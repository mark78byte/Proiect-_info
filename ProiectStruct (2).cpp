#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

// Structura pentru entitatea Masina
struct Masina {
    char numar_masina[21];
    char nume_proprietar[31];
    char marca[21];
} masini[1000];

// Structura pentru entitatea Reparatie
struct Reparatie {
    int cod_reparatie;
    char numar_masina[21];
    char data[15];
    float cost_reparatie;
} reparatii[1000];

// Număr de mașini și reparații
int nr_masini = 0, nr_reparatii = 0;

/* Declarații funcții principale */
void incarcare_date();
void completeaza_date();
void salveaza_date();
void afiseaza_date();
void afiseaza_reparatii();
void afiseaza_fara_reparatii();
void adauga_masina();
void adauga_reparatie();
void echipa();
int meniu();

int main() {
    int optiune;
    do {
        optiune = meniu();
        switch (optiune) {
            case 1:  incarcare_date();          break;
            case 2:  completeaza_date();        break;
            case 3:  salveaza_date();           break;
            case 4:  afiseaza_date();           break;
            case 5:  afiseaza_reparatii();      break;
            case 6:  afiseaza_fara_reparatii(); break;
            case 7:  adauga_masina();           break;
            case 8:  adauga_reparatie();        break;
            case 9:  echipa();                  break;
            case 10: return 0;
        }
    } while (optiune != 10);

    return 0;
}

int meniu() {
    cout << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#      Echipa_6        #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << endl;
    cout << "[1] Incarca date din fisier" << endl;
    cout << "[2] Completeaza date de la tastatura" << endl;
    cout << "[3] Salveaza date in fisier" << endl;
    cout << "[4] Afiseaza toate datele" << endl;
    cout << "[5] Afiseaza reparatii pentru fiecare masina" << endl;
    cout << "[6] Afiseaza masinile fara reparatii" << endl;
    cout << "[7] Adauga o masina" << endl;
    cout << "[8] Adauga o reparatie" << endl;
    cout << "[9] Echipa" << endl;
    cout << "[10] Iesire" << endl;
    cout << "Alege o optiune: ";

    int opt;
    cin >> opt;
    return opt;
}

void echipa() {
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#      Echipa_6        #" << endl;
    cout << "#    Subiectul 30      #" << endl;
    cout << "#  David - Programator #" << endl;
    cout << "#  Alex - Programator  #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;

    cout << endl;

}

void incarcare_date() {
    ifstream fisier("grupa_6.in");
    if (!fisier) {
            cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
            cout << "# Eroare la deschiderea fisierului grupa_6.in #" << endl;
            cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
        return;
    }
    fisier >> nr_masini >> nr_reparatii;

    for (int i = 0; i < nr_masini; ++i) {
        fisier >> masini[i].numar_masina
               >> masini[i].nume_proprietar
               >> masini[i].marca;
    }

    for (int i = 0; i < nr_reparatii; ++i) {
        fisier >> reparatii[i].cod_reparatie
               >> reparatii[i].numar_masina
               >> reparatii[i].data
               >> reparatii[i].cost_reparatie;
    }

    fisier.close();
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "# Datele au fost incarcate cu succes. #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
}

void completeaza_date() {
    cout<<endl;
    cout << "Introdu numarul de masini pe care vrei sa le inregistrezi: ";
    cin >> nr_masini;



    for (int i = 0; i < nr_masini; i++) {
        cout << "Numarul de inmatriculare al masinii: ";
        cin >> masini[i].numar_masina;

        cout << "Numele proprietarului: ";
        cin >> masini[i].nume_proprietar;

        cout << "Marca: ";
        cin >> masini[i].marca;
    }

    cout << "Introdu numarul de reparatii efectuate: ";
    cin >> nr_reparatii;

    for (int i = 0; i < nr_reparatii; ++i) {
        cout << "Cod reparatie: ";
        cin >> reparatii[i].cod_reparatie;

        cout << "Numarul de inmatriculare al masinii: ";
        cin >> reparatii[i].numar_masina;

        cout << "Data efectuarii reparatiei: ";
        cin >> reparatii[i].data;

        cout << "Cost: ";
        cin >> reparatii[i].cost_reparatie;
    }
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "# Datele au fost completate cu succes. #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
}

void salveaza_date() {
    ofstream fisier("grupa_6.out");
    if (!fisier) {
            cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
            cout << "# Eroare la deschiderea fisierului grupa_6.out #" << endl;
            cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
        return;
    }

    fisier << nr_masini << ' ' << nr_reparatii << '\n';

    for (int i = 0; i < nr_masini; i++) {
        fisier << masini[i].numar_masina << ' '
               << masini[i].nume_proprietar << ' '
               << masini[i].marca << '\n';
    }

    for (int i = 0; i < nr_reparatii; i++) {
        fisier << reparatii[i].cod_reparatie << ' '
               << reparatii[i].numar_masina << ' '
               << reparatii[i].data << ' '
               << reparatii[i].cost_reparatie << '\n';
    }

    fisier.close();
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "# Datele au fost salvate cu succes. #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
}
#include <iostream>
#include <iomanip>  // <== ca să folosim setw, left
using namespace std;

// ... restul codului rămâne la fel ...

void afiseaza_date() { /// !!!!!!!!!!!!!!!!!!!!!AICI AM RAMAS CU MODIFICARILE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cout << "#~~~~~~~~~~~~~~~~#" << endl;
    cout << "#  BAZA DE DATE  #" << endl;
    cout << "#~~~~~~~~~~~~~~~~#" << endl << endl;

    // Secțiunea pentru mașini:
    cout << "#~~~~~~~~#" << endl;
    cout << "# Masini #" << endl;
    cout << "#~~~~~~~~#" << endl;

    // Linie de „cap de tabel”
    cout << "#~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "# Numar Inmatriculare #" << "   Nume Proprietar   #" << "    Marca Masinii    #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << endl;

    // Afișarea fiecărei mașini pe câte un rând
    for (int i = 0; i < nr_masini; ++i) {
        // Folosim manipulatoarele de flux pentru aliniere
        cout << left
             << "# " << setw(20) << masini[i].numar_masina
             << "# " << setw(20) << masini[i].nume_proprietar
             << "# " << setw(20) << masini[i].marca
             << "#" << endl;
    }
    // Linie de închidere pentru tabelul mașini
    cout << "#~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << endl;

    // Secțiunea pentru reparații
    cout << "\n#~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#       REPARATII        #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;

    cout << "#~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#   Codul Reparatiei  #" << " Numar Inmatriculare #" << "   Data Reparatiei   #" << "  Costul reparatiei  #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << endl;

    for (int i = 0; i < nr_reparatii; ++i) {
        cout << left
             << "# " << setw(20) <<reparatii[i].cod_reparatie
             << "# " << setw(20) <<reparatii[i].numar_masina
             << "# " << setw(20) << reparatii[i].data
             << "# " << setw(20) << reparatii[i].cost_reparatie
             << "#" << endl;
    }
    cout <<"#~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#" << "~~~~~~~~~~~~~~~~~~~~~#"  <<"~~~~~~~~~~~~~~~~~~~~~#" << endl;
}

void afiseaza_reparatii() {
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "# REPARATII PE MASINI  #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;

    for (int i = 0; i < nr_masini; ++i) {
        cout << "Reparatii pentru masina: " << masini[i].numar_masina << endl;
        for (int j = 0; j < nr_reparatii; ++j) {
            if (strcmp(masini[i].numar_masina, reparatii[j].numar_masina) == 0) {
                cout << "Cod: " << reparatii[j].cod_reparatie
                     << ", Data: " << reparatii[j].data
                     << ", Cost: " << reparatii[j].cost_reparatie << endl;
            }
        }
        cout << endl;
    }
}

void afiseaza_fara_reparatii() {
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "# MASINI FARA NICIO REPARATIE     #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;

    for (int i = 0; i < nr_masini; ++i) {
        bool are_reparatii = false;
        for (int j = 0; j < nr_reparatii; ++j) {
            if (strcmp(masini[i].numar_masina, reparatii[j].numar_masina) == 0) {
                are_reparatii = true;
                break;
            }
        }
        if (!are_reparatii) {
            cout << masini[i].numar_masina << " "
                 << masini[i].nume_proprietar << " "
                 << masini[i].marca << endl;
        }
    }
    cout << endl;
}

void adauga_masina() {
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#   ADAUGA O MASINA    #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~#" << endl;

    cout << "Numar masina: ";
    cin >> masini[nr_masini].numar_masina;

    cout << "Nume proprietar: ";
    cin >> masini[nr_masini].nume_proprietar;

    cout << "Marca: ";
    cin >> masini[nr_masini].marca;

    nr_masini++;
    cout << "Masina a fost adaugata cu succes." << endl;
    cout << endl;
}

void adauga_reparatie() {
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;
    cout << "#   ADAUGA O REPARATIE    #" << endl;
    cout << "#~~~~~~~~~~~~~~~~~~~~~~~~~#" << endl;

    cout << "Cod reparatie: ";
    cin >> reparatii[nr_reparatii].cod_reparatie;

    cout << "Numar masina: ";
    cin >> reparatii[nr_reparatii].numar_masina;

    cout << "Data: ";
    cin >> reparatii[nr_reparatii].data;

    cout << "Cost: ";
    cin >> reparatii[nr_reparatii].cost_reparatie;

    nr_reparatii++;
    cout << "Reparatia a fost adaugata cu succes." << endl;
    cout << endl;
}
