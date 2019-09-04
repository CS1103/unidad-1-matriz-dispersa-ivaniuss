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
void PideEspacio(int **&pM, unsigned int f1,unsigned int c1);
void LlenarMatriz(int **pM,unsigned int f,unsigned int c);
void ImprimirMatriz(int **pM,unsigned int f,unsigned int c);
void multiplicarMatriz(int **pM1,int **pM2,int **pM3,unsigned int f1,unsigned int c1,unsigned int f2,unsigned int c2,unsigned int f3,unsigned int c3);
void EliminarMatriz(int **&pM,unsigned int f);

class SparseMatrix {

    using TipoMatriz = int;

    TipoMatriz **matriz;
    unsigned int filas;
    unsigned int columnas;

public:
    SparseMatrix();
    SparseMatrix(int, int);
    virtual ~SparseMatrix();

    void pedirEspacio();
    void llenar();
    void mostrar();
    SparseMatrix operator+(const SparseMatrix &otro);
    SparseMatrix operator*(const SparseMatrix &otro);


};


#endif //MATRIZDISPERSA_SPARSEMATRIX_H
