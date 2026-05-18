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
    int m_valorActual;   
    bool m_insertando;   
};

#endif