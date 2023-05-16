#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
using namespace std;

void cadastro(int [], int [], int);
float calculaMediaAritmetica(int [], int);
void calculaFrequencias (int [], int [], int, int);
void calculaModa (int[], int[], int, int);
void imprimeVetor (int [], int);

int main(){
    setlocale(LC_ALL, "Portuguese");
    cout << setiosflags (ios:: fixed| ios:: showpoint) << setprecision(2);
    const int tam= 90;
    int automoveis[tam], motocicletas[tam];
    int frequenciaA[348] = {0};
    int frequenciaM[126] = {0};
    float mediaA, mediaM;

    cadastro(automoveis, motocicletas, tam);

    cout << "=============RESULTADOS AUTOMÓVEIS============" << endl;
    cout << "\nVetor automoveis: " << endl;
    imprimeVetor(automoveis, tam);
    mediaA = calculaMediaAritmetica(automoveis, tam);
    cout << "\nMédia: " << mediaA;
    calculaModa(automoveis, frequenciaA, tam, 348);
    cout << endl;

    cout << "============RESULTADOS MOTOCICLETAS==============" << endl;
    cout << "\nVetor motocicletas: " << endl;
    imprimeVetor(motocicletas, tam);
    mediaM = calculaMediaAritmetica(motocicletas, tam);
    cout << "\nMédia: " << mediaM;
    calculaModa(motocicletas, frequenciaM, tam, 126);
    cout << endl;

    return 0;
}

void cadastro(int A[], int M[], int t){

    cout << "Digite os dados coletados por dia referentes a AUTOMÓVEIS: " << endl;
    for (int i=0; i<t; i++){
        cin >> A[i];
    }
    cout << "\nDigite os dados coletados por dia referentes a MOTOCICLETAS: " << endl;
    for (int i=0; i<t; i++){
        cin >> M[i];
    }
}

float calculaMediaAritmetica(int A[], int t){
    float somatorio =0;
    for (int i=0; i<t; i++){
        somatorio = somatorio + A[i];
    }
    return (somatorio/(t));
}

void calculaFrequencias (int V[], int f[], int tV, int tF){  // tV= tamanho V, tF = tamanho F
    int pos; // pos = posição
    for (int i=0; i<tV; i++){
        pos = V[i];
        for (int i1=0; i1<tF; i1++){
            if (i1 == pos){
                f[i1] = f[i1] + 1;
            }
        }
    }
}

void calculaModa (int V[], int f[], int tV, int tF){
    calculaFrequencias(V, f, tV, tF);
    int moda = f[0], posmoda = 0, qtdmodas = 0;
    cout << "\nFrequência: " << endl;
    for (int i=0; i<tF; i++){
        cout << setw(4) << f[i];
        if (f[i] > moda){
            moda = i;
            posmoda = f[i];
        }
        if (f[i] == moda){
            qtdmodas ++;
        }
    }

    if (qtdmodas==tF-1){
        cout << "O conjunto não apresenta moda. " << endl;
    } else{
        cout << "\nModa: " << moda << " e f[" << moda << "]: " << posmoda << endl;
    }
}

void imprimeVetor (int V[], int tam){
    for (int i=0; i<tam; i++){
        cout << setw(4) << V[i] ;
    }
}
