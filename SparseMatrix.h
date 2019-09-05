//
// Created by Ivan Mamani on 29/08/2019.
//

#ifndef MATRIZDISPERSA_SPARSEMATRIX_H
#define MATRIZDISPERSA_SPARSEMATRIX_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class SparseMatrix {

    using TipoMatriz = int;

    TipoMatriz **matriz;
    unsigned int filas;
    unsigned int columnas;
    unsigned int sizeSM;

public:
     SparseMatrix();
    SparseMatrix(unsigned int, unsigned int);
    virtual ~SparseMatrix();
    void pedirEspacio();
    void llenar();
    void mostrar();
    SparseMatrix operator+(const SparseMatrix &otro);
    SparseMatrix operator*(const SparseMatrix &otro);


};


#endif //MATRIZDISPERSA_SPARSEMATRIX_H
