#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    int t;
    cin >> t;
    int alf[26] = {0};
    vector<string> s(t);
    int tmp;
    for (int i = 0; i < t; i++) {
        cin >> tmp;
        cin >> s[i];
    }

    for (int i = 0; i < t; i++) {
        for (char c : s[i]) {
            alf[c - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (alf[j] == 0) {
                char c = 'a' + j;
                cout << c << endl;
            }
            alf[j] = 0;
        }
    }

    return 0;
}
