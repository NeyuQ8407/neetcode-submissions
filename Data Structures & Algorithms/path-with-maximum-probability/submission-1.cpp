class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        typedef pair<double, int > data;
        vector<vector<data>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({ succProb[i], edges[i][1] });
            adj[edges[i][1]].push_back({ succProb[i], edges[i][0] });
        }

        vector<double> dist(n, -1);
        dist[start_node] = 1;
        priority_queue<data> pq;
        pq.push({ dist[start_node], start_node });

        while (!pq.empty()) {
            int u = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            if (currProb < dist[u]) continue;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.second;
                double prob = neighbor.first;

                double newProb = prob * currProb;
                if (newProb > dist[v]) {
                    dist[v] = newProb;
                    pq.push({ newProb, v });
                }
            }
        }
        if (dist[end_node] == -1) return 0;
        return dist[end_node];
    }
};