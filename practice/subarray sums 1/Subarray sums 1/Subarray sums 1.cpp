#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{

	int n, x;
	cin >> n >> x;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	ll sum = 0;
	int count = 0;

	while (right != n) {

		sum += arr[right];

		while (sum > x) 
		{
			sum -= arr[left];
			left++;
		}

		if (sum == x) {
			count++;
		}
		right++;
	}

	cout << count << endl;

	return 0;
}
