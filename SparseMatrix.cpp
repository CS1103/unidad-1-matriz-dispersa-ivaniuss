//
// Created by Ivan Mamani on 29/08/2019.
//

#include "SparseMatrix.h"
#include <iostream>

/*

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
*/

SparseMatrix::SparseMatrix() {
    matriz = nullptr;
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


}

SparseMatrix SparseMatrix::operator+(const SparseMatrix &otro) {
    unsigned int rangoMa = 0, rangoMe = 0;
    SparseMatrix temporal1(3,sizeSM);
    SparseMatrix temporal2(3,otro.sizeSM);
    temporal1.pedirEspacio();
    temporal2.pedirEspacio();

    if(sizeSM > otro.sizeSM){
        rangoMa = sizeSM;
        rangoMe = otro.sizeSM;

    }
        else{

        rangoMa = otro.sizeSM;
        rangoMe = sizeSM;

    }
    SparseMatrix temporal3(3,rangoMa);
    temporal3.pedirEspacio();

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


    int m = 0;
    for (int i = 0; i < otro.filas; i++)
        for (int j = 0; j < otro.columnas; j++)
            if (otro.matriz[i][j] != 0)
            {
                temporal2.matriz[0][m] = i;
                temporal2.matriz[1][m] = j;
                temporal2.matriz[2][m] = otro.matriz[i][j];
                m++;
            }
     for (int i=0; i<3; i++){
        for (int j=0; j<otro.sizeSM; j++){
            cout << temporal2.matriz[i][j] << " ";
        }
        cout <<"\n";
    }
/*
int n = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < otro.columnas; j++)
            while (temporal1.matriz[i][j] < temporal2.matriz[i][j])
           // temp
            {
                temporal3.matriz[0][m] = i;
                temporal3.matriz[1][m] = j;
                temporal3.matriz[2][m] = otro.matriz[i][j];
                n++;
            }
*/



int n= 0;
    for(int i = 0; i < rangoMa; i++){
        if (temporal1.matriz[0][i] < temporal2.matriz[0][n] || n == rangoMe){
            temporal3.matriz[0][i] = temporal1.matriz[0][i];
            temporal3.matriz[1][i] = temporal1.matriz[1][i];
            temporal3.matriz[2][i] = temporal1.matriz[2][i];
        }



        else if (temporal1.matriz[0][i] == temporal2.matriz[0][n]){
                if(temporal1.matriz[1][i] < temporal2.matriz[1][n]){
                    temporal3.matriz[0][i] = temporal1.matriz[0][i];
                    temporal3.matriz[1][i] = temporal1.matriz[1][i];
                    temporal3.matriz[2][i] = temporal1.matriz[2][i];
                }
                    else if ((temporal1.matriz[1][i] == temporal2.matriz[1][n])){
                    temporal3.matriz[0][i] = temporal1.matriz[0][i];
                    temporal3.matriz[1][i] = temporal1.matriz[1][i];
                    temporal3.matriz[2][i] = temporal1.matriz[2][i]+temporal2.matriz[2][n];
                    if(n<rangoMe)
                        n++;
                }
                    else{
                    temporal3.matriz[0][i] = temporal2.matriz[0][n];
                    temporal3.matriz[1][i] = temporal2.matriz[1][n];
                    temporal3.matriz[2][i] = temporal2.matriz[2][n];
                    if(n<rangoMe)
                        n++;
                }
                    }

        else{

            temporal3.matriz[0][i] = temporal2.matriz[0][n];
            temporal3.matriz[1][i] = temporal2.matriz[1][n];
            temporal3.matriz[2][i] = temporal2.matriz[2][n];
            if(n<rangoMe)
                n++;
        }}



    for (int i=0; i<rangoMa; i++){
        for (int j=0; j<rangoMa; j++){
            cout << temporal3.matriz[i][j] << " ";
        }

        cout <<"\n";
            }

}

SparseMatrix SparseMatrix::operator *(const SparseMatrix &otro) {
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

    for (int i = 0; i < temporal1.filas; i++)
      for (int j = 0; j < sizeSM; j++)
        temporal1.matriz[i] = temporal1.matriz[i] + temporal1.matriz[2][i] *temporal1.matriz[1][j] ;
}
