#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "AlgoritmoOrdenamiento.h"

using namespace std;

class SelectionSort : public AlgoritmoOrdenamiento {
public:
    explicit SelectionSort(const vector<int>& datos);
    ~SelectionSort();
    
    void reiniciar(const vector<int>& datos) override;
    void paso() override;
    string nombre() const override;

private:
    int m_indiceMinimo;  // Indice del minimo encontrado
};

#endif