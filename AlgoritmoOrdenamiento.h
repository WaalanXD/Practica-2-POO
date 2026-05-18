#ifndef ALGORITMOORDENAMIENTO_H
#define ALGORITMOORDENAMIENTO_H

#include <vector>
#include <string>

using namespace std;


class AlgoritmoOrdenamiento {
public:
    
    explicit AlgoritmoOrdenamiento(const vector<int>& datos);
    
    
    virtual ~AlgoritmoOrdenamiento() = default;

    
    virtual void paso() = 0;

    
    virtual void reiniciar(const vector<int>& datos);

    
    bool terminado() const { return m_terminado; }

    
    virtual string nombre() const = 0;

    
    const vector<int>& datos() const { return m_datos; }
    int tamano() const { return static_cast<int>(m_datos.size()); }
    int indicePrimero() const { return m_i; }
    int indiceSegundo() const { return m_j; }
    int comparaciones() const { return m_comparaciones; }
    int intercambios() const { return m_intercambios; }

protected:
    vector<int> m_datos;      
    bool m_terminado;         
    int m_i;                  
    int m_j;                  
    int m_comparaciones;      
    int m_intercambios;       
};

#endif