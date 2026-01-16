#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<int> stack;

	for (int i = 0; i < n; i++) {


		if (isdigit(arr[i][0])) {
			stack.push_back(stoi(arr[i]));
		}
		else {
			int a, b;
			a = stack.back();
			stack.pop_back();
			b = stack.back();
			stack.pop_back();
			if (arr[i][0] == '+') {
				stack.push_back(a + b);
			}
			else if (arr[i][0] == '-') {
				stack.push_back(b - a);
			}
			else if (arr[i][0] == '*') {
				stack.push_back(a * b);
			}
		}
	}

	cout << stack[0] << endl;


	return 0;
}
