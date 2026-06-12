class Solution {
private:
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	void dfs(vector<vector<char>>& board, int i, int j) {
		int n = board.size();
		int m = board[0].size();

		board[i][j] = '#';

		for (int k = 0; k < 4; k++) {
			int i1 = i + dx[k];
			int j1 = j + dy[k];

			if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && board[i1][j1] == 'O')
				dfs(board, i1, j1);
		}
	}
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;

		int n = board.size();
		int m = board[0].size();

		for (int i = 0; i < n; i++) {
			if (board[i][0] == 'O') dfs(board, i, 0);
			if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
		}
		for (int j = 0; j < m; j++) {
			if (board[0][j] == 'O') dfs(board, 0, j);
			if (board[n - 1][j] == 'O') dfs(board, n - 1, j);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '#') board[i][j] = 'O';
			}
		}
	}
};