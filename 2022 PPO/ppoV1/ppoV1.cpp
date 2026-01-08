#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool Isspecial(char c) {
	if ((c <= 'z' && c >= 'a') || (c >= 'A' && c <= 'Z') || (c <= '9' && c >= '0')) {
		return false;
	}
	return true;
}


int main()
{
	int n;
	cin >> n;

	vector<vector<string>> pass(n, vector<string>(2));

	for (int i = 0; i < n; i++) {
		cin >> pass[i][0];
		cin >> pass[i][1];
	}

	
	for (int i = 0; i < n; i++) {
		string newpass = pass[i][0];
		string oldpass = pass[i][1];
		
		if (newpass.size() < 8) { // error 1
			cout << "0" << endl;
			continue;
		}
		else if (newpass.size() > 16) { // error 2
			cout << "0" << endl;
			continue;
		}
		
		int u = 0;
		int l = 0;
		for (char c : newpass) {
			if (islower(c)) l++;
			if (isupper(c)) u++;
			if (l != 0 && u != 0) break;
		}
		if (l == 0 || u == 0) { // error 3
			cout << "0" << endl;
			continue;
		}

		int d = 0;
		int s = 0;
		for (char c : newpass) {
			if (Isspecial(c)) s++;
			if (isdigit(c)) d++;
			if (s != 0 && d != 0) break;
		}
		if (s == 0 || d == 0) { // error 4
			cout << "0" << endl;
			continue;
		}
		char oldc = newpass[0];
		int first = 0;
		bool valid = true;
		for (char c : newpass) {
			if ((c == oldc) && (first != 0)) {
				valid = false;
				break;
			}
			first = 1;
			oldc = c;
		}
		if (!valid) {
			cout << "0" << endl; // error 5
			continue;
		}
		// error 6
		bool valid6 = false;
		if (newpass.size() == oldpass.size() + 1) {
			int j = 0;
			int diversi = 0;
			for (int i = 0; i < oldpass.size(); i++) {
				if (newpass[j] == oldpass[i]) {
					j++;
					continue;
				}

				if (newpass[j] != oldpass[i]) {
					i--;
					diversi++;
				}
				j++;
				if (diversi > 1) {
					valid6 = true;
					break;
				}
			}
			if (!valid6) {
				cout << "0" << endl;
				continue;
			}

		}
		else if (newpass.size() == oldpass.size() - 1) {
			int i = 0;
			int diversi = 0;
			for (int j = 0; j < newpass.size(); j++) {
				if (newpass[j] == oldpass[i]) {
					i++;
					continue;
				}

				if (newpass[j] != oldpass[i]) {
					j--;
					diversi++;
				}
				i++;
				if (diversi > 1) {
					valid6 = true;
					break;
				}
			}
			if (!valid6) {
				cout << "0" << endl;
				continue;
			}
		}
		else if (newpass.size() == oldpass.size()) {
			int diversi = 0;
			for (int i = 0; i < newpass.size(); i++) {
				if (newpass[i] == oldpass[i]) continue;
				diversi++;
			}
			
			if (diversi > 1) valid6 = true;

			if (!valid6) {
				cout << "0" << endl;
				continue;
			}
		}


		cout << "1" << endl;
	}




	return 0;
}
