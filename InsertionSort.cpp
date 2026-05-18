#include "InsertionSort.h"


InsertionSort::InsertionSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_valorActual = 0;
    m_insertando = false;
    m_i = 1;  
    m_j = 0;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}


InsertionSort::~InsertionSort() {
    
}


void InsertionSort::reiniciar(const vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_valorActual = 0;
    m_insertando = false;
    m_i = 1;
    m_j = 0;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}


void InsertionSort::paso() {
    if (m_terminado) {
        return;
    }

    
    if (!m_insertando) {
        m_valorActual = m_datos[m_i];
        m_j = m_i - 1;
        m_insertando = true;
    }

    
    m_comparaciones++;

    if (m_j >= 0 && m_datos[m_j] > m_valorActual) {
        
        m_datos[m_j + 1] = m_datos[m_j];
        m_intercambios++;
        m_j--;
    } else {
        
        m_datos[m_j + 1] = m_valorActual;
        m_insertando = false;
        m_i++;

        if (m_i >= (int)m_datos.size()) {
            m_terminado = true;
        }
    }
}