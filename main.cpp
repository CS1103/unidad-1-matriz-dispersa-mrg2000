#include <iostream>
#include "Sparse.h"
#include "Elemento.h"
#include "Definiciones.h"

using namespace std;

int main() {

    Sparse ms1(2,10,10); //(NoZeroElements,filas,columnas)
    //Sparse ms2(3,3,3);

    cin >> ms1;
    //cin >> ms2;

    //Sparse suma = ms1+ms2;


    cout << "\n\n" << ms1 << endl;
    //cout << "ms2\n" << ms2 << endl;
    //cout << "Suma\n" << suma << endl;











    return 0;
}