#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nome;
    double conto;
    double portafoglio; 
    int tempo; 
    bool contoNegativo;

public:
    Cliente(string n, double s = 0.0)
        : nome(n), conto(s), portafoglio(0.0), tempo(0), contoNegativo(false) {}

    
    void avanzaTempo(int mesi) {
        tempo += mesi;
        portafoglio += 100 * mesi; 
        cout << mesi << " mesi avanzati. Portafoglio ora: " << portafoglio << "€" << endl;
    }

    
    void depositaDaPortafoglio(double importo) {
        if (importo <= 0) {
            cout << "Importo non valido "<< endl;
        } else if(importo > portafoglio){
            cout<<"Non hai abbastanza fondi nel portafoglio." << endl;        
        } else{
            conto += importo;
            portafoglio -= importo;
            cout <<"Deposito riuscito con successo." << endl;
        }
    }

    void preleva(double importo) {
        if (importo > conto) {
            cout << "Non hai abbastanza fondi." << endl;
        } else {
            conto -= importo;
            cout << "Prelievo riuscito: " << importo << "€" << endl;
        }
    }

    void mostraStato() {
        cout << "Nome: " << nome << endl;
        cout << "Saldo conto: " << conto << "€" << endl;
        cout << "Saldo portafoglio: " << portafoglio << "€" << endl;
        cout <<    "Mesi trascorsi: " <<  tempo << endl;
    }

   
    void investi(double importo, int durata, int rischio) {
        if(contoNegativo) {
            cout << "Il tuo conto è negativo. Non potrai fare investimenti finché il conto non sarà positivo" <<endl;
            return;
        }
        
        if (importo > conto) {
            cout << "Fondi insufficienti per l'investimento." << endl;
            return;
        }
        
        
        double guadagno = 0.0;

        if (durata <= 2) {  
            if (rischio == 1) {
                guadagno = rand() % (-5) + (-1);  
            } else if (rischio == 2) {
                guadagno = rand() % 9 + 4;  
            } else if (rischio == 3) {
                guadagno = rand() % 11 + 10;  
            }
        } else if (durata <= 6) {  
            if (rischio == 1) {
                guadagno = rand() % 11 + 1;  
            } else if (rischio == 2) {
                guadagno = rand() % (-13) + (-10);  
            } else if (rischio == 3) {
                guadagno = rand() % 19 + 13;  
            }
        } else {  
            if (rischio == 1) {
                guadagno = rand() % 16 + 1;  
            } else if (rischio == 2) {
                guadagno = rand() % 24 + 15;  
            } else if (rischio == 3) {
                guadagno = rand() % (-36) + (-30);  
            }
        }

        guadagno = importo * guadagno / 100;  
        conto = importo + guadagno;  
        cout << "Investimento completato. Guadagno/perdita: " << guadagno << "€" << endl;
    }
};