#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<ll, int>m;
    ll curr = 0;

    m[0] = 1;
    
    ll res = 0;

    for (int i = 0; i < n; i++) {
        curr += arr[i];

        if (m.count(curr - sum)) {
            res += m[curr - sum];
        }
        m[curr]++;
    }

    cout << res << endl;


    return 0;
}
