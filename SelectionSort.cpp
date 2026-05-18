#include "SelectionSort.h"


SelectionSort::SelectionSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_indiceMinimo = 0;
    m_i = 0;
    m_j = 1;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}


SelectionSort::~SelectionSort() {
    
}


void SelectionSort::reiniciar(const vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_indiceMinimo = 0;
    m_i = 0;
    m_j = 1;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}


void SelectionSort::paso() {
    if (m_terminado) {
        return;
    }

    
    m_comparaciones++;

    
    if (m_datos[m_j] < m_datos[m_indiceMinimo]) {
        m_indiceMinimo = m_j;
    }

    m_j++;

    
    if (m_j >= (int)m_datos.size()) {
        
        if (m_indiceMinimo != m_i) {
            
            int temp = m_datos[m_i];
            m_datos[m_i] = m_datos[m_indiceMinimo];
            m_datos[m_indiceMinimo] = temp;
            
            m_intercambios++;
        }

        
        m_i++;
        m_indiceMinimo = m_i;
        m_j = m_i + 1;

        if (m_i >= (int)m_datos.size() - 1) {
            m_terminado = true;
        }
    }
}