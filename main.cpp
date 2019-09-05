#include <iostream>
#include "Sparse.h"
#include "Elemento.h"
#include "Definiciones.h"

using namespace std;

int main() {

    Sparse ms1(2,3,5); //(NoZeroElements,filas,columnas)
    Sparse ms2(2,5,3);

    cin >> ms1;
    cin >> ms2;

    //cout << "\n\n" << ms1 << endl;

    cout << "\n\n";

    Sparse ms3 = ms1*ms2;

    cout << ms3 << endl;






    return 0;
}