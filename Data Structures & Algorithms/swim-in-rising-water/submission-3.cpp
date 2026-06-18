class Solution {
public:
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> timeTo(n, vector<int>(n, INT_MAX));
		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({ grid[0][0], {0, 0} });
		
		int dx[4] = { 1, -1, 0, 0 };
		int dy[4] = { 0, 0, 1, -1 };

		while (!pq.empty()) {
			int currTime = pq.top().first;
			int i = pq.top().second.first;
			int j = pq.top().second.second;
			pq.pop();

			if (i == n - 1 && j == n - 1) return currTime;

			if (currTime > timeTo[i][j]) continue;

			for (int k = 0; k < 4; k++) {
				int i1 = i + dx[k];
				int j1 = j + dy[k];

				if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
					int newTime = max(currTime, grid[i1][j1]);

					if (newTime < timeTo[i1][j1]) {
						timeTo[i1][j1] = newTime;
						pq.push({ newTime, {i1, j1} });
					}
				}
				
			}
		}
		return 0;
	}
};