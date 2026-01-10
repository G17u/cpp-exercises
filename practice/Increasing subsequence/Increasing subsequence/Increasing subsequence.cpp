#include <iostream>
#include <vector>
#include <algorithm>


#define ll long long

using namespace std;

int main()
{
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)cin >> arr[i];

    vector<int> len(1, 0);

    for (int i = 0; i < n; i++) {

        if (arr[i] > len.back()) {
            len.push_back(arr[i]);
        }
        else {
            int index = lower_bound(len.begin(), len.end(), arr[i]) - len.begin();
            len[index] = arr[i];
        }

    }

    cout << len.size() - 1 << endl;


    return 0;
}