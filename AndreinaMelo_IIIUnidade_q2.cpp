#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    cout << setiosflags (ios:: fixed| ios:: showpoint) << setprecision(2);
    float pontuacao[1000][4];
    int flag=1, qtd=0;

    cout << "Digite as pontuações por candidato (0 p/ encerrar)." << endl << endl;
    do {
        for (int i=0; i<1000; i++){
            cout << "Candidato " << i+1 << endl;
            for (int j=0; j<4; j++){
                if (j==0){
                    cout << "C. Exatas: ";
                    cin >> pontuacao[i][0];
                    if (pontuacao[i][0] == 0){
                        flag = 0;
                        break;
                    }
                }
                if (j==1){
                    cout << "C. Naturais: ";
                    cin >> pontuacao[i][1];
                }
                if (j==2){
                    cout << "C. Humanas: ";
                    cin >> pontuacao[i][2];
                }
                if (j==3){
                    cout << "C. e Expressão: ";
                    cin >> pontuacao[i][3];
                }
            }
            cout << endl;
            if (flag == 0){
                break;
            }
            qtd++;
        }
    } while (flag!=0);

    float mediaponderada[qtd];
    for (int i=0; i< qtd; i++){
        mediaponderada[i] = (pontuacao[i][0]*5 + pontuacao[i][1]*2 + pontuacao[i][2]*2 + pontuacao[i][3]*3)/12;
    }

    cout  << "\n Inscrição | C. Exatas  | C. Humanas | C. Naturais | C. e Expressão | Média " << endl;
    for (int i=0; i< qtd; i++){
        cout << setw(6) << i+1;
        for (int j=0; j<4; j++){
            cout << setw(14) << pontuacao[i][j];
        }
        cout << setw(12) << mediaponderada[i];
        cout << endl;
    }

    return 0;
}
