class Solution {
private:
	int findRoot(vector<int>& parent, int node) {
		if (node == parent[node]) return node;
		return parent[node] = findRoot(parent, parent[node]);
	}
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1);
		for (int i = 1; i <= n; i++) parent[i] = i;

		for (auto& edge : edges) {
			int rootA = findRoot(parent, edge[0]);
			int rootB = findRoot(parent, edge[1]);

			if (rootA == rootB) return edge;
			parent[rootA] = rootB;
		}
		return {};
	}
};
