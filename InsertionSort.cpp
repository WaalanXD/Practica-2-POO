#include "InsertionSort.h"

// Constructor
InsertionSort::InsertionSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_valorActual = 0;
    m_insertando = false;
    m_i = 1;  // Empezamos desde el segundo elemento
    m_j = 0;
    
    if (m_datos.size() <= 1) {
        m_terminado = true;
    }
}

// Destructor
InsertionSort::~InsertionSort() {
    // No hay nada extra que liberar
}

// Reiniciar
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

// Un paso del algoritmo
void InsertionSort::paso() {
    if (m_terminado) {
        return;
    }

    // Si no estamos insertando, comenzar con el siguiente elemento
    if (!m_insertando) {
        m_valorActual = m_datos[m_i];
        m_j = m_i - 1;
        m_insertando = true;
    }

    // Hacer UNA comparacion
    m_comparaciones++;

    if (m_j >= 0 && m_datos[m_j] > m_valorActual) {
        // Mover elemento hacia la derecha
        m_datos[m_j + 1] = m_datos[m_j];
        m_intercambios++;
        m_j--;
    } else {
        // Insertar el valor en su posicion correcta
        m_datos[m_j + 1] = m_valorActual;
        m_insertando = false;
        m_i++;

        if (m_i >= (int)m_datos.size()) {
            m_terminado = true;
        }
    }
}