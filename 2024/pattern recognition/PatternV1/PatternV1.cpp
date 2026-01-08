#include <iostream>
#include <vector>
#include <string>



using namespace std;


int solve() {

    int n, m;
    cin >> n >> m;

    vector<char> alf(n);
    string stringa;
    vector<char> cover;
    for (int i = 0; i < n; i++) cin >> alf[i];

    cin >> stringa;

    cover.push_back(stringa[0]);

    int ans = 1;


    while (cover.size() != stringa.size()) {
        int len = cover.size();
        int right = len - 1;
        int left = -1;
        int oldright = right - 1;
        bool valid = true;
        bool correct = true;

        while (right < stringa.size()) {

            for (int i = 0; i < len; i++) {
                if (cover[i] != stringa[left + 1 + i]) {
                    valid = false;
                    break;
                }
            }
            if (!valid && left==oldright) {
                correct = false;
                break;
            }
            else if (valid) {
                oldright = right;
            }

            valid = true;
            right++;
            left++;
        }

        if (oldright != stringa.size() - 1) correct = false;

        if (correct) ans++;
        cover.push_back(stringa[len]);
    }
    
    return ans;

}


int main()
{
    
    int t;
    cin >> t;

    vector<int> ans(t);

    for (int i = 0; i < t; i++) {
        ans[i]=solve();
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}