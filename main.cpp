#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "AlgoritmoOrdenamiento.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MemoryAnalysis.h"

using namespace std;

// Genera numeros aleatorios
vector<int> generarAleatorios(int cantidad) {
    vector<int> datos(cantidad);
    
    for (int i = 0; i < cantidad; i++) {
        datos[i] = rand() % 1000 + 1;  // Numeros entre 1 y 1000
    }
    
    return datos;
}

// Lee numeros desde archivo
vector<int> leerDesdeArchivo(string nombreArchivo) {
    vector<int> datos;
    ifstream archivo(nombreArchivo.c_str());
    
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return datos;
    }
    
    int valor;
    while (archivo >> valor) {
        datos.push_back(valor);
    }
    
    archivo.close();
    return datos;
}

// Crea el algoritmo segun la opcion
AlgoritmoOrdenamiento* crearAlgoritmo(int opcion, vector<int> datos) {
    switch (opcion) {
        case 1: return new BubbleSort(datos);
        case 2: return new InsertionSort(datos);
        case 3: return new SelectionSort(datos);
        case 4: return new MergeSort(datos);
        case 5: return new QuickSort(datos);
        default: return NULL;
    }
}

// Ejecuta y muestra resultados
void ejecutarAlgoritmo(AlgoritmoOrdenamiento* algo) {
    // Ejecutar todos los pasos
    while (!algo->terminado()) {
        algo->paso();
    }

    cout << endl;
    cout << "--- Resultados de " << algo->nombre() << " ---" << endl;
    cout << "Comparaciones: " << algo->getComparaciones() << endl;
    cout << "Intercambios:  " << algo->getIntercambios() << endl;

    // Mostrar primeros elementos
    vector<int> ordenado = algo->getDatos();
    cout << "Primeros 10 elementos: ";
    int mostrar = 10;
    if (algo->getTamano() < 10) {
        mostrar = algo->getTamano();
    }
    for (int i = 0; i < mostrar; i++) {
        cout << ordenado[i] << " ";
    }
    cout << endl;
}

// Menu principal
void mostrarMenu() {
    cout << endl;
    cout << "====================================" << endl;
    cout << "   ALGORITMOS DE ORDENAMIENTO" << endl;
    cout << "====================================" << endl;
    cout << "1. Cargar datos desde archivo" << endl;
    cout << "2. Generar datos aleatorios" << endl;
    cout << "3. Generar datos ordenados (ascendente)" << endl;
    cout << "4. Generar datos ordenados (descendente)" << endl;
    cout << "5. Seleccionar algoritmo y ordenar" << endl;
    cout << "6. Ejecutar pruebas comparativas" << endl;
    cout << "7. Analisis de memoria" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------------------" << endl;
    cout << "Opcion: ";
}

// Menu de algoritmos
void mostrarMenuAlgoritmos() {
    cout << endl;
    cout << "--- Seleccione algoritmo ---" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "Opcion: ";
}

// Pruebas comparativas
void ejecutarPruebas() {
    cout << endl;
    cout << "========== PRUEBAS COMPARATIVAS ==========" << endl;
    
    int tamanos[] = {10, 50, 100};
    string nombres[] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort"};

    for (int t = 0; t < 3; t++) {
        int tam = tamanos[t];
        
        cout << endl;
        cout << "--- DATOS ALEATORIOS (" << tam << " elementos) ---" << endl;
        cout << "Algoritmo          Comparaciones  Intercambios" << endl;
        cout << "----------------------------------------------" << endl;

        vector<int> datosBase = generarAleatorios(tam);

        for (int i = 1; i <= 5; i++) {
            vector<int> datosCopia = datosBase;
            AlgoritmoOrdenamiento* algo = crearAlgoritmo(i, datosCopia);

            while (!algo->terminado()) {
                algo->paso();
            }

            cout << nombres[i-1];
            // Espacios para alinear
            for (int s = nombres[i-1].length(); s < 19; s++) {
                cout << " ";
            }
            cout << algo->getComparaciones();
            // Espacios para alinear
            int numComp = algo->getComparaciones();
            int digitos = 1;
            while (numComp >= 10) {
                numComp = numComp / 10;
                digitos++;
            }
            for (int s = digitos; s < 15; s++) {
                cout << " ";
            }
            cout << algo->getIntercambios() << endl;

            delete algo;
        }
    }

    // Datos ordenados ascendente
    cout << endl;
    cout << "--- DATOS ORDENADOS ASCENDENTE (50 elementos) ---" << endl;
    cout << "Algoritmo          Comparaciones  Intercambios" << endl;
    cout << "----------------------------------------------" << endl;

    vector<int> datosAsc(50);
    for (int i = 0; i < 50; i++) {
        datosAsc[i] = i + 1;
    }

    for (int i = 1; i <= 5; i++) {
        vector<int> datosCopia = datosAsc;
        AlgoritmoOrdenamiento* algo = crearAlgoritmo(i, datosCopia);

        while (!algo->terminado()) {
            algo->paso();
        }

        cout << nombres[i-1];
        for (int s = nombres[i-1].length(); s < 19; s++) {
            cout << " ";
        }
        cout << algo->getComparaciones();
        int numComp = algo->getComparaciones();
        int digitos = 1;
        while (numComp >= 10) {
            numComp = numComp / 10;
            digitos++;
        }
        for (int s = digitos; s < 15; s++) {
            cout << " ";
        }
        cout << algo->getIntercambios() << endl;

        delete algo;
    }

    // Datos ordenados descendente
    cout << endl;
    cout << "--- DATOS ORDENADOS DESCENDENTE (50 elementos) ---" << endl;
    cout << "Algoritmo          Comparaciones  Intercambios" << endl;
    cout << "----------------------------------------------" << endl;

    vector<int> datosDesc(50);
    for (int i = 0; i < 50; i++) {
        datosDesc[i] = 50 - i;
    }

    for (int i = 1; i <= 5; i++) {
        vector<int> datosCopia = datosDesc;
        AlgoritmoOrdenamiento* algo = crearAlgoritmo(i, datosCopia);

        while (!algo->terminado()) {
            algo->paso();
        }

        cout << nombres[i-1];
        for (int s = nombres[i-1].length(); s < 19; s++) {
            cout << " ";
        }
        cout << algo->getComparaciones();
        int numComp = algo->getComparaciones();
        int digitos = 1;
        while (numComp >= 10) {
            numComp = numComp / 10;
            digitos++;
        }
        for (int s = digitos; s < 15; s++) {
            cout << " ";
        }
        cout << algo->getIntercambios() << endl;

        delete algo;
    }
}

// Analisis de memoria
void analisisMemoria() {
    cout << endl;
    cout << "========== ANALISIS DE MEMORIA ==========" << endl;
    MemoryAnalysis::run();
}

// Funcion principal
int main() {
    // Inicializar semilla para numeros aleatorios
    srand(time(0));
    
    vector<int> datosActuales;
    AlgoritmoOrdenamiento* algoritmoActivo = NULL;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Nombre del archivo: ";
                string nombreArchivo;
                cin >> nombreArchivo;
                datosActuales = leerDesdeArchivo(nombreArchivo);
                if (!datosActuales.empty()) {
                    cout << "Datos cargados: " << datosActuales.size() << " elementos." << endl;
                }
                break;
            }
            case 2: {
                cout << "Cantidad de elementos: ";
                int cantidad;
                cin >> cantidad;
                datosActuales = generarAleatorios(cantidad);
                cout << "Datos generados: " << datosActuales.size() << " elementos." << endl;
                break;
            }
            case 3: {
                cout << "Cantidad de elementos: ";
                int cantidad;
                cin >> cantidad;
                datosActuales.resize(cantidad);
                for (int i = 0; i < cantidad; i++) {
                    datosActuales[i] = i + 1;
                }
                cout << "Datos ascendentes generados." << endl;
                break;
            }
            case 4: {
                cout << "Cantidad de elementos: ";
                int cantidad;
                cin >> cantidad;
                datosActuales.resize(cantidad);
                for (int i = 0; i < cantidad; i++) {
                    datosActuales[i] = cantidad - i;
                }
                cout << "Datos descendentes generados." << endl;
                break;
            }
            case 5: {
                if (datosActuales.empty()) {
                    cout << "Error: Primero cargue o genere datos." << endl;
                    break;
                }
                if (algoritmoActivo != NULL) {
                    delete algoritmoActivo;
                    algoritmoActivo = NULL;
                }
                mostrarMenuAlgoritmos();
                int algoOpcion;
                cin >> algoOpcion;
                algoritmoActivo = crearAlgoritmo(algoOpcion, datosActuales);
                if (algoritmoActivo != NULL) {
                    cout << endl;
                    cout << "Ordenando con " << algoritmoActivo->nombre() << "..." << endl;
                    ejecutarAlgoritmo(algoritmoActivo);
                } else {
                    cout << "Opcion invalida." << endl;
                }
                break;
            }
            case 6:
                ejecutarPruebas();
                break;
            case 7:
                analisisMemoria();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    if (algoritmoActivo != NULL) {
        delete algoritmoActivo;
    }

    return 0;
}