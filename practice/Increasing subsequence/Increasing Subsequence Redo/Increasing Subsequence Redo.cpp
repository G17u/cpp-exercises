#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    vector<int> len(1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > len.back()) {
            len.push_back(arr[i]);
        }
        else {
            len[lower_bound(len.begin(), len.end(), arr[i]) - len.begin()] = arr[i];
        }
    }

    cout << len.size() - 1 << endl;


    return 0;
}

