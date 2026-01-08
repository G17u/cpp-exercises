#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    int n, q;
    cin >> q >> n;

    string ans;
    vector<string> s(n);

    cin >> ans;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            if (ans[j] == s[i][j]) val++;
        }
        cout << val << endl;
        val = 0;
    }

    return 0;
}
