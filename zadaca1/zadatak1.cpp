#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> unosSekvence() {
    vector<int> sekvenca;
    string linija;
    
    getline(cin, linija);  // Ucitaje citavu liniju za sekvencu
    stringstream ss(linija);
    int broj;

    while (ss >> broj) {
        sekvenca.push_back(broj);
    }

    return sekvenca;
}

int ciklicnaPermutacija(const vector<int>& prva, const vector<int>& druga) {
    if (prva.size() != druga.size())  // Ako su razlicite duzine onda jednostavno nije moguca permutacija
        return -1;

    vector<int> dupliranaPrva = prva;
    dupliranaPrva.insert(dupliranaPrva.end(), prva.begin(), prva.end());

    for (size_t i = 0; i < prva.size(); i++) {
        if (vector<int>(dupliranaPrva.begin() + i, dupliranaPrva.begin() + i + druga.size()) == druga) {
            return i;
        }
    }

    return -1;
}

int main() {
    cout << "Prva sekvenca: ";
    vector<int> prva = unosSekvence();

    cout << "Druga sekvenca: ";
    vector<int> druga = unosSekvence();

    int rezultat = ciklicnaPermutacija(prva, druga);

    if (rezultat == -1) {
        cout << "Druga sekvenca nije ciklièka permutacija prve." << endl;
    } else {
        cout << "Druga sekvenca je ciklièka permutacija prve s pomakom " << rezultat << "." << endl;
    }

    return 0;
}

