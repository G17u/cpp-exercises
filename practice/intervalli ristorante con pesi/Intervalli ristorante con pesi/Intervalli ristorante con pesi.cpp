#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define ll long long

using namespace std;

struct films {
	int inizio;
	int fine;
	ll valore;
};

ll solve() {
	int n;
	cin >> n;

	vector<films> film(n);

	for (int i = 0; i < n; i++) {
		cin >> film[i].inizio;
		cin >> film[i].fine;
		cin >> film[i].valore;
	}

	sort(film.begin(), film.end(), [](films a, films b) {

		if (a.fine != b.fine) return a.fine < b.fine;
		return a.inizio < b.inizio;
		});

	vector<ll> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		ll opa = dp[i - 1];

		int high = i - 2;
		int low = 0;
		int mid;
		int p = -1;
		while (low <= high) {

			mid = low + (high - low) / 2;

			if (film[mid].fine <= film[i - 1].inizio) {
				low = mid + 1;
				p = mid;
			}
			else {
				high = mid - 1;
			}

		}

		ll opb = film[i - 1].valore + dp[p + 1];

		dp[i] = max(opa, opb);
	}

	return dp[n];
}

int main()
{

	int t;
	cin >> t;

	vector<ll> ans(t);
	for (int i = 0; i < t; i++) {
		ans[i] = solve();
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}