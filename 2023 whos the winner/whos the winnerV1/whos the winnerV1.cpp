#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <math.h>
#include <tuple>
#include <map>

using namespace std;

void solve(vector<tuple<int, string, int>> tasks, vector<tuple<int, int, string, int>> subs, int p, int t, int s) {

    vector<vector<bool>> isdone(p + 1,vector<bool>(t + 1, false));
    
    vector<pair<int, int>> player(p + 1, {0,0});
    //points time

    vector<tuple<int, float, float>> scoreboard(p + 1);
    // points time pid
    // pid task flag time
    for (int i = 0; i < s; i++) {

        bool valid = true;
        string flag = get<2>(subs[i]);
        int pid = get<0>(subs[i]);
        int task = get<1>(subs[i]) - 1;
        int time = get<3>(subs[i]);

        string taskflag = get<1>(tasks[task]);

        if (flag.size() != taskflag.size()) {
            continue;
        }
        for (int j = 0; j < flag.size(); j++) {
            if (flag[i] != taskflag[i]) {
                valid = false;
                break;
            }
        }
        if (!valid||isdone[pid][task]) continue;

        isdone[pid][task] = true;
        player[pid].first += get<2>(tasks[task]);
        player[pid].second = max(time, player[pid].second);
    }

    for (int i = 1; i <= p; i++) {
        get<0>(scoreboard[i]) = player[i].first;
        get<1>(scoreboard[i]) = (float)1/player[i].second;
        get<2>(scoreboard[i]) = (float)1/i;
    }

    sort(scoreboard.begin(), scoreboard.end());
    reverse(scoreboard.begin(), scoreboard.end());

    for (int i = 0; i < p; i++) {
        cout << 1/get<2>(scoreboard[i]) << " " << get<0>(scoreboard[i]) << endl;
    }

}


int main()
{
    int p, t, s;

    cin >> p >> t >> s;

    vector<tuple<int, string, int>> tasks(t);
    vector<tuple<int, int, string, int>> subs(s);

    for (int i = 0; i < t; i++) {
        cin >> get<0>(tasks[i]) >> get<1>(tasks[i]) >> get<2>(tasks[i]);
    }
    
    for (int i = 0; i < s; i++) {
        cin >> get<0>(subs[i]) >> get<1>(subs[i]) >> get<2>(subs[i]) >> get<3>(subs[i]);
    }

    solve(tasks, subs, p, t, s);

    return 0;
}

