#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <deque>
#include <tuple>
#include <algorithm>



using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<int> ans(T);

    for (int t = 0; t < T; t++) {

        int nid, nskills, ps;
        cin >> nid >> nskills >> ps;

        // vector<vector<pair<string, int>>> playerskills(nid + 1, vector<pair<string,int>>(ps));
        deque<string> skills(nskills);
        deque<tuple<string, int, int>> tot(nid * ps);
        int totalpoints = 0;
        vector<bool> used(nid + 1, false);

        for (int i = 0; i < nskills; i++) {
            cin >> skills[i];
        }
        int k = 0;
        for (int i = 1; i <= nid; i++) {
            for (int j = 0; j < ps; j++) {
                cin >> get<2>(tot[k]);
                cin >> get<0>(tot[k]);
                cin >> get<1>(tot[k]);
                k++;
            }
        }
        sort(tot.begin(), tot.end(), [](tuple<string, int, int>& a, tuple<string, int, int>& b) {
            
            // Regola: true se A deve stare prima di B
            if (get<0>(a) != get<0>(b)) {
                return get<0>(a) < get<0>(b); // Ordina per Skill (alfabetico)
            }
            // Se le skill sono uguali, guardiamo i punti
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) > get<1>(b); // Punti decrescenti (voglio il più forte prima)
            }
            // Se anche i punti sono uguali
            return get<2>(a) < get<2>(b); // ID crescente
            
            });
        sort(skills.begin(), skills.end());

        int j = 0;
        for (int i = 0; i < skills.size(); i++) {

            if (j >= tot.size()) break;

            string skill = get<0>(tot[j]);
            int points = get<1>(tot[j]);
            int pid = get<2>(tot[j]);

            if (skills[i] == skill) {
                if (!used[pid]) {
                    totalpoints += points;
                    used[pid] = true;
                    j++;
                    continue;
                }
                i--;
                j++;
            }
            else if (skills[i] < skill) {
                
                continue;
            }
            else if (skills[i] > skill) {
                i--;
                j++;
                continue;
            }

        }
        

        ans[t] = totalpoints;
    }


    for (int i = 0; i < T; i++)
        cout << ans[i] << endl;


    return 0;
}
