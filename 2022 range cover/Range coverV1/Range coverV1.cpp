#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<ll, char>> R(2*n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> R[i].first;
        if (i % 2 == 0) {
            R[i].second = 'b';
        }
        else {
            R[i].first++;
            R[i].second = 'e';
        }
    }

    sort(R.begin(), R.end());

    int val = 0;
    ll ans = 0;

    for (int i = 0; i < 2 * n; i++) {
        
        if (R[i].second == 'b') {
            val++;
        }
        else {
            val--;
        }

        if (val == k) {
            if (i < 2 * n - 1) {
                ans += R[i + 1].first - R[i].first;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
