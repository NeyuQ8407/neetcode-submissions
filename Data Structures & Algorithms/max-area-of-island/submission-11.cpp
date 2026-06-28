class Solution {
private:
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int dfs(vector<vector<int>>& grid, int i, int j) {
		int n = grid.size();
		int m = grid[0].size();

		if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;

		grid[i][j] = 0;
		int area = 1;
		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			area += dfs(grid, i1, j1);
		}

		return area;
	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int n = grid.size();
		int m = grid[0].size();

		int maxArea = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					int area = dfs(grid, i, j);
					maxArea = max(maxArea, area);
				}
			}
		}
		return maxArea;
	}
};
