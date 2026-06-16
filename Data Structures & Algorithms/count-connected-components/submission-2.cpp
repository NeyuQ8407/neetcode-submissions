class Solution {
private:
	void dfs(vector<vector<int>>& adj, int u, vector<bool>& check) {
		check[u] = true;
		for (auto& v : adj[u]) {
			if (!check[v]) {
				dfs(adj, v, check);
			}
		}
	}
public:
	int countComponents(int n, vector<vector<int>>& edges) {
		vector<vector<int>> adj(n);
		for (auto& edge : edges) {
			int u = edge[0];
			int v = edge[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<bool> check(n, false);

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				cnt++;
				dfs(adj, i, check);
			}
		}
		return cnt;
	}
};