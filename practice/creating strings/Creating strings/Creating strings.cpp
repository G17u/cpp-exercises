#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

vector<int> freq(26);
vector<string> res;

void sub(string a, int max) {

	if (a.size() == max) {
		res.push_back(a);
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (freq[i] > 0) {
			a += i + 'a';
			freq[i]--;
			sub(a, max);
			freq[i]++;
			a.pop_back();
		}
	}
	return;
}


int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		freq[s[i] - 'a']++;
	}
	

	string a;
	sub(a, s.size());

	cout << res.size() << endl;
	for (string s : res) cout << s << endl;

	return 0;
}

