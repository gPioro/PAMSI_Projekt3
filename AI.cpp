#include "AI.h"

void WyswietlPlansze(int wymiar, char ** tablica){
    for ( int i = 0; i < wymiar; ++i, cout<<endl){  
        if(i>=1 && i<wymiar){
        }
        for ( int j = 0; j < wymiar; ++j){
            if(j>=0 && j<wymiar-1){
                cout<<tablica[i][j]<<"|";
            } else {
                cout<<tablica[i][j];
            }
        }
    }
    cout<<"\n";
}

void PostawZnak(char ** tablica, int wymiar){
    int w,k;
    cout<<"Ruch gracza:\n";
    cout<<"Podaj indeks wiersza, w który chcesz wstawić 'X':";
    cin>>w;
    cout<<"Podaj indeks kolumny, w którą chcesz wstawić 'X':";
    cin>>k;
    cout<<"\n";
    if(tablica[w][k]=='-'){
        tablica[w][k] = 'X';
    } else if(tablica[w][k]=='X') {
        cout<<"Pole zajęte! Wybierz inne miejsce.\n";
        PostawZnak(tablica, wymiar);
    } else if(tablica[w][k]=='O') {
        cout<<"Pole zajęte! Wybierz inne miejsce.\n";
        PostawZnak(tablica, wymiar);
    }
}

bool czyMozliwyRuch(char ** tablica, int wymiar){
    for(int i = 0; i < wymiar; i++){
        for(int j = 0; j < wymiar; j++){
            if(tablica[i][j]=='-'){
                return true;
            }
        }
    }
    return false;
}

bool CzyWygrana(int wymiar, char ** tablica){
    for(int i = 0; i < wymiar; i++){
        for(int j = 0; j < wymiar; j++){
            if(tablica[i][0] == tablica[i][1] && tablica[i][1] == tablica[i][2]){
                if(tablica[i][0]=='X'){
                    cout<<"WYGRANA GRACZA\n";
                    return true;
                } else if(tablica[i][0]=='O'){
                    cout<<"WYGRANA KOMPUTERA\n";
                    return true;
                }
            }
            else if(tablica[0][j] == tablica[1][j] && tablica[1][j] == tablica[2][j]){
                if(tablica[0][j]=='X'){
                    cout<<"WYGRANA GRACZA\n";
                    return true;
                } else if(tablica[0][j]=='O'){
                    cout<<"WYGRANA KOMPUTERA\n";
                    return true;
                }
            }
            else if(tablica[0][0] == tablica[1][1] && tablica[1][1] == tablica[2][2]){
                if(tablica[0][0]=='X'){
                    cout<<"WYGRANA GRACZA\n";
                    return true;
                } else if(tablica[0][0]=='O'){
                    cout<<"WYGRANA KOMPUTERA\n";
                    return true;
                }
            }
            else if(tablica[0][2] == tablica[1][1] && tablica[1][1] == tablica[2][0]){
                if(tablica[0][2]=='X'){
                    cout<<"WYGRANA GRACZA\n";
                    return true;
                } else if(tablica[0][2]=='O'){
                    cout<<"WYGRANA KOMPUTERA\n";
                    return true;
                }
            }
        }
    }
    if(!czyMozliwyRuch(tablica, wymiar)){
        cout<<"REMIS\n";
        return false;
    }
    return false;
}

int Ocena(int wymiar, char ** tablica){
    for(int i = 0; i < wymiar; i++){
        if(tablica[i][0] == tablica[i][1] && tablica[i][1] == tablica[i][2]){
            if(tablica[i][0]=='X'){
                return +10; 
            } else if(tablica[i][0]=='O'){
                return -10;
            }
        }
    }
    for(int j = 0; j < wymiar; j++){
        if(tablica[0][j] == tablica[1][j] && tablica[1][j] == tablica[2][j]){
            if(tablica[0][j]=='X'){
                return +10;
            } else if(tablica[0][j]=='O'){
                return -10;
            }
        }
    }
    if(tablica[0][0] == tablica[1][1] && tablica[1][1] == tablica[2][2]){
        if(tablica[0][0]=='X'){
            return +10;
        } else if(tablica[0][0]=='O'){
            return -10;
        }
    }
    if(tablica[0][2] == tablica[1][1] && tablica[1][1] == tablica[2][0] ){
        if(tablica[0][2]=='X'){
            return +10;
        } else if(tablica[0][2]=='O'){
            return -10;
        }
    }
    return 0;
}

int minimax(char **tablica, int wymiar, int glebokosc, bool maxiGracz){
    int wynik = Ocena(wymiar, tablica);

    if(wynik == 10){
        return wynik;
    }
    if(wynik == -10){
        return wynik;
    }
    if(czyMozliwyRuch(tablica, wymiar)==false){
        return 0;
    }

    if(maxiGracz){

        int najlepszy = -1000;

        for(int i = 0; i < wymiar; i++){
            for(int j = 0; j < wymiar; j++){

                if(tablica[i][j]=='-'){
                    tablica[i][j] = 'X';

                    najlepszy = max(najlepszy, minimax(tablica, wymiar, glebokosc + 1, !maxiGracz));
                    tablica[i][j] = '-';
                }
            }
        }
        return najlepszy;

    } else {

        int najlepszy = 1000;
        for(int i = 0; i < wymiar; i++){
            for(int j = 0; j < wymiar; j++){
                if(tablica[i][j]=='-'){
                    tablica[i][j] = 'O';

                    najlepszy = min(najlepszy, minimax(tablica, wymiar, glebokosc + 1, maxiGracz));
                    tablica[i][j] = '-';
                }
            }
        }
        return najlepszy;
    }
}

Ruch najlepszyRuch(char** tablica, int wymiar){
    int najlepszy = 1000;
    Ruch najlepszyRuch;
    najlepszyRuch.rzad = -1;
    najlepszyRuch.kolumna = -1;
    for(int i = 0; i < wymiar; i++){
        for(int j = 0; j < wymiar; j++){
            if(tablica[i][j]=='-'){
                tablica[i][j] = 'O';

                int ruch = minimax(tablica, wymiar, 0, true);

                tablica[i][j] = '-';

                if(ruch < najlepszy){                  
                    najlepszyRuch.rzad = i;
                    najlepszyRuch.kolumna = j;
                    najlepszy = ruch;
                }
            }
        }
    }

    return najlepszyRuch;
}

void ruchKomputera(Ruch ruch, char** tablica, int wymiar){
    for(int i = 0; i < wymiar; i++){
        for(int j = 0; j < wymiar; j++){
            tablica[ruch.rzad][ruch.kolumna] = 'O';
        }
    }
}