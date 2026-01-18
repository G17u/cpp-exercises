#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, p;
	cin >> s >> p;

	int res = 0;

	int i = 0;
	int a = s.find(p, i);

	while (a!=string::npos) {
		res++;
		i = a + 1;
		a = s.find(p, i);
	}

	cout << res << endl;

	return 0;
}
