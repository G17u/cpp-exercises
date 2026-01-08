#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> rotate(vector<vector<char>> matrix, int n) {

    vector<vector<char>> v(n, vector<char>(n));
    vector<char> tmp(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][n - j - 1] = matrix[j][i];
        }
    }

    return v;
}

int main()
{
    
    int n, m;
    cin >> n >> m;

    bool error = false;
    bool found = false;

    vector<vector<char>> card(n, vector<char>(n));
    vector<vector<char>> pad(m, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> card[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pad[i][j];
        }
    }

    int rigapad=0, k=0;
    
    for (int rotations = 0; rotations < 4; rotations++) {
        rigapad = 0;
        k = 0;
        while (!found) {

            for (; rigapad <= m - n; rigapad++) {
                error = false;
                for (; k <= m - n; k++) {
                    error = false;
                    for (int j = 0; j < n; j++) {
                        if (card[0][j] != pad[rigapad][j + k])
                        {
                            error = true;
                            break;
                        }
                    }
                    if (!error)break;

                }
                if (!error)break;
            }

            if (!error) {
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (card[i][j] != pad[rigapad + i][k + j]) {
                            error = true;
                            break;
                        }
                    }
                    if (error) break;
                }
                if (!error)found = true;
            }
            else {
                break;
            }
            if (error && (rigapad == m - n) && (k == m - n)) break;
            if (error) {
                rigapad++;
                k++;
                continue;
            } 
        }

        if (found) {
            cout << rigapad << " " << k << " " << rotations * 90 << endl;
            break;
        }
        card = rotate(card, n);
    }
    if (!found) cout << "err" << endl;;
    return 0;
}