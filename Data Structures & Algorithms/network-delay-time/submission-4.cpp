class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int>>> adj(n + 1);
		for (auto& x : times) {
			int u = x[0];
			int v = x[1];
			int w = x[2];
			adj[u].push_back({ v, w });
		}

		typedef pair<int, int> edgeData;
		priority_queue<edgeData, vector<edgeData>, greater<edgeData>> pq;
		vector<int> d(n + 1, INT_MAX);
		d[k] = 0;
		pq.push({ 0, k });

		while (!pq.empty()) {
			int u = pq.top().second;
			int w = pq.top().first;
			pq.pop();

			if (w > d[u]) continue;

			for (auto& neighbor : adj[u]) {
				int v = neighbor.first;
				int cost = neighbor.second;
				int newCost = w + cost;

				if (newCost < d[v]) {
					pq.push({newCost, v});
					d[v] = newCost;
				}
			}
		}
		int maxTime = d[1];
		for (int i = 1; i <= n; i++) {
			if (d[i] == INT_MAX) return -1;
			maxTime = max(maxTime, d[i]);
		}
		return maxTime;
	}
};
