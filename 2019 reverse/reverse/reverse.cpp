#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;



int main()
{
    
    int n;
    cin >> n;

    vector<char> text(n);
    vector<char> newtext(n);
    vector<pair<int, char>> freq;
    
    vector<bool> Ispresent(256, false);
    int num = 0;
    

    for (int i = 0; i < n; i++) {
        cin >> text[i];
    }

    
    for (char c : text) {
        if (Ispresent[c]) {
            int i = 0;
            for (pair<int, char> car : freq) {
                if (car.second == c) {
                    freq[i].first++;
                    break;
                }
                i++;
            }
        }
        else {
            Ispresent[c] = true;
            num++;
            freq.push_back({ 1,c });
        }
    }

    sort(freq.begin(), freq.end());
    vector<pair<char, char>> freq2(num);
    
    int lastlim = 0;
    char tmp;
    int lim = 1;

    for (lim = 1; lim < num; lim++) {
        if ((freq[lim].first == freq[lim - 1].first)) continue;

        for (int i = lastlim; i < lim; i++) {
            freq2[i].first = freq[i].second;
            freq2[i].second = freq[lim - i + lastlim - 1].second;
        }
        lastlim = lim;
    }

    for (int i = lastlim; i < lim; i++) {
        freq2[i].first = freq[i].second;
        freq2[i].second = freq[lim - i + lastlim - 1].second;
    }

    int c;
    for (int i = 0; i < n;i++) {
        c = text[i];
        for (int j = 0; j < num; j++) {
            if (c == freq2[j].first) {
                newtext[i] = freq2[j].second;
                break;
            }
        }
    }

    for (char c : newtext) {
        cout << c;
    }

    return 0;
}
