#ifndef MERGESORT_H
#define MERGESORT_H

#include "AlgoritmoOrdenamiento.h"
#include <stack>

using namespace std;

class MergeSort : public AlgoritmoOrdenamiento {
public:
    explicit MergeSort(const vector<int>& datos);
    ~MergeSort();
    
    void reiniciar(const vector<int>& datos) override;
    void paso() override;
    string nombre() const override { return "Merge Sort"; }

private:
    
    struct Tarea {
        int izq;
        int der;
        bool esMerge;
    };

    stack<Tarea> m_tareas;    
    vector<int> m_temp;       

    
    int m_mergeIzq;
    int m_mergeMid;
    int m_mergeDer;
    int m_mergeI;
    int m_mergeJ;
    int m_mergeK;
    bool m_enMerge;

    void inicializarTareas();
};

#endif