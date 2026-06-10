class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		if (grid.empty()) return -1;

		int n = grid.size();
		int m = grid[0].size();

		int freshFruit = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) q.push({ i, j });
				else if (grid[i][j] == 1) freshFruit++;
			}
		}

		if (freshFruit == 0) return 0;

		int dx[4] = { 1, -1, 0, 0 };
		int dy[4] = { 0, 0, 1, -1 };
		int time = 0;
		while (!q.empty() && freshFruit > 0) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nr = r + dx[k];
					int nc = c + dy[k];
					
					if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
						grid[nr][nc] = 2;
						freshFruit--;
						q.push({ nr, nc });
					}
				}
			}
			time++;
		}
		if (freshFruit == 0) return time;
		else return -1;
	}
};