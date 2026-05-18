#include "BubbleSort.h"


BubbleSort::BubbleSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_huboSwap = false;
    m_limite = (int)m_datos.size() - 1;
    
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}


BubbleSort::~BubbleSort() {
    
}


void BubbleSort::reiniciar(const vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_huboSwap = false;
    m_limite = (int)m_datos.size() - 1;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}


void BubbleSort::paso() {
    
    if (m_terminado) {
        return;
    }

    
    m_i = m_j;

    
    m_comparaciones++;

    
    if (m_datos[m_j] > m_datos[m_j + 1]) {
        
        int temp = m_datos[m_j];
        m_datos[m_j] = m_datos[m_j + 1];
        m_datos[m_j + 1] = temp;
        
        m_intercambios++;
        m_huboSwap = true;
    }

    
    m_j++;

    
    if (m_j >= m_limite) {
        if (!m_huboSwap) {
            
            m_terminado = true;
        } else {
            
            m_limite--;
            m_j = 0;
            m_huboSwap = false;

            if (m_limite <= 0) {
                m_terminado = true;
            }
        }
    }
}