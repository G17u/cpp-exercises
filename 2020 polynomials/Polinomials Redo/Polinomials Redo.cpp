#include <iostream>
#include <vector>


#define INF 1000000


using namespace std;

int main()
{
	
	int grado, k, n;

	cin >> grado >> k;
	n = grado + 1;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	vector<int> sotto(n);
	vector<int> sopra(n);
	sotto[0] = 0;
	int tmpsopra = 0;
	int tmpsotto = 0;
	int resto;
	int ans = 0;

	for (int i = grado; i >= 0; i--) {

		tmpsopra = tmpsopra * 2 + v[i];

		if (abs(tmpsopra)> INF) {
			while (i >= 0) {
				sopra[i] = INF;
				i--;
			}
			break;
		}
		else {
			sopra[i] = tmpsopra;
		}
	}

	for (int i = 1; i <= grado; i++) {
		resto = (tmpsotto + v[i - 1]) % 2;
		if (resto != 0) {
			while (i <= grado) {
				sotto[i] = INF;
				i++;
			}
			break;
		}
		else {
			tmpsotto = (tmpsotto + v[i - 1]) / 2;
			sotto[i] = tmpsotto;
		}

	}

	int newa;

	for (int i = 0; i <= grado; i++) {

		if (sopra[i] == INF) continue;
		if (sotto[i] == INF) break;

		newa = v[i] - sopra[i] - sotto[i];
		if (abs(newa) <= k) ans++;
		if ((i == grado) && (newa == 0))ans--;
	}
	cout << ans << endl;

	return 0;
}
