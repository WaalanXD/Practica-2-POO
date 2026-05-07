#ifndef ALGORITMOORDENAMIENTO_H
#define ALGORITMOORDENAMIENTO_H

#include <vector>
#include <string>

using namespace std;

// Clase base abstracta para algoritmos de ordenamiento
class AlgoritmoOrdenamiento {
public:
    // Constructor: recibe los datos a ordenar
    explicit AlgoritmoOrdenamiento(const vector<int>& datos);
    
    // Destructor virtual: necesario para herencia
    virtual ~AlgoritmoOrdenamiento() = default;

    // Metodo virtual puro: cada subclase DEBE implementarlo
    virtual void paso() = 0;

    // Reinicia el algoritmo con nuevos datos
    virtual void reiniciar(const vector<int>& datos);

    // Retorna true si ya termino de ordenar
    bool terminado() const { return m_terminado; }

    // Retorna el nombre del algoritmo
    virtual string nombre() const = 0;

    // Getters para acceder al estado
    vector<int> getDatos() const { return m_datos; }
    int getTamano() const { return (int)m_datos.size(); }
    int getIndicePrimero() const { return m_i; }
    int getIndiceSegundo() const { return m_j; }
    int getComparaciones() const { return m_comparaciones; }
    int getIntercambios() const { return m_intercambios; }

protected:
    vector<int> m_datos;      // El arreglo a ordenar
    bool m_terminado;         // Si ya termino
    int m_i;                  // Indice primero
    int m_j;                  // Indice segundo
    int m_comparaciones;      // Contador de comparaciones
    int m_intercambios;       // Contador de intercambios
};

#endif