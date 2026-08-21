#include "SolutionB.h"
#include <iostream>

using namespace std;

int findProduct(string* productNames, int productCount, string name) {
    for (int i = 0; i < productCount; i++) {
        if (productNames[i] == name) {
            return i;
        }
    }
    return -1;
}

void addProduct(string*& productNames, double*& productPrices, int*& productStock, int& productCount, string name, double price, int qty) {
    string* newNames = new string[productCount + 1];
    double* newPrices = new double[productCount + 1];
    int* newStock = new int[productCount + 1];

    for (int i = 0; i < productCount; i++) {
        newNames[i] = productNames[i];
        newPrices[i] = productPrices[i];
        newStock[i] = productStock[i];
    }

    newNames[productCount] = name;
    newPrices[productCount] = price;
    newStock[productCount] = qty;

    delete[] productNames;
    delete[] productPrices;
    delete[] productStock;

    productNames = newNames;
    productPrices = newPrices;
    productStock = newStock;
    productCount = productCount + 1;
}

void updateStock(int* productStock, int index, int newQty) {
    if (index >= 0) {
        productStock[index] = newQty;
    }
}

void priceMinMax(double* productPrices, int productCount, double* minPrice, double* maxPrice) {
    if (productCount <= 0) {
        return;
    }
    *minPrice = productPrices[0];
    *maxPrice = productPrices[0];
    for (int i = 1; i < productCount; i++) {
        if (productPrices[i] < *minPrice) {
            *minPrice = productPrices[i];
        }
        if (productPrices[i] > *maxPrice) {
            *maxPrice = productPrices[i];
        }
    }
}

void showInventory(string* productNames, double* productPrices, int* productStock, int productCount) {
    cout << endl << "INVENTARIO" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "Nombre: " << productNames[i] << " | Precio: " << productPrices[i] << " | Stock: " << productStock[i] << endl;
    }
}

void salesMatrix(int productCount) {
    if (productCount <= 0) {
        cout << endl << "No hay productos registrados." << endl;
        return;
    }

    int sales[7][10] = {
        {1, 2, 3, 0, 1, 2, 0, 1, 0, 2},
        {2, 1, 0, 1, 2, 1, 1, 0, 2, 1},
        {0, 1, 2, 2, 0, 1, 2, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 2, 1, 0},
        {2, 2, 0, 1, 2, 1, 0, 1, 2, 1},
        {1, 1, 2, 0, 1, 2, 1, 0, 1, 2},
        {0, 2, 1, 2, 0, 1, 2, 1, 0, 1}
    };

    cout << endl << "VENTAS POR DIA" << endl;
    for (int i = 0; i < 7; i++) {
        int totalDia = 0;
        cout << "Dia " << i + 1 << ": ";
        for (int j = 0; j < productCount; j++) {
            cout << sales[i][j] << " ";
            totalDia = totalDia + sales[i][j];
        }
        cout << " Total: " << totalDia << endl;
    }

    cout << endl << "TOTAL POR PRODUCTO" << endl;
    for (int j = 0; j < productCount; j++) {
        int totalProducto = 0;
        for (int i = 0; i < 7; i++) {
            totalProducto = totalProducto + sales[i][j];
        }
        cout << "Producto " << j + 1 << ": " << totalProducto << endl;
    }
}

void freeAll(string* productNames, double* productPrices, int* productStock) {
    delete[] productNames;
    delete[] productPrices;
    delete[] productStock;
}

void runInventoryMenu() {
    string* productNames = nullptr;
    double* productPrices = nullptr;
    int* productStock = nullptr;
    int productCount = 0;

    int opcion = 0;
    while (opcion != 7) {
        cout << endl << "MENU DE INVENTARIO" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Buscar producto" << endl;
        cout << "3. Actualizar stock" << endl;
        cout << "4. Precio minimo y maximo" << endl;
        cout << "5. Mostrar inventario" << endl;
        cout << "6. Matriz de ventas" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre;
            double precio;
            int cantidad;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Precio: ";
            cin >> precio;
            cout << "Cantidad: ";
            cin >> cantidad;
            addProduct(productNames, productPrices, productStock, productCount, nombre, precio, cantidad);
            cout << "Producto agregado." << endl;
        }
        else if (opcion == 2) {
            string nombre;
            cout << "Nombre a buscar: ";
            cin >> nombre;
            int posicion = findProduct(productNames, productCount, nombre);
            if (posicion != -1) {
                cout << "Encontrado en la posicion: " << posicion << endl;
            }
            else {
                cout << "No existe ese producto." << endl;
            }
        }
        else if (opcion == 3) {
            string nombre;
            cout << "Nombre del producto: ";
            cin >> nombre;
            int posicion = findProduct(productNames, productCount, nombre);
            if (posicion != -1) {
                int nuevaCantidad;
                cout << "Nuevo stock: ";
                cin >> nuevaCantidad;
                updateStock(productStock, posicion, nuevaCantidad);
                cout << "Stock actualizado." << endl;
            }
            else {
                cout << "No existe ese producto." << endl;
            }
        }
        else if (opcion == 4) {
            if (productCount > 0) {
                double minP = 0;
                double maxP = 0;
                priceMinMax(productPrices, productCount, &minP, &maxP);
                cout << "Precio minimo: " << minP << endl;
                cout << "Precio maximo: " << maxP << endl;
            }
            else {
                cout << "No hay productos en la lista." << endl;
            }
        }
        else if (opcion == 5) {
            showInventory(productNames, productPrices, productStock, productCount);
        }
        else if (opcion == 6) {
            salesMatrix(productCount);
        }
    }

    freeAll(productNames, productPrices, productStock);
    cout << "Saliendo del programa..." << endl;
}