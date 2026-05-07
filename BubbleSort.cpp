#include "BubbleSort.h"

// Constructor
BubbleSort::BubbleSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_huboSwap = false;
    m_limite = (int)m_datos.size() - 1;
    
    // Si hay 0 o 1 elementos, ya esta ordenado
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}

// Destructor
BubbleSort::~BubbleSort() {
    // No hay nada extra que liberar
}

// Reiniciar
void BubbleSort::reiniciar(const vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_huboSwap = false;
    m_limite = (int)m_datos.size() - 1;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}

// Nombre del algoritmo
string BubbleSort::nombre() const {
    return "Bubble Sort";
}

// Un paso del algoritmo (UNA comparacion)
void BubbleSort::paso() {
    // Si ya termino, no hacer nada
    if (m_terminado) {
        return;
    }

    // Guardar indice actual
    m_i = m_j;

    // Hacer UNA comparacion
    m_comparaciones++;

    // Si el elemento actual es mayor que el siguiente, intercambiar
    if (m_datos[m_j] > m_datos[m_j + 1]) {
        // Intercambio manual (sin usar std::swap)
        int temp = m_datos[m_j];
        m_datos[m_j] = m_datos[m_j + 1];
        m_datos[m_j + 1] = temp;
        
        m_intercambios++;
        m_huboSwap = true;
    }

    // Avanzar al siguiente par
    m_j++;

    // Si llegamos al limite, terminamos esta pasada
    if (m_j >= m_limite) {
        if (!m_huboSwap) {
            // No hubo intercambios: ya esta ordenado
            m_terminado = true;
        } else {
            // Preparar siguiente pasada
            m_limite--;
            m_j = 0;
            m_huboSwap = false;

            if (m_limite <= 0) {
                m_terminado = true;
            }
        }
    }
}