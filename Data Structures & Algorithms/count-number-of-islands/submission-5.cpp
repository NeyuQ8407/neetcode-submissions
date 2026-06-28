class Solution {
private:
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	void dfs(vector<vector<char>>& grid, int i, int j) {
		int n = grid.size();
		int m = grid[0].size();

		if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == '0') return;
		grid[i][j] = '0';

		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			dfs(grid, i1, j1);
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1') {
					cnt++;
					dfs(grid, i, j);
				}
			}
		}
		return cnt;
	}
};
