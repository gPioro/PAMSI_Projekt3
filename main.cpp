#include "AI.h"

int main(){


    cout<<"\n               ------REGUŁY------\n\n";
    cout<<"Użytkownik wybiera pole, w które chce wstawić znak 'X'.\nIndeksy rzędów i kolumn numerowane są od 0. Przykładowa plansza:\n\n";
    cout<<"I 0|1|2\n0 -|-|-\n1 -|-|-\n2 -|-|-\n\n";
    cout<<"Wygrana następuje po ułożeniu w rzędzie, kolumnie\nlub po przekątnej odpowiedniej ilości znaków.\n";

    int wymiar;
    cout<< "\nPodaj wymiar planszy: ";
    cin>>wymiar;
    while(wymiar < 3){
        cout<<"Minimalny rozmiar planszy to 3x3\nPodaj wymiar planszy: ";
        cin>>wymiar;
    }
    cout<< "\n";

    char ** tablica = new char * [wymiar];
    for (int i = 0; i<wymiar; ++i){
        tablica[i] = new char [wymiar];
        for(int j = 0; j < wymiar; ++j){
            tablica[i][j] = '-';
        }
    }
    WyswietlPlansze(wymiar, tablica);

    while(!CzyWygrana(wymiar, tablica) || !czyMozliwyRuch(tablica, wymiar)){
        PostawZnak(tablica, wymiar);
        WyswietlPlansze(wymiar, tablica);
        if(czyMozliwyRuch(tablica, wymiar)){
            cout<<"Ruch komputera:\n";
            Ruch naj = najlepszyRuch(tablica, wymiar);
            ruchKomputera(naj, tablica, wymiar);
            WyswietlPlansze(wymiar, tablica);
        }
        else {
            CzyWygrana(wymiar, tablica);
            break;
        }        
    }
    
    delete [] tablica;
}