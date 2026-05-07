#ifndef MERGESORT_H
#define MERGESORT_H

#include "AlgoritmoOrdenamiento.h"
#include <stack>

using namespace std;

class MergeSort : public AlgoritmoOrdenamiento {
public:
    MergeSort(const vector<int>& datos);
    ~MergeSort();
    
    void reiniciar(const vector<int>& datos) override;
    void paso() override;
    string nombre() const override;

private:
    // Estructura para una tarea pendiente
    struct Tarea {
        int izq;
        int der;
        bool esMerge;
    };

    stack<Tarea> m_tareas;    // Pila de tareas pendientes
    vector<int> m_temp;       // Vector auxiliar para mezclar

    // Estado del merge actual
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