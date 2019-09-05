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

    TipoEntero i,j,k;

    if(numFilas != matrizASumar.numFilas || numColumnas != matrizASumar.numColumnas) //Se comprueba que se pueden sumar ambas matrices
        return matrizASumar;

    Sparse *matrizResultado=new Sparse(noZeros+matrizASumar.noZeros,numFilas, numColumnas);

    i=j=k=0;

    while(i<noZeros && j<matrizASumar.noZeros){
        //Filas
        if(elemento[i].fila<matrizASumar.elemento[j].fila)
            matrizResultado->elemento[k++]=elemento[i++];
        else if(elemento[i].fila>matrizASumar.elemento[j].fila)
            matrizResultado->elemento[k++]=elemento[j++];
        //Columnas
        else{
            if(elemento[i].columna<elemento[j].columna)
                matrizResultado->elemento[k++]=elemento[i++];

            else if(elemento[i].columna>matrizASumar.elemento[j].columna)
                matrizResultado->elemento[k++]=elemento[j++];

            else{
                matrizResultado->elemento[k]=elemento[i];
                matrizResultado->elemento[k++].valor=elemento[i++].valor+matrizASumar.elemento[j++].valor;
            }
        }
    }
    for(;i<noZeros;i++)matrizResultado->elemento[k++]=elemento[i];
    for(;j<matrizASumar.noZeros;j++)matrizResultado->elemento[k++]=matrizASumar.elemento[j];
    matrizResultado->noZeros=k;

    return *matrizResultado;

}



Sparse Sparse::operator*(Sparse &matrizAMultiplicar) {





}


Sparse Sparse::operator*(TipoNumerico escalar) {

    Sparse* matrizResultado = new Sparse(noZeros,numFilas,numColumnas);

    for(TipoEntero i=0;i<noZeros;i++){
        matrizResultado->elemento[i].fila=elemento[i].fila;
        matrizResultado->elemento[i].columna=elemento[i].columna;
        matrizResultado->elemento[i].valor=elemento[i].valor*escalar;
    }


    return *matrizResultado;
}



Sparse Sparse::Transpos() {

    Sparse* matrizResultado = new Sparse(noZeros,numColumnas,numFilas);


    for(TipoEntero i=0;i<noZeros;i++) {
        matrizResultado->elemento[i].fila = elemento[i].columna;
        matrizResultado->elemento[i].columna = elemento[i].fila;
        matrizResultado->elemento[i].valor = elemento[i].valor;
    }



    return *matrizResultado;
}


