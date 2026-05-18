#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "AlgoritmoOrdenamiento.h"

using namespace std;

class BubbleSort : public AlgoritmoOrdenamiento {
public:
    explicit BubbleSort(const vector<int>& datos);
    ~BubbleSort();
    
    void reiniciar(const vector<int>& datos) override;
    void paso() override;
    string nombre() const override { return "Bubble Sort"; }

private:
    bool m_huboSwap;  
    int m_limite;     
};

#endif