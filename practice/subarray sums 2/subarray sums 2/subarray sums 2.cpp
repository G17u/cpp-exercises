#include <iostream>
#include <vector>
#include <map>


#define ll long long

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)cin >> arr[i];

    map<ll, int> freq;
    freq[0] = 1;

    ll sum = 0;
    ll res = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (freq.count(sum - x)) {
            res += freq[sum - x];
        }
        freq[sum]++;
    }

    cout << res << endl;


    return 0;
}
