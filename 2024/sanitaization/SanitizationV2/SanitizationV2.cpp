#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> banned(m);
    vector<string> s(n);

    for (int i = 0; i < m; i++) {
        cin >> banned[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        bool trovata = false;

        for (int j = 0; j < m; j++) {

            if (s[i].find(banned[j]) != string::npos) {
                trovata = true;
                break;
            }

        }
        if (trovata) {
            cout << "BANNED" << endl;
        }
        else {
            cout << "SAFE" << endl;
        }
    }

    return 0;
}
