#include "AlgoritmoOrdenamiento.h"

// Constructor
AlgoritmoOrdenamiento::AlgoritmoOrdenamiento(const vector<int>& datos) {
    m_datos = datos;
    m_terminado = false;
    m_i = 0;
    m_j = 0;
    m_comparaciones = 0;
    m_intercambios = 0;
}

// Destructor
AlgoritmoOrdenamiento::~AlgoritmoOrdenamiento() {
    // No hay nada que liberar manualmente
    // El vector se libera automaticamente
}

// Reiniciar con nuevos datos
void AlgoritmoOrdenamiento::reiniciar(const vector<int>& datos) {
    m_datos = datos;
    m_terminado = false;
    m_i = 0;
    m_j = 0;
    m_comparaciones = 0;
    m_intercambios = 0;
}

// Getters
bool AlgoritmoOrdenamiento::terminado() const {
    return m_terminado;
}

vector<int> AlgoritmoOrdenamiento::getDatos() const {
    return m_datos;
}

int AlgoritmoOrdenamiento::getTamano() const {
    return (int)m_datos.size();
}

int AlgoritmoOrdenamiento::getIndicePrimero() const {
    return m_i;
}

int AlgoritmoOrdenamiento::getIndiceSegundo() const {
    return m_j;
}

int AlgoritmoOrdenamiento::getComparaciones() const {
    return m_comparaciones;
}

int AlgoritmoOrdenamiento::getIntercambios() const {
    return m_intercambios;
}