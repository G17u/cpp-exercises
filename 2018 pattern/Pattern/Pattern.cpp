#include <iostream>
#include <vector>

#define ll long long
#define MAXK 20

using namespace std;

vector<vector<int>> vicini = {
    {},
    {2,4,5},
    {1,3,4,5,6},
    {2,5,6},
    {1,2,5,7,8},
    {1,2,3,4,6,7,8,9},
    {2,3,5,8,9},
    {4,5,8},
    {4,5,6,7,9},
    {5,6,8}
};

vector<vector<bool>> GiaTrovate(MAXK + 1, vector<bool>(10, false));
vector<vector<int>> StradeTrovate(MAXK + 1, vector<int>(10));

ll trovastrade(int K, int elemento) {

    ll strade = 0;

    if (K == 1) {
        strade = vicini[elemento].size();
        return strade;
    }

    if (GiaTrovate[K][elemento]) {
        strade = StradeTrovate[K][elemento];
        return strade;
    }

    for (auto vicino : vicini[elemento]) {
        strade += trovastrade(K - 1, vicino);
    }

    GiaTrovate[K][elemento] = true;
    StradeTrovate[K][elemento] = strade;

    return strade;
}




int main()
{

    int K;
    cin >> K;

    ll strade = 0;

    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= 9; i++) {
            strade += trovastrade(k, i);
        }
    }

    cout << strade;

    return 0;
}