#ifndef ALGORITMOORDENAMIENTO_H
#define ALGORITMOORDENAMIENTO_H

#include <vector>
#include <string>

using namespace std;

// Clase base abstracta para algoritmos de ordenamiento
class AlgoritmoOrdenamiento {
public:
    // Constructor: recibe los datos a ordenar
    AlgoritmoOrdenamiento(const vector<int>& datos);
    
    // Destructor virtual: necesario para herencia
    virtual ~AlgoritmoOrdenamiento();

    // Metodo virtual puro: cada subclase DEBE implementarlo
    virtual void paso() = 0;

    // Reinicia el algoritmo con nuevos datos
    virtual void reiniciar(const vector<int>& datos);

    // Retorna true si ya termino de ordenar
    bool terminado() const;

    // Retorna el nombre del algoritmo
    virtual string nombre() const = 0;

    // Getters para acceder al estado
    vector<int> getDatos() const;
    int getTamano() const;
    int getIndicePrimero() const;
    int getIndiceSegundo() const;
    int getComparaciones() const;
    int getIntercambios() const;

protected:
    vector<int> m_datos;      // El arreglo a ordenar
    bool m_terminado;         // Si ya termino
    int m_i;                  // Indice primero
    int m_j;                  // Indice segundo
    int m_comparaciones;      // Contador de comparaciones
    int m_intercambios;       // Contador de intercambios
};

#endif