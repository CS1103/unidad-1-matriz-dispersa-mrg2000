#ifndef ESTRUCTURA_MYMATRIZ_MATRIZ_H
#define ESTRUCTURA_MYMATRIZ_MATRIZ_H

#include "Definiciones.h"
#include "Elemento.h"
#include <iostream>
using namespace std;


//Objetivo 1: Reducir los requerimientos de memoria, es decir, los elementos 0 no almacenarlos
//Objetivo 2: Reducri el costo aritmetico de cada operacion
// Objetivo 3: Se busca su eficiencia en cuanto al acceso secuencial a la matriz
// Ventaja 1: COO (Coordinate) --> Acceso secuencial eficiente
// Ventaja 2: CSR (Compressed sparse row) --> Se alamacenan de forma implicita los indices de fila



class Sparse {
private:
    Elemento* elemento;  //Vector con elementos que contienen coordenadaFila, coordenadaColumna y valor
    TipoEntero noZeros;
    TipoEntero numFilas;
    TipoEntero numColumnas;


public:
    //Sparse();
    Sparse(TipoEntero _noZeros,TipoEntero _numFilas, TipoEntero _numColumnas);
    ~Sparse();

    //Sobrecargar operadores para leer e imprimir datos
    friend istream &operator>>(istream &is, Sparse &matriz); // Leer
    friend ostream &operator<<(ostream &os, Sparse &matriz); // Imprimir

    //Sobrecargar operadores para realizar operaciones
    Sparse operator+(Sparse &matriz);
    Sparse operator*(Sparse &matrizAMultiplicar);
    Sparse operator*(TipoNumerico escalar);
    Sparse Transpos();


};


#endif //ESTRUCTURA_MYMATRIZ_MATRIZ_H
