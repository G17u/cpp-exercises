#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define ll long long



// funzione per avere k insiemi
ll solvek() {
	int n, d, K;
	cin >> n >> d >> K;

	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end());

	vector<vector<ll>> maxlen(n,vector<ll>(K, 0));
	vector<ll> len(n, 0);
	ll res = 0;
	int left = 0;

	for (int right = 0; right < n; right++) {
		
		while (s[right] - s[left] > d) left++;

		for (int k = 0; k < K; k++) {

			len[right] = right - left + 1;

			if (k == 0) {
				maxlen[right][k] = max(maxlen[right - 1 < 0 ? 0 : right - 1][k], len[right]);
			}
			else {
				maxlen[right][k] = max(maxlen[right - 1 < 0 ? 0 : right - 1][k], len[right] + (left - 1 < 0 ? 0 : maxlen[left - 1][k - 1]));
			}
		}
	}
	return maxlen[n - 1][K - 1];
}

// funzione per avere 2 insiemi
ll solve2() {

	int n, d;
	cin >> n >> d;

	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end());

	vector<ll> maxlen(n, 0);
	vector<ll> len(n, 0);
	ll res = 0;
	int left = 0;

	for (int right = 0; right < n; right++) {

		while (s[right] - s[left] > d) left++;

		len[right] = right - left + 1;

		maxlen[right] = max(maxlen[right - 1 < 0 ? 0 : right - 1], len[right]);
		
		res = max(res, len[right] + (left - 1 < 0 ? 0 : maxlen[left - 1]));

	}


	return res;
}


int main()
{
	int t;
	cin >> t;

	vector<ll> res(t);

	for (int i = 0; i < t; i++) {
		res[i] = solve2();
	}
	for (int i = 0; i < t; i++) {
		cout << res[i] << endl;
	}
	return 0;
}