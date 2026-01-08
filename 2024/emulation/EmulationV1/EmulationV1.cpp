#include <iostream>
#include <vector>
#include <string>
#include <tuple>

#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;

    ll ans = 0;
    
    vector<string> op(n);
    //           var num label
    vector<tuple<char, ll, string>> val(n , {'0', -1, "0"});

    for (int i = 0; i < n; i++) {
        cin >> op[i];
        if (op[i] == "add" || op[i] == "sub" || op[i] == "mul") {
            cin >> get<0>(val[i]);
            cin >> get<1>(val[i]);
        }
        else if (op[i] == "lab") {
            cin >> get<2>(val[i]);
        }
        else if (op[i] == "jmp") {
            cin >> get<0>(val[i]);
            cin >> get<1>(val[i]);
            cin >> get<2>(val[i]);
        }
    }
    vector<ll> endvar(6, 0);
    
    for (int i = 0; i < n; i++) {
        string oper = op[i];
        char var = get<0>(val[i]);
        ll num = get<1>(val[i]);
        string lab = get<2>(val[i]);
        
        if (oper == "add") {
            endvar[var - 'a'] += num;
        }
        else if (oper == "sub") {
            endvar[var - 'a'] -= num;
        }
        else if (oper == "mul") {
            endvar[var - 'a'] *= num;
        }
        else if (oper == "lab") {
        }
        else if (oper == "jmp") {

            if (endvar[var - 'a'] == num) {
                
                for (int k = 0; k < n; k++) {
                    if (get<2>(val[k]) == lab && k != i) {
                        i = k;
                        break;
                    }
                }

            }

        }
    }

    for (int i = 0; i < 6; i++) {
        ans += endvar[i];
    }
    cout << ans << endl;

    return 0;
}

