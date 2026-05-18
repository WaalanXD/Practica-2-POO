#include "QuickSort.h"

// Constructor
QuickSort::QuickSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_partIzq = 0;
    m_partDer = 0;
    m_pivote = 0;
    m_indicePart = 0;
    m_enParticion = false;
    
    inicializarRangos();
}

// Destructor
QuickSort::~QuickSort() {
    // Limpiar la pila
    while (!m_rangos.empty()) {
        m_rangos.pop();
    }
}

// Reiniciar
void QuickSort::reiniciar(const vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_partIzq = 0;
    m_partDer = 0;
    m_pivote = 0;
    m_indicePart = 0;
    m_enParticion = false;

    // Limpiar la pila
    while (!m_rangos.empty()) {
        m_rangos.pop();
    }
    inicializarRangos();
}

// Inicializar rangos
void QuickSort::inicializarRangos() {
    if (m_datos.size() <= 1) {
        m_terminado = true;
        return;
    }
    
    Rango inicial;
    inicial.izq = 0;
    inicial.der = (int)m_datos.size() - 1;
    m_rangos.push(inicial);
}

// Un paso del algoritmo
void QuickSort::paso() {
    if (m_terminado) {
        return;
    }

    // Si estamos particionando, continuar
    if (m_enParticion) {
        // Hacer UNA comparacion
        m_comparaciones++;

        if (m_datos[m_j] < m_pivote) {
            m_indicePart++;
            if (m_indicePart != m_j) {
                // Intercambio manual
                int temp = m_datos[m_indicePart];
                m_datos[m_indicePart] = m_datos[m_j];
                m_datos[m_j] = temp;
                
                m_intercambios++;
            }
        }

        m_j++;
        m_i = m_indicePart;

        // Si terminamos de recorrer
        if (m_j >= m_partDer) {
            // Colocar pivote en su posicion final
            int temp = m_datos[m_indicePart + 1];
            m_datos[m_indicePart + 1] = m_datos[m_partDer];
            m_datos[m_partDer] = temp;
            
            m_intercambios++;
            int posPivote = m_indicePart + 1;

            // Agregar sub-rangos a la pila
            if (posPivote + 1 < m_partDer) {
                Rango derecho;
                derecho.izq = posPivote + 1;
                derecho.der = m_partDer;
                m_rangos.push(derecho);
            }
            if (m_partIzq < posPivote - 1) {
                Rango izquierdo;
                izquierdo.izq = m_partIzq;
                izquierdo.der = posPivote - 1;
                m_rangos.push(izquierdo);
            }

            m_enParticion = false;
        }
        return;
    }

    // Si no hay mas rangos, terminamos
    if (m_rangos.empty()) {
        m_terminado = true;
        return;
    }

    // Obtener el siguiente rango
    Rango rango = m_rangos.top();
    m_rangos.pop();

    if (rango.izq < rango.der) {
        // Iniciar particion
        m_partIzq = rango.izq;
        m_partDer = rango.der;
        // Elegir pivote por "mediana de tres" (izq, medio, der) para reducir particiones desbalanceadas.
        // Luego lo movemos al final para reutilizar la particion actual.
        int izq = rango.izq;
        int der = rango.der;
        int mid = izq + (der - izq) / 2;

        int a = m_datos[izq];
        int b = m_datos[mid];
        int c = m_datos[der];

        auto less = [this](int x, int y) {
            m_comparaciones++;
            return x < y;
        };

        int indicePivote;
        // indicePivote = indice del valor mediano entre a, b, c
        // (con comparaciones contadas de forma explícita)
        if (less(a, b)) {
            if (less(b, c)) {
                indicePivote = mid;      // a < b < c
            } else if (less(a, c)) {
                indicePivote = der;      // a < c <= b
            } else {
                indicePivote = izq;      // c <= a < b
            }
        } else {
            if (less(a, c)) {
                indicePivote = izq;      // b <= a < c
            } else if (less(b, c)) {
                indicePivote = der;      // b < c <= a
            } else {
                indicePivote = mid;      // c <= b <= a
            }
        }

        if (indicePivote != der) {
            int tmp = m_datos[indicePivote];
            m_datos[indicePivote] = m_datos[der];
            m_datos[der] = tmp;
            m_intercambios++;
        }
        m_pivote = m_datos[rango.der];
        m_indicePart = rango.izq - 1;
        m_j = rango.izq;
        m_enParticion = true;
    }
}