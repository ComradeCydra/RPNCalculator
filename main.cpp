#include <iostream>

using namespace std;

struct cislo {
    int hodnota;
    struct cislo* dalsi = nullptr;
};

struct cislo* zacatek = nullptr;

void ToBeg(int value){
    cislo *help;

    help = new cislo;
    help->hodnota = value;
    help->dalsi = zacatek;
    zacatek = help;
}

int CancelAtBeg(){
    cislo *help;

    help = zacatek;
    zacatek = help->dalsi;
    int hodnota = help->hodnota;
    delete help;
    return hodnota;
}

int main()
{
    string input;
    cout << "RPN Calculator Deluxe 2000" << endl;
    do {
        cout << "Zadejte cislo nebo znak +,-,*,/,=: ";
        cin >> input;
        int value = atoi(input.c_str());
        if (value == 0){
            if(input == "+"){
                int a = CancelAtBeg();
                int b = CancelAtBeg();
                ToBeg(a+b);
            } else if(input == "*"){
                int a = CancelAtBeg();
                int b = CancelAtBeg();
                ToBeg(a*b);
            } else if(input == "/"){
                int a = CancelAtBeg();
                int b = CancelAtBeg();
                ToBeg(b/a);
            } else if(input == "-"){
                int a = CancelAtBeg();
                int b = CancelAtBeg();
                ToBeg(b-a);
            }
        } else {
            ToBeg(value);
        }
    } while(input != "=");
    cout << "Vysledek je: " << CancelAtBeg() <<  endl;
}
