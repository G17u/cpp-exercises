#include <iostream>
#include <vector>
#include <deque>
#include <utility>


#define INF 1000000

using namespace std;

int main()
{
    
    int n;
    cin >> n;

    int vicini[8][2] = {
        {-2,+1},
        {-2,-1},
        {+2,+1},
        {+2,-1},
        {+1,-2},
        {-1,-2},
        {+1,+2},
        {-1,+2}
    };

    deque<pair<int, int>> coda;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    board[0][0] = true;
    vector<vector<int>> res(n, vector<int>(n, 0));


    coda.push_back({ 0,0 });

    while (!coda.empty()) {

        int x = coda[0].first;
        int y = coda[0].second;
        coda.pop_front();

        for (auto vicino : vicini) {
            int dx = x + vicino[0];
            int dy = y + vicino[1];

            if (dx < n && dx >= 0 && dy < n && dy >= 0) {
                
                if (board[dx][dy])continue;
                board[dx][dy] = true;
                coda.push_back({ dx,dy });
                res[dx][dy] = res[x][y] + 1;
            }

        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}