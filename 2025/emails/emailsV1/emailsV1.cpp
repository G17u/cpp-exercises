#include <iostream>
#include <vector>
#include <numeric>
#include <map>


using namespace std;

#define ll long long

typedef struct server {
    int mod;
    int pt;
};


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nums, nume;
    cin >> nums >> nume;

    vector<server> s(nums);
    

    map<int, int> f;

    int mcm = 1;

    for (int i = 0; i < nums; i++) {
        cin >> s[i].mod;
        f[s[i].mod] = 1;
        
    }
    for (int i = 0; i < nums; i++) {
        cin >> s[i].pt;
    }
    

    for (auto i : f) {
        mcm = lcm(mcm, i.first);
    }

    vector<ll> mapc(mcm, 0);
   

    for (int rit = 0; rit < mcm; rit++) {
        ll tp = rit;
        int mod;
        for (int ser = 0; ser < nums; ser++) {
            
            mod = tp % s[ser].mod;
            
            if (mod != 0) {
                tp = s[ser].mod - mod + tp;
            }
            
            tp += s[ser].pt;
        }
        mapc[rit] = tp;
    }

    ll res = 0;

    int e;

    for (int i = 0; i < nume; i++) {
        cin >> e;
        int mod = e % mcm;
        res += mapc[mod] + e - mod;
    }

    cout << res;

    return 0;
}