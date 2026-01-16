#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#define ll long long
using namespace std;



ll solve() {

    int n, m;
    cin >> n >> m;
    string alf, t;
    cin >> alf >> t;

    string cover = "";

    ll ans = 1;

    for (int i = 0; i < m - 1; i++) {
        cover += t[i];
        bool same = true;
        bool valid = true;

        int oldr = cover.size() - 1;

        for (int j = 0; j < cover.size(); j++) {
            if (cover[j] != t[m - cover.size() + j]) {
                same = false;
                break;
            }
        }
        if (!same)continue;

        for (int right = cover.size(); right < m; right++) {

            if (cover == t.substr(right - cover.size() + 1, cover.size())) {
                oldr = right;
            }

            if (oldr == right - cover.size()) {
                valid = false;
                break;
            }

        }
        if (valid && oldr == m - 1)ans++;

    }

    return ans;
}

int main()
{
    
    int t;
    cin >> t;

    vector<ll> ans(t);

    for (int i = 0; i < t; i++) {
        ans[i] = solve();
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
