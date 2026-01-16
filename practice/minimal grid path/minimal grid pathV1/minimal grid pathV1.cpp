#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 1. Ottimizzazione Input/Output (fondamentale in C++)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Usiamo vector<string> invece di vector<vector<char>> per comodità
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // La stringa risultato. Iniziamo subito col primo carattere.
    string result = "";
    result += grid[0][0];

    // "frontier" contiene le coordinate (riga, colonna) delle celle 
    // che stiamo considerando in questo passo.
    vector<pair<int, int>> frontier;
    frontier.push_back({ 0, 0 });

    // Dobbiamo fare 2*n - 2 passi per arrivare da (0,0) a (n-1, n-1)
    // (La lunghezza totale del percorso è 2*n - 1)
    for (int step = 0; step < 2 * n - 2; step++) {

        char min_char = 'z' + 1; // '{' è il carattere ASCII subito dopo 'z', serve come valore alto.

        // FASE 1: Troviamo qual è il carattere minimo raggiungibile
        for (auto p : frontier) {
            int r = p.first;
            int c = p.second;

            // Controlla Destra (r, c+1)
            if (c + 1 < n) {
                if (grid[r][c + 1] < min_char) {
                    min_char = grid[r][c + 1];
                }
            }
            // Controlla Giù (r+1, c)
            if (r + 1 < n) {
                if (grid[r + 1][c] < min_char) {
                    min_char = grid[r + 1][c];
                }
            }
        }

        // Aggiungiamo il carattere vincitore al risultato
        result += min_char;

        // FASE 2: Costruiamo la nuova frontiera solo con le celle che hanno 'min_char'
        vector<pair<int, int>> next_frontier;

        for (auto p : frontier) {
            int r = p.first;
            int c = p.second;

            // Controlla Destra
            if (c + 1 < n && grid[r][c + 1] == min_char) {
                // Evitiamo duplicati: controlliamo se l'ultima cella aggiunta è uguale a questa
                if (next_frontier.empty() || next_frontier.back() != make_pair(r, c + 1)) {
                    next_frontier.push_back({ r, c + 1 });
                }
            }

            // Controlla Giù
            if (r + 1 < n && grid[r + 1][c] == min_char) {
                // Evitiamo duplicati
                if (next_frontier.empty() || next_frontier.back() != make_pair(r + 1, c)) {
                    next_frontier.push_back({ r + 1, c });
                }
            }
        }

        // Aggiorniamo la frontiera per il prossimo giro
        frontier = next_frontier;
    }

    cout << result << endl;

    return 0;
}