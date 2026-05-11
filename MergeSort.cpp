#include "MergeSort.h"

// Constructor
MergeSort::MergeSort(const vector<int>& datos) : AlgoritmoOrdenamiento(datos) {
    m_mergeIzq = 0;
    m_mergeMid = 0;
    m_mergeDer = 0;
    m_mergeI = 0;
    m_mergeJ = 0;
    m_mergeK = 0;
    m_enMerge = false;
    
    m_temp.resize(datos.size());
    inicializarTareas();
}

// Destructor
MergeSort::~MergeSort() {
    // Limpiar la pila
    while (!m_tareas.empty()) {
        m_tareas.pop();
    }
}

// Reiniciar
void MergeSort::reiniciar(const vector<int>& datos) {
    AlgoritmoOrdenamiento::reiniciar(datos);
    m_temp.resize(datos.size());
    m_enMerge = false;
    m_mergeIzq = 0;
    m_mergeMid = 0;
    m_mergeDer = 0;
    m_mergeI = 0;
    m_mergeJ = 0;
    m_mergeK = 0;

    // Limpiar la pila
    while (!m_tareas.empty()) {
        m_tareas.pop();
    }
    inicializarTareas();
}

// Inicializar tareas
void MergeSort::inicializarTareas() {
    if (m_datos.size() <= 1) {
        m_terminado = true;
        return;
    }
    
    Tarea inicial;
    inicial.izq = 0;
    inicial.der = (int)m_datos.size() - 1;
    inicial.esMerge = false;
    m_tareas.push(inicial);
}

// Un paso del algoritmo
void MergeSort::paso() {
    if (m_terminado) {
        return;
    }

    // Si estamos en medio de un merge, continuar
    if (m_enMerge) {
        if (m_mergeI <= m_mergeMid && m_mergeJ <= m_mergeDer) {
            // Comparar elementos de ambas mitades
            m_comparaciones++;
            if (m_datos[m_mergeI] <= m_datos[m_mergeJ]) {
                m_temp[m_mergeK] = m_datos[m_mergeI];
                m_mergeI++;
            } else {
                m_temp[m_mergeK] = m_datos[m_mergeJ];
                m_mergeJ++;
                m_intercambios++;
            }
            m_mergeK++;
        } else if (m_mergeI <= m_mergeMid) {
            // Copiar resto de la izquierda
            m_temp[m_mergeK] = m_datos[m_mergeI];
            m_mergeI++;
            m_mergeK++;
        } else if (m_mergeJ <= m_mergeDer) {
            // Copiar resto de la derecha
            m_temp[m_mergeK] = m_datos[m_mergeJ];
            m_mergeJ++;
            m_mergeK++;
        }

        // Actualizar indices para visualizacion
        m_i = m_mergeI;
        m_j = m_mergeJ;

        // Verificar si termino el merge
        if (m_mergeK > m_mergeDer) {
            // Copiar de vuelta al arreglo original
            for (int t = m_mergeIzq; t <= m_mergeDer; t++) {
                m_datos[t] = m_temp[t];
            }
            m_enMerge = false;
        }
        return;
    }

    // Si no hay mas tareas, terminamos
    if (m_tareas.empty()) {
        m_terminado = true;
        return;
    }

    // Obtener la siguiente tarea
    Tarea tarea = m_tareas.top();
    m_tareas.pop();

    if (tarea.esMerge) {
        // Iniciar merge de dos mitades
        m_mergeIzq = tarea.izq;
        m_mergeDer = tarea.der;
        m_mergeMid = (tarea.izq + tarea.der) / 2;
        m_mergeI = tarea.izq;
        m_mergeJ = m_mergeMid + 1;
        m_mergeK = tarea.izq;
        m_enMerge = true;
    } else {
        // Dividir en dos mitades
        if (tarea.izq < tarea.der) {
            int mid = (tarea.izq + tarea.der) / 2;

            // Agregar tarea de merge
            Tarea tareaM;
            tareaM.izq = tarea.izq;
            tareaM.der = tarea.der;
            tareaM.esMerge = true;
            m_tareas.push(tareaM);

            // Agregar mitad derecha
            Tarea tareaD;
            tareaD.izq = mid + 1;
            tareaD.der = tarea.der;
            tareaD.esMerge = false;
            m_tareas.push(tareaD);

            // Agregar mitad izquierda
            Tarea tareaI;
            tareaI.izq = tarea.izq;
            tareaI.der = mid;
            tareaI.esMerge = false;
            m_tareas.push(tareaI);
        }
    }
}