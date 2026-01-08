#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n;
    char tmp;
    cin >> n;
    cin.get(tmp);

    vector<pair<int, char>> freq;
    vector<int> c(256, 0);
    vector<char> sub(256);
    vector<char> t(n);

    for (int i = 0; i < n; i++) {
        cin.get(t[i]);
        c[t[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (c[i] > 0) {
            freq.push_back({ c[i],i });
        }
    }

    sort(freq.begin(), freq.end());
    
    int last = 0;
    for (int i = 1; i < freq.size(); i++) {
        if (freq[i].first == freq[i - 1].first) continue;
        for (int j = last; j < i; j++) {
            sub[freq[j].second] = freq[i - j - 1 + last].second;
        }
        last = i;
    }
    for (int j = last; j < freq.size(); j++) {
        sub[freq[j].second] = freq[freq.size() - j - 1 + last].second;
    }

    for (char c : t) {
        cout << sub[c];
    }

    return 0;
}
