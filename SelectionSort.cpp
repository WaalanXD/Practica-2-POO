#include "SelectionSort.h"

// Constructor
SelectionSort::SelectionSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_indiceMinimo = 0;
    m_i = 0;
    m_j = 1;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}

// Destructor
SelectionSort::~SelectionSort() {
    // No hay nada extra que liberar
}

// Reiniciar
void SelectionSort::reiniciar(const vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_indiceMinimo = 0;
    m_i = 0;
    m_j = 1;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}

// Nombre del algoritmo
string SelectionSort::nombre() const {
    return "Selection Sort";
}

// Un paso del algoritmo
void SelectionSort::paso() {
    if (m_terminado) {
        return;
    }

    // Hacer UNA comparacion
    m_comparaciones++;

    // Si encontramos un elemento menor, actualizar el indice
    if (m_datos[m_j] < m_datos[m_indiceMinimo]) {
        m_indiceMinimo = m_j;
    }

    m_j++;

    // Si terminamos de buscar el minimo para esta posicion
    if (m_j >= (int)m_datos.size()) {
        // Intercambiar el minimo con la posicion actual
        if (m_indiceMinimo != m_i) {
            // Intercambio manual
            int temp = m_datos[m_i];
            m_datos[m_i] = m_datos[m_indiceMinimo];
            m_datos[m_indiceMinimo] = temp;
            
            m_intercambios++;
        }

        // Pasar a la siguiente posicion
        m_i++;
        m_indiceMinimo = m_i;
        m_j = m_i + 1;

        if (m_i >= (int)m_datos.size() - 1) {
            m_terminado = true;
        }
    }
}