#include <iostream>

using namespace std;

struct Ruch
{
    int kolumna, rzad;
};

void WyswietlPlansze(int wymiar, char ** tablica);
void PostawZnak(char ** tablica, int wymiar);
bool czyMozliwyRuch(char ** tablica, int wymiar);
bool CzyWygrana(int wymiar, char ** tablica);
int Ocena(int wymiar, char ** tablica);
int minimax(char **tablica, int wymiar, int glebokosc, bool maxiGracz);
Ruch najlepszyRuch(char** tablica, int wymiar);
void ruchKomputera(Ruch ruch, char** tablica, int wymiar);