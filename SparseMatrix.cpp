//
// Created by Ivan Mamani on 29/08/2019.
//

/*
 * #include "SparseMatrix.h"
void PideEspacio(int **&pM, unsigned int f,unsigned int c){
    pM = new int *[f];
    for(unsigned int i = 0; i < f; i++)
        pM[i] = new int [c];

}

void LlenarMatriz(int **pM,unsigned int f,unsigned int c){
    for(unsigned int contf = 0; contf < f; contf++)
        for(unsigned int contc = 0; contc < c; contc++)
            pM[contf][contc] = rand()%100;
}

void ImprimirMatriz(int **pM,unsigned int f,unsigned int c){
    for(unsigned int contf = 0; contf < f; contf++){
        for(unsigned int contc = 0; contc < c; contc++)
            cout <<setw(7)<< pM[contf][contc];
        cout << endl;

    }
}
void multiplicarMatriz(int **pM1,int **pM2,int **pM3,unsigned int f1,unsigned int c1,unsigned int f2,unsigned int c2,unsigned int f3,unsigned int c3){

    for (int i = 0; i < f3; i++){
        for (int j = 0; j < c3; j++){
            pM3[i][j] = 0;
            for(int k = 0; k < f3; k++){
                pM3[i][j]+= pM1[i][k] * pM2[k][j];
            }
        }
    }
}

void EliminarMatriz(int **&pM,unsigned int f){
    for (unsigned int i = 0; i < f; i++){
        delete []pM[i];
        delete []pM;
        pM = nullptr;
    }
}
 */
#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix() {
    matriz = nullptr;
    matriztemp1 = nullptr;
    matriztemp2 = nullptr;
    filas = 0;
    columnas = 0;
    sizeSM = 0;
}

SparseMatrix::SparseMatrix(unsigned int filas, unsigned int columnas) {
    sizeSM = 0;
    this -> filas  = filas;
    this -> columnas = columnas;

//    pedirEspacio(matriz, filas, columnas);

}

SparseMatrix::~SparseMatrix() {
    for (unsigned int i = 0; i < filas; i++){
        delete []matriz[i];
        delete []matriz;
        matriz = nullptr;
    }
}
void SparseMatrix::pedirEspacio() {
    matriz = new int*[filas];
    for (unsigned int i = 0; i < filas; i++)
        matriz[i] = new int[columnas];

}

void SparseMatrix::llenar() {

    for(unsigned int i = 0; i < filas; i++){
        for(unsigned int j = 0; j < columnas; j++)
            cin >> matriz[i][j];
    }

    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            if (matriz[i][j] != 0)
                sizeSM++;
        }
    }

}

void SparseMatrix::mostrar() {

    for(unsigned int i = 0; i < filas; i++){
        for(unsigned int j = 0; j < columnas; j++){
            cout << matriz[i][j] << " ";
        }
            cout << "\n";
    }

    cout << sizeSM << "\n";
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix &otro) {
    SparseMatrix temporal1(3,sizeSM);
    SparseMatrix temporal2(3,otro.sizeSM);
    temporal1.pedirEspacio();
    temporal2.pedirEspacio();

        int k = 0;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (matriz[i][j] != 0)
            {
                temporal1.matriz[0][k] = i;
                temporal1.matriz[1][k] = j;
                temporal1.matriz[2][k] = matriz[i][j];
                k++;
            }
    for (int i=0; i<3; i++){
        for (int j=0; j<sizeSM; j++){
            cout << temporal1.matriz[i][j] << " ";
        }
        cout <<"\n";
    }

}


SparseMatrix SparseMatrix::operator *(const SparseMatrix &otro) {


}
