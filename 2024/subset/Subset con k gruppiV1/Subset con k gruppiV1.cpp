#include <iostream>
#include <vector>
#include <algorithm>


#define ll long long

using namespace std;


int solve() {

	int n, K, d;

	cin >> n >> d >> K;
	vector<ll> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end());

	vector<vector<int>> dp(K + 1, vector<int>(n, 0));
	vector<int> len(n, 0);
	vector<int> start(n, 0);
	int ans = 0;

	int right = 0;
	int left = 0;

	for (right = 0; right < n; right++) {
		while (s[right] - s[left] > d)left++;

		len[right] = right - left + 1;
		start[right] = left;

	}

	for (int k = 1; k <= K; k++) {
		for (int i = 0; i < n; i++) {

			int opa = i - 1 < 0 ? 0 : dp[k][i - 1];
			
			int opb = start[i] - 1 < 0 ? 0 : dp[k - 1][start[i] - 1] + len[i];
			
			dp[k][i] = max(opa, opb);

		}
	}
	return dp[K][n - 1];

}


int main()
{

	int t;
	cin >> t;
	vector<int> ans(t);
	for (int i = 0; i < t; i++) {
		ans[i] = solve();
	}
	for (int i = 0; i < t; i++) {

		cout << ans[i] << endl;

	}

	return 0;
}