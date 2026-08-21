#ifndef SOLUTION_B_H
#define SOLUTION_B_H

#include <string>
using namespace std;

int findProduct(string* productNames, int productCount, string name);
void addProduct(string*& productNames, double*& productPrices, int*& productStock, int& productCount, string name, double price, int qty);
void updateStock(int* productStock, int index, int newQty);
void priceMinMax(double* productPrices, int productCount, double* minPrice, double* maxPrice);
void salesMatrix(int productCount);
void showInventory(string* productNames, double* productPrices, int* productStock, int productCount);
void freeAll(string* productNames, double* productPrices, int* productStock);
void runInventoryMenu();

#endif