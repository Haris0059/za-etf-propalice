#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Funkcija za parsiranje unosa i dobijanje broja redova i kolona
vector<int> brojRedovaIKolona() {
    vector<int> lista;
    int broj1, broj2;
    
    cin >> broj1 >> broj2; // Unos dva broja
    lista.push_back(broj1);
    lista.push_back(broj2);

    return lista;
}

// Funkcija za unos reda matrice
vector<int> unos(int brojKolona) {
    vector<int> sekvenca;
    int broj;

    for (int i = 0; i < brojKolona; i++) {
        cin >> broj; // Unos broja
        sekvenca.push_back(broj);
    }

    return sekvenca;
}

// Funkcija za primjenu usrednjavajuæeg filtera
void usrednjavajuciFilter(vector<vector<int>> &matrica, int n) {
    int brojRedova = matrica.size();
    int brojKolona = matrica[0].size();

    // Kreiranje rezultantne matrice iste velièine
    vector<vector<double>> filtriranaMatrica(brojRedova, vector<double>(brojKolona, 0));

    for (int i = 0; i < brojRedova; i++) {
        for (int j = 0; j < brojKolona; j++) {
            double suma = 0;
            int brojac = 0;

            // Prolazak kroz (2N+1) x (2N+1) prozor
            for (int x = i - n; x <= i + n; x++) {
                for (int y = j - n; y <= j + n; y++) {
                    if (x >= 0 && x < brojRedova && y >= 0 && y < brojKolona) {
                        suma += matrica[x][y];
                        brojac++;
                    }
                }
            }

            // Dodavanje zaokružene srednje vrijednosti u novi red
            filtriranaMatrica[i][j] = round((suma / brojac) * 100.0) / 100.0;
        }
    }

    // Ispis filtrirane matrice
    cout << "Matrica nakon filtriranja:" << endl;
    for (const auto &red : filtriranaMatrica) {
        for (double broj : red) {
            printf("%7.2f", broj);
        }
        cout << endl;
    }
}

int main() {
    cout << "Unesite broj redova i kolona matrice: ";
    vector<int> lista = brojRedovaIKolona();

    int brojRedova = lista[0];
    int brojKolona = lista[1];

    // Kreiranje matrice
    vector<vector<int>> matrica;

    cout << "Unesite elemente matrice:" << endl;
    for (int i = 0; i < brojRedova; i++) {
        vector<int> red = unos(brojKolona); // Dobijamo listu brojeva
        matrica.push_back(red); // Dodajemo red u matricu
    }

    cout << "Unesite broj filtriranja: ";
    int n;
    cin >> n;

    if (n < 0) {
        cout << "GRESKA: Neispravan red filtriranja!" << endl;
    } else {
        usrednjavajuciFilter(matrica, n);
    }

    return 0;
}

