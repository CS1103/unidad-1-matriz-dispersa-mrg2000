#include "Sparse.h"
#include "Definiciones.h"
#include "Elemento.h"

#include <iostream>

using namespace std;


Sparse::Sparse(TipoEntero _noZeros, TipoEntero _numFilas, TipoEntero _numColumnas) {
    noZeros = _noZeros;
    numFilas = _numFilas;
    numColumnas = _numColumnas;
    elemento = new Elemento[noZeros];
}

Sparse::~Sparse() {
    delete [] elemento;
}

istream &operator>>(istream &is, Sparse &matriz) {
    //cout << "Ingrese el número de elementos diferentes de 0: ";
    cout << "Ingrese fila/columna/valor y presiones ENTER: \n";

    for(TipoEntero i=0;i<matriz.noZeros;i++){
        cin>>matriz.elemento[i].fila;
        cin>>matriz.elemento[i].columna;
        cin>>matriz.elemento[i].valor;
    }

    return is;
}


ostream &operator<<(ostream &os, Sparse &matriz) {

    TipoEntero nz =0; //Cuenta los elementos NoZero impresos
    for(TipoEntero i=0;i<matriz.numFilas;i++){
        for(TipoEntero j=0;j<matriz.numColumnas;j++){
            if(matriz.elemento[nz].fila==i && matriz.elemento[nz].columna==j){
                cout << matriz.elemento[nz++].valor << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return os;

}

Sparse Sparse::operator+(Sparse &matrizASumar) {
    TipoEntero a =0; //Contador elementos diferentes de 0 de la matriz 1
    TipoEntero b =0; //Contador elementos diferentes de 0 de la matriz 2
    TipoEntero c = 0; //Contador elementos diferentes de 0 de la matriz resultado

    if(numFilas != matrizASumar.numFilas || numColumnas != matrizASumar.numColumnas) //Se comprueba que se pueden sumar ambas matrices
        return matrizASumar;

    Sparse* matrizResultadoSuma = new Sparse(noZeros+matrizASumar.noZeros,numFilas,numColumnas); // Sumamos la cantidad de noZeros de ambas matrices









    return *matrizResultadoSuma;
}
