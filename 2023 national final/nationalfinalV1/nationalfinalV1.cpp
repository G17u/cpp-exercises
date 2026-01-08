#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>


using namespace std;

bool check(int w, const vector<int>& task, int n, int tmax) {
    priority_queue<long long, vector<long long>, greater<long long>> workers;
    long long tempo = 0;
    long long tmp;

    for (int i = 0; i < w; i++) {
        workers.push(0);
    }

    for (int i = 0; i < n; i++) {
        tmp = workers.top();
        workers.pop();
        workers.push(tmp + task[i]);
        tempo = max(tmp + task[i], tempo);
        if (tempo > tmax)return false;
    }
    if (tempo > tmax)return false;
    
    return true;
}


int main()
{
    int n, tmax;
    cin >> n >> tmax;
    
    int w = n / 2;
    vector<int> task(n);

    for (int i = 0; i < n; i++) {
        cin >> task[i];
    }

    int low = 1;      // Minimo 1 worker
    int high = n;     // Massimo N worker
    int ans = n;      // Variabile per salvare la risposta migliore trovata

    while (low <= high) {
        int mid = low + (high - low) / 2; // Questo è il tuo "w"

        if (check(mid, task, n, tmax)) {
            // Se 'mid' funziona, salviamolo come possibile risposta
            ans = mid;
            // E proviamo a cercare se ce la facciamo con MENO worker (parte sinistra)
            high = mid - 1;
        }
        else {
            // Se non funziona, ci servono PIÙ worker (parte destra)
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
