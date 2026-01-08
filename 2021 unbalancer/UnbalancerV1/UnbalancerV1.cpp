#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.rbegin(), v.rend());

	if (n == 1) {
		cout << "0" << endl;
		return 0;
	}

	for (int i = 0; i < k; i++) {
		v[0] += v[i + 1];
		v[i + 1] = 0;
	}
	
	cout << v[0] << endl;

	return 0;
}
