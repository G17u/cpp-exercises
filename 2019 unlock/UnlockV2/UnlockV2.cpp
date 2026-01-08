#include <iostream>
#include <vector>


using namespace std;


vector<vector<char>> rotate(vector<vector<char>> matrix, int n) {
	vector<vector<char>> v(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] = matrix[n - j - 1][i];
		}
	}
	return v;
}


int main()
{
   
	int n, m;
	cin >> n >> m;

	vector<vector<char>> Card(n, vector<char>(n));
	vector<vector<char>> Pad(m, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Card[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Pad[i][j];
		}
	}


	bool found = true;

	for (int rot = 0; rot < 4; rot++) {

		for (int rigapad = 0; rigapad <= m - n; rigapad++) {
			for (int colonnapad = 0; colonnapad <= m - n; colonnapad++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (Card[i][j] != Pad[rigapad + i][colonnapad + j]) {
							found = false;
							break;
						}
					}
					if (!found) {
						break;
					}
				}
				if (found) {
					cout << rigapad << " " << colonnapad << " " << rot * 90;
					return 0;
				}
				found = true;
			}
		}

		Card = rotate(Card, n);
	}

	cout << "err";

	return 0;
}
