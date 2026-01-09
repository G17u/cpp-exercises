#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define ll long long

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<ll, int>> cust(2*n);

	for (int i = 0; i < 2*n; i++) {
		cin >> cust[i].first; 
		
		if (i % 2 == 0) {
			cust[i].second = 0;// beginning
		}
		else {
			cust[i].second = 1;// end
		}
		
	}

	sort(cust.begin(), cust.end());

	int maxcount = 0;
	int count = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (cust[i].second == 0) {
			count++;
		}
		else {
			count--;
		}
		maxcount = max(maxcount, count);
	}
	cout << maxcount << endl;

	return 0;
}
