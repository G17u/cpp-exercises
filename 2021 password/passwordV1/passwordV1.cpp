#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

bool perm(int alfP[256], int alfH[256]) {

    for (int i = 0; i < 256; i++) {
        if (alfP[i] != alfH[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    vector<string> P(t);
    vector<string> H(t);

    bool isperm;

    for (int i = 0; i < t; i++) {
        cin >> P[i];
        cin >> H[i];

    }

    for (int i = 0; i < t; i++) {

        deque<char> tmp;
        int alfP[256] = { 0 };
        int alfH[256] = { 0 };
        
        for (int j = 0; j < P[i].size(); j++) {
            tmp.push_back(H[i][j]);
            alfP[P[i][j]]++;
            alfH[H[i][j]]++;
        }


        isperm = perm(alfP, alfH);
        if (isperm) {
            cout << "1" << endl;
            continue;
        }

        for (int j = 1; j <= H[i].size() - P[i].size(); j++) {
            
            alfH[tmp.front()]--;
            tmp.pop_front();
            tmp.push_back(H[i][j + P[i].size() - 1]);
            alfH[tmp.back()]++;

            isperm = perm(alfP, alfH);
            if (isperm) break;
        }
        if (isperm) {
            cout << "1" << endl;
        }
        else {
            cout << "0" << endl;
        }
    }


    return 0;
}
