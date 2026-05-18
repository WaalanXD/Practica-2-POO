#include "MergeSort.h"


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


MergeSort::~MergeSort() {
    
    while (!m_tareas.empty()) {
        m_tareas.pop();
    }
}


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

    
    while (!m_tareas.empty()) {
        m_tareas.pop();
    }
    inicializarTareas();
}


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


void MergeSort::paso() {
    if (m_terminado) {
        return;
    }

    
    if (m_enMerge) {
        if (m_mergeI <= m_mergeMid && m_mergeJ <= m_mergeDer) {
            
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
            
            m_temp[m_mergeK] = m_datos[m_mergeI];
            m_mergeI++;
            m_mergeK++;
        } else if (m_mergeJ <= m_mergeDer) {
            
            m_temp[m_mergeK] = m_datos[m_mergeJ];
            m_mergeJ++;
            m_mergeK++;
        }

        
        m_i = m_mergeI;
        m_j = m_mergeJ;

        
        if (m_mergeK > m_mergeDer) {
            
            for (int t = m_mergeIzq; t <= m_mergeDer; t++) {
                m_datos[t] = m_temp[t];
            }
            m_enMerge = false;
        }
        return;
    }

    
    if (m_tareas.empty()) {
        m_terminado = true;
        return;
    }

    
    Tarea tarea = m_tareas.top();
    m_tareas.pop();

    if (tarea.esMerge) {
        
        m_mergeIzq = tarea.izq;
        m_mergeDer = tarea.der;
        m_mergeMid = (tarea.izq + tarea.der) / 2;
        m_mergeI = tarea.izq;
        m_mergeJ = m_mergeMid + 1;
        m_mergeK = tarea.izq;
        m_enMerge = true;
    } else {
        
        if (tarea.izq < tarea.der) {
            int mid = (tarea.izq + tarea.der) / 2;

            
            Tarea tareaM;
            tareaM.izq = tarea.izq;
            tareaM.der = tarea.der;
            tareaM.esMerge = true;
            m_tareas.push(tareaM);

            
            Tarea tareaD;
            tareaD.izq = mid + 1;
            tareaD.der = tarea.der;
            tareaD.esMerge = false;
            m_tareas.push(tareaD);

            
            Tarea tareaI;
            tareaI.izq = tarea.izq;
            tareaI.der = mid;
            tareaI.esMerge = false;
            m_tareas.push(tareaI);
        }
    }
}