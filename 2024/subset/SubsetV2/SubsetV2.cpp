#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int solve() {
	int n, d;
	cin >> n >> d;
	vector<ll> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end());

	int ans = 0;

	int left = 0;
	int right = 0;
	vector<int> len(n, 0);
	vector<int> max_prev(n, 0);

	for (right = 0; right < n; right++) {

		while (s[right] - s[left] > d)left++;

		len[right] = right - left + 1;

		max_prev[right] = max(right - 1 < 0 ? 0 : max_prev[right - 1], len[right]);

		int start = left;
		int fina = start - 1 < 0 ? 0 : max_prev[start - 1];

		ans = max(ans, fina + len[right]);

	}

	return ans;
}

int main()
{
   
	int t;
	cin >> t;
	vector<int> ans(t);
	for (int i = 0; i < t; i++) {
		ans[i]=solve();
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}
