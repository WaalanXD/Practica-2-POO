#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "AlgoritmoOrdenamiento.h"

using namespace std;

class InsertionSort : public AlgoritmoOrdenamiento {
public:
    explicit InsertionSort(const vector<int>& datos);
    ~InsertionSort();
    
    void reiniciar(const vector<int>& datos) override;
    void paso() override;
    string nombre() const override { return "Insertion Sort"; }

private:
    int m_valorActual;   // El valor que estamos insertando
    bool m_insertando;   // Si estamos moviendo elementos
};

#endif