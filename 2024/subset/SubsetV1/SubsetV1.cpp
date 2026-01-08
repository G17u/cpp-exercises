#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <deque>

#define ll long long

using namespace std;

int main()
{
    int T;
    cin >> T;

    vector<vector<ll>> S(T);
    vector<int> N(T);
    vector<int> D(T);

    for (int t = 0; t < T; t++) {
        cin >> N[t];
        cin >> D[t];
        ll tmp;
        for (int i = 0; i < N[t]; i++) {
            cin >> tmp;
            S[t].push_back(tmp);
        }
    }

    for (int t = 0; t < T; t++) {

        int ans = 0;
        vector<ll> s = S[t];
        vector<int> len(s.size(), 0);
        vector<int> max_prev(s.size(), 0);
        int n = N[t]; int d = D[t];

        sort(s.begin(), s.end());

        int left = 0; 
        int right = 0;

        while (right != s.size()) {

            while (s[right] - s[left] > d) {
                left++;
            }

            len[right] = right - left + 1;

            max_prev[right] = max(right - 1 < 0 ? 0 : max_prev[right - 1], len[right]);

            int start = left;
            int fina = start - 1 < 0 ? 0 : max_prev[start - 1];

            ans = max(ans, fina + len[right]);
            right++;
        }
        cout << ans << endl;
    }

    return 0;
}