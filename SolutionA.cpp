#include "SolutionA.h"
#include <iostream>

using namespace std;

int countGreaterThan(int* array, int size, int limit) {
    int contador = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > limit) {
            contador++;
        }
    }
    return contador;
}

double average(int* array, int size) {
    if (size == 0) {
        return 0.0;
    }
    double suma = 0.0;
    for (int i = 0; i < size; i++) {
        suma = suma + array[i];
    }
    return suma / size;
}

void sumByRow(int matrix[3][4], int result[3]) {
    for (int i = 0; i < 3; i++) {
        int sumaFila = 0;
        for (int j = 0; j < 4; j++) {
            sumaFila = sumaFila + matrix[i][j];
        }
        result[i] = sumaFila;
    }
}

int countValue(int matrix[3][4], int value) {
    int contador = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == value) {
                contador++;
            }
        }
    }
    return contador;
}

void findMinMax(int* array, int size, int* minResult, int* maxResult) {
    if (size <= 0) {
        return;
    }
    *minResult = array[0];
    *maxResult = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < *minResult) {
            *minResult = array[i];
        }
        if (array[i] > *maxResult) {
            *maxResult = array[i];
        }
    }
}

void doubleValue(int& value) {
    value = value * 2;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int* resizeArray(int* oldArray, int oldSize, int newSize) {
    int* newArray = new int[newSize];
    for (int i = 0; i < oldSize; i++) {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray;
    return newArray;
}

void fillAndPrintFixed(int count) {
    int* values = new int[count];
    for (int i = 0; i < count; i++) {
        values[i] = i;
    }
    for (int i = 0; i < count; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    delete[] values;
}