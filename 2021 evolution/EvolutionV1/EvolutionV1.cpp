#include <iostream>
#include <vector>


using namespace std;


int main()
{

	int n, m, K;

	cin >> n >> m >> K;
	vector<vector<char>> grid(n, vector<char>(m, '.'));
	vector<vector<char>> grid2(n, vector<char>(m, '.'));

	int vicini[8][2] =
	{
		{1,1},
		{1,0},
		{1,-1},
		{0,1},
		{0,-1},
		{-1,1},
		{-1,0},
		{-1,-1}
	};

	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int k = 0; k < K; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int piene = 0;
				int vicinox;
				int vicinoy;
				for (int riga = 0; riga < 8; riga++) {

					vicinox = vicini[riga][0] + j;
					vicinoy = vicini[riga][1] + i;

					if (vicinox<0 || vicinox>=m || vicinoy<0 || vicinoy>=n) {
						continue;
					}
					if (grid[vicinoy][vicinox] != '.') {
						piene++;
					}
				}

				if (grid[i][j] == '.') {
					if (piene > 4) grid2[i][j] = '+';
					else grid2[i][j] = grid[i][j];
				}
				else if (grid[i][j] == '+') {
					if (piene > 4) grid2[i][j] = '*';
					else if (piene < 4) grid2[i][j] = '.';
					else grid2[i][j] = grid[i][j];
				}
				else if (grid[i][j] == '*') {
					if (piene > 4) grid2[i][j] = '+';
					else if (piene < 4) grid2[i][j] = '.';
					else grid2[i][j] = grid[i][j];
				}

			}
		}

		grid = grid2;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}


	return 0;

}

