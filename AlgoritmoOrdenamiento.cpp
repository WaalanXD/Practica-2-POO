#include "AlgoritmoOrdenamiento.h"


AlgoritmoOrdenamiento::AlgoritmoOrdenamiento(const vector<int>& datos) {
    m_datos = datos;
    m_terminado = false;
    m_i = 0;
    m_j = 0;
    m_comparaciones = 0;
    m_intercambios = 0;
}


void AlgoritmoOrdenamiento::reiniciar(const vector<int>& datos) {
    m_datos = datos;
    m_terminado = false;
    m_i = 0;
    m_j = 0;
    m_comparaciones = 0;
    m_intercambios = 0;
}
