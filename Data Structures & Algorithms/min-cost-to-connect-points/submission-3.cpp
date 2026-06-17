class Solution {
private:
	int distance(vector<int>& p1, vector<int>& p2) {
		return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
	}
	
	int findRoot(vector<int>& parent, int node) {
		if (node == parent[node]) return node;
		return parent[node] = findRoot(parent, parent[node]);
	}
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size();
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				edges.push_back({ distance(points[i], points[j]), {i, j} });
			}
		}
		sort(edges.begin(), edges.end());
		
		vector<int> parent(n);
		for (int i = 0; i < n; i++) parent[i] = i;
		int minCost = 0;
		int cnt = 0;

		for (auto& edge : edges) {
			int rootA = findRoot(parent, edge.second.first);
			int rootB = findRoot(parent, edge.second.second);
			int cost = edge.first;

			if (rootA != rootB) {
				parent[rootA] = rootB;
				minCost += cost;
				cnt++;
			}
			if (cnt == n - 1) break;
		}
		return minCost;
	}
};
