#include "class.h"

int main() {
    string nomeCliente;
    cout << "Benvenuto! Inserisci il tuo nome: ";
    cin >> nomeCliente;

    Cliente cliente(nomeCliente); 
    int scelta;

    do {
        
        cout << "\nCosa vuoi fare?\n";
        cout << "1. Deposita fondi\n";
        cout << "2. Preleva fondi\n";
        cout << "3. Visualizza stato conto\n";
        cout << "4. Investi\n";
        cout << "5. Avanza nel tempo\n";
        cout << "6. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
        case 1: {
            double importo;
            cout << "Quanto vuoi depositare? ";
            cin >> importo;
            cliente.depositaDaPortafoglio(importo);
            break;
        }
        case 2: {
            double importo;
            cout << "Quanto vuoi prelevare? ";
            cin >> importo;
            cliente.preleva(importo);
            break;
        }
        case 3:
            cliente.mostraStato();
            break;
        case 4: {
            double importo;
            int durata, rischio;
            cout << "Quanto vuoi investire? ";
            cin >> importo;
            cout << "Inserisci la durata dell'investimento (mesi): ";
            cin >> durata;
            cout << "Inserisci il livello di rischio (1-3): ";  
            cin >> rischio;
            cliente.investi(importo, durata, rischio);
            break;
        }
        case 5: {
            int mesi;
            cout << "Di quanti mesi vuoi avanzare? ";
            cin >> mesi;
            cliente.avanzaTempo(mesi);
            break;
        }
        case 6:
            cout << "Grazie e Arrivederci!\n";
            break;
        default:
            cout << "Scelta non valida. Riprova.\n";
        }
    } while (scelta != 6);

    return 0;
}
