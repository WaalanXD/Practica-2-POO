#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "AlgoritmoOrdenamiento.h"
#include <stack>

using namespace std;

class QuickSort : public AlgoritmoOrdenamiento {
public:
    explicit QuickSort(const vector<int>& datos);
    ~QuickSort();
    
    void reiniciar(const vector<int>& datos) override;
    void paso() override;
    string nombre() const override { return "Quick Sort"; }

private:
    // Estructura para un rango a ordenar
    struct Rango {
        int izq;
        int der;
    };

    stack<Rango> m_rangos;  // Pila de rangos pendientes

    // Estado de la particion actual
    int m_partIzq;
    int m_partDer;
    int m_pivote;
    int m_indicePart;
    bool m_enParticion;

    void inicializarRangos();
};

#endif