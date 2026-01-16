#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funzione principale per ogni test case
void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    int max_val = 0;

    // Lettura input e ricerca del valore massimo M
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    // pos[v] conterrà la lista degli indici dove compare il valore v
    // Usiamo vector di vector per gestire le posizioni
    vector<vector<int>> pos(max_val + 1);

    long long totale_coppie = 0;
    int max_l = -1; // Il limite sinistro valido più alto trovato finora

    // Scorriamo r da 0 a N-1
    for (int r = 0; r < N; r++) {
        int val_r = a[r];

        // Dobbiamo cercare se val_r completa una tripletta (i, j, k)
        // I casi sono due:
        // CASO 1: val_r è il termine al quadrato (il centro della formula: x * y = val_r^2)
        // CASO 2: val_r è uno dei termini del prodotto (un lato: val_r * y = z^2)

        // Nota: Per semplicità e per i primi subtask, possiamo iterare sui valori possibili
        // Poiché M è piccolo (fino a 100 nel subtask 3), questo ciclo non è troppo pesante.

        // --- CASO 1: a[r] è il "k" (a[i] * a[j] = a[r]^2) ---
        long long target = (long long)val_r * val_r;
        for (int x = 1; x <= max_val; x++) {
            // Cerchiamo y tale che x * y = val_r^2
            if (target % x == 0) {
                int y = target / x;
                if (y > max_val) continue; // Fuori range

                // Abbiamo i valori x, y, val_r. Cerchiamo se x e y esistono nell'array prima di r.
                // Ci servono indici distinti.
                if (pos[x].empty() || pos[y].empty()) continue;

                // Prendiamo l'ultimo indice disponibile per x e y
                int idx_x = pos[x].back();
                int idx_y = pos[y].back();

                // Se x == y, ci servono DUE occorrenze diverse
                if (x == y) {
                    if (pos[x].size() < 2) continue;
                    idx_x = pos[x][pos[x].size() - 2]; // Penultimo
                    idx_y = pos[x].back();             // Ultimo
                }

                // Se abbiamo trovato indici validi < r
                // La tripletta inizia nel minimo tra idx_x, idx_y (e r, ma r è il max)
                int inizio_tripletta = min(idx_x, idx_y);
                max_l = max(max_l, inizio_tripletta);
            }
        }

        // --- CASO 2: a[r] è "i" o "j" (a[r] * y = z^2) ---
        for (int z = 1; z <= max_val; z++) {
            long long z2 = (long long)z * z;
            if (z2 % val_r == 0) {
                int y = z2 / val_r;
                if (y > max_val) continue;

                // Abbiamo valori val_r, y, z.
                // val_r è all'indice r. Cerchiamo indici passati per y e z.
                if (pos[y].empty() || pos[z].empty()) continue;

                int idx_y = pos[y].back();
                int idx_z = pos[z].back();

                // Gestione indici distinti
                // Dobbiamo assicurarci che idx_y, idx_z e r siano tutti diversi.
                // r è sicuramente > di tutti. Ma idx_y potrebbe essere uguale a idx_z se y == z.
                if (y == z) {
                    if (pos[y].size() < 2) continue;
                    idx_y = pos[y][pos[y].size() - 2];
                    idx_z = pos[y].back();
                }

                int inizio_tripletta = min(idx_y, idx_z);
                max_l = max(max_l, inizio_tripletta);
            }
        }

        // Aggiungiamo alla soluzione
        // Se max_l è 2, significa che gli intervalli [0..r], [1..r], [2..r] sono validi.
        // Quindi sono max_l + 1 intervalli.
        if (max_l != -1) {
            totale_coppie += (max_l + 1);
        }

        // Infine, aggiungiamo la posizione corrente alla lista
        pos[val_r].push_back(r);
    }

    cout << totale_coppie << endl;
}

int main() {
    // Ottimizzazione I/O standard per le gare
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
