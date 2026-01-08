#include <iostream>
#include <string>
#include <vector>



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

	int same = 0;

	for (int i = 0; i < n; i++) {
			
		vector<bool> equal(m, false);
		for (int a = 0; a < m; a++) {
			
			int k = 0;
			bool valid = false;
			string ban = banned[a];

			for (int j = 0; j < s[i].size(); j++) {

				if (k == ban.size() - 1) {
					if (s[i][j] == ban[k]) {
						equal[a] = true;
						break;
					}
				}
				else if (s[i][j] == ban[k]) {
					valid = true;
					k++;
				}
				else {
					if (valid) {
						valid = false;
						j--;
					}
					k = 0;
				}
			}

		}
		for (int b = 0; b < m;b++) {
			if (equal[b]) 
			{
				cout << "BANNED" << endl;
				break;
			}
			if (!equal[b] && b == m - 1) {
				cout << "SAFE" << endl;
			}
			
		}

	}


	return 0;
}

