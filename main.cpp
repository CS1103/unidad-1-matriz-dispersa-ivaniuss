#include <iostream>
#include <ctime>
#include "SparseMatrix.h"

int main() {
    /*
    using namespace std;

    unsigned  int f1,c1,f2,c2,f3,c3;
    int **pM1 = nullptr, **pM2 = nullptr,**pM3 = nullptr;

    srand(time(nullptr));

    cout << "Numero de filas de la primera matriz: ";
    cin >> f1;
    cout << "Numero de columnas de la primera matriz: ";
    cin >> c1;
    cout << "Numero de filas de la segunda matriz: ";
    cin >> f2;
    cout << "Numero de columnas de la segunda matriz: ";
    cin >> c2;

    if(c1!=f2){
        cout<< "no es posible multiplicar las matrices";
        return 1;
    }

    PideEspacio(pM1, f1, c1);
    PideEspacio(pM2, f2, c2);
    LlenarMatriz(pM1, f1, c1);
    LlenarMatriz(pM2, f2, c2);
    cout<<"\n\nPrimera matriz\n";
    ImprimirMatriz(pM1,f1,c1);
    cout<<"\n\nSegunda matriz\n";
    ImprimirMatriz(pM2,f2,c2);
    cout<<"\n\nMultiplicacion de matrices\n";
    PideEspacio(pM3,f3,c3);
    f3=f1;
    c3=c2;
    multiplicarMatriz(pM1,pM2,pM3,f1,f2,c1,c2,f3,c3);
    ImprimirMatriz(pM3,f3,c3);
    EliminarMatriz(pM1, f1);
    EliminarMatriz(pM2,f2);
    EliminarMatriz(pM3,f3);
*/
    SparseMatrix matriz1(2,2);

    matriz1.pedirEspacio();

    matriz1.llenar();

    matriz1.mostrar();


    SparseMatrix matriz2(2,2);

    matriz2.pedirEspacio();

    matriz2.llenar();

    matriz2.mostrar();


    matriz1+matriz2;
    return 0;


}