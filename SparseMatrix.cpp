//
// Created by Ivan Mamani on 29/08/2019.
//
#include "SparseMatrix.h"
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
#include "SparseMatrix.h"
