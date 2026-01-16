#include <iostream>
#include <vector>
#include <string>
#include <cctype>


using namespace std;


typedef struct instruction {
    string ins;
    char fo;
    char so;
    int rot;
};

int main()
{
    string alf = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    int n;
    cin >> n;
    
    vector<instruction> a(n);
    string res;

    for (int i = 0; i < n; i++) {
        cin >> a[i].ins;

        if (a[i].ins == "add") {
            cin >> a[i].fo;
        }
        else if (a[i].ins == "del") {
            
        }
        else if (a[i].ins == "swap") {
            cin >> a[i].fo;
            cin >> a[i].so;
        }
        else if (a[i].ins == "rot") {
            cin >> a[i].rot;
        }
    }

    for (int j = 0; j < n; j++) {

        instruction in = a[j];

        if (in.ins == "add") {
            res.push_back(in.fo);
        }
        else if (in.ins == "del") {
            if (!res.empty()) {
                res.pop_back();
            }
        }
        else if (in.ins == "swap") {
            for (int i = 0; i < res.size();i++) {
                if (res[i] == in.fo) {
                    res[i] = in.so;
                }
                else if (res[i] == in.so) {
                    res[i] = in.fo;
                }
                
            }
        }
        else if (in.ins == "rot") {
            for (int i = 0; i < res.size(); i++) {
                if (isupper(res[i])) {
 
                    res[i] = alf[(res[i] - 'A' + 26 + in.rot) % 62];

                }
                else if (islower(res[i])) {

                    res[i] = alf[(res[i] - 'a' + in.rot) % 62];

                }
                else if (isdigit(res[i])) {

                    res[i] = alf[(res[i] - '0' + 52 + in.rot) % 62];

                }
            }
        }

    }

    cout << res << endl;

    return 0;
}

