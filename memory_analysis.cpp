#include "MemoryAnalysis.h"

#include <iostream>
#include <vector>

#include "AlgoritmoOrdenamiento.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

void MemoryAnalysis::run() {
    cout << "=== Tipos que usa el algoritmo ===" << endl;
    cout << "int              : " << sizeof(int) << " bytes" << endl;
    cout << "bool             : " << sizeof(bool) << " bytes" << endl;
    cout << "vector<int>      : " << sizeof(vector<int>) << " bytes" << endl;
    cout << "puntero (void*)  : " << sizeof(void*) << " bytes" << endl;

    cout << "\n=== Tamano de los objetos ===" << endl;
    cout << "sizeof(AlgoritmoOrdenamiento) : " << sizeof(AlgoritmoOrdenamiento) << " bytes" << endl;
    cout << "sizeof(BubbleSort)            : " << sizeof(BubbleSort) << " bytes" << endl;
    cout << "sizeof(InsertionSort)         : " << sizeof(InsertionSort) << " bytes" << endl;
    cout << "sizeof(SelectionSort)         : " << sizeof(SelectionSort) << " bytes" << endl;
    cout << "sizeof(MergeSort)             : " << sizeof(MergeSort) << " bytes" << endl;
    cout << "sizeof(QuickSort)             : " << sizeof(QuickSort) << " bytes" << endl;

    int suma = (int)(sizeof(void*) + sizeof(vector<int>) + sizeof(bool)
        + sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int));
    cout << "\n=== Analisis de padding ===" << endl;
    cout << "Suma de atributos (sin padding) : " << suma << " bytes" << endl;
    cout << "sizeof(AlgoritmoOrdenamiento)   : " << sizeof(AlgoritmoOrdenamiento) << " bytes" << endl;
    cout << "Diferencia por padding          : " << (int)sizeof(AlgoritmoOrdenamiento) - suma << " bytes" << endl;

    cout << "\n=== Stack vs Heap ===" << endl;
    vector<int> datos = { 5, 3, 8, 1, 9, 2, 7, 4, 6 };
    BubbleSort a1(datos);
    AlgoritmoOrdenamiento* a2 = new BubbleSort(datos);
    cout << "Direccion a1 (stack): " << &a1 << endl;
    cout << "Direccion a2 (heap) : " << a2 << endl;

    cout << "\n=== Memoria del arreglo interno ===" << endl;
    cout << "Elementos                : " << a1.tamano() << endl;
    cout << "sizeof(vector<int>)      : " << sizeof(vector<int>) << " bytes" << endl;
    cout << "Datos reales en heap     : " << a1.tamano() * sizeof(int) << " bytes" << endl;

    delete a2;
}