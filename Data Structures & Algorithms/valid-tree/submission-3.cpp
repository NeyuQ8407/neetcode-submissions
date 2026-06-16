class Solution {
private:
	int findRoot(vector<int>& parent, int node) {
		if (node == parent[node]) return node;
		return parent[node] = findRoot(parent, parent[node]);
	}
public:
	bool validTree(int n, vector<vector<int>>& edges) {
		if (edges.size() != n - 1) return false;
		vector<int> parent(n);
		for (int i = 0; i < n; i++) parent[i] = i;

		for (auto& edge : edges) {
			int rootA = findRoot(parent, edge[0]);
			int rootB = findRoot(parent, edge[1]);

			if (rootA != rootB) parent[rootA] = rootB;
			else return false;
		}
		return true;
	}
};