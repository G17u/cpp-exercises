#include <iostream>
#include <vector>
#include <string>
#include <math.h>


using namespace std;

int main()
{
	string s, t;

	cin >> s >> t;

	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));

	for (int i = 0; i <= s.size(); i++) dp[i][0] = i;
	for (int i = 0; i <= t.size(); i++) dp[0][i] = i;

	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= t.size(); j++) {

			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {

				int opa = dp[i - 1][j - 1] + 1;
				int opb = dp[i - 1][j] + 1;
				int opc = dp[i][j - 1] + 1;
				dp[i][j] = min(opa, min(opb, opc));

			}

		}
	}

	cout << dp[s.size()][t.size()];

	return 0;
}
