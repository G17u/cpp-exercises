#include <iostream>
#include <vector>
#include <string>



using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> freq(26, 0);
	vector<char> res(n);
	int len;
	char tmp;
	for (int i = 0; i < n; i++) {
		cin >> len;
		for (int j = 0; j < len; j++) {
			cin >> tmp;
			freq[tmp - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			if (freq[j] == 0) {
				res[i] = j + 'a';
			}
			freq[j] = 0;
		}
	}

	for (char c : res) {
		cout << c << endl;
	}


	return 0;
}
