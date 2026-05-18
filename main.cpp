#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

#include "AlgoritmoOrdenamiento.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MemoryAnalysis.h"

using namespace std;


vector<int> generarAleatorios(int cantidad) {
    vector<int> datos(cantidad);
    
    for (int i = 0; i < cantidad; i++) {
        datos[i] = rand() % 1000 + 1;  
    }
    
    return datos;
}


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


void ejecutarAlgoritmo(AlgoritmoOrdenamiento* algo) {
    
    auto inicio = chrono::high_resolution_clock::now();

    
    while (!algo->terminado()) {
        algo->paso();
    }

    
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> tiempo = fin - inicio;

    cout << endl;
    cout << "--- Resultados de " << algo->nombre() << " ---" << endl;
    cout << "Comparaciones: " << algo->comparaciones() << endl;
    cout << "Intercambios:  " << algo->intercambios() << endl;
    cout << "Tiempo:        " << fixed << setprecision(3) << tiempo.count() << " ms" << endl;

    
    const vector<int>& ordenado = algo->datos();
    cout << "Primeros 10 elementos: ";
    int mostrar = 10;
    if (algo->tamano() < 10) {
        mostrar = algo->tamano();
    }
    for (int i = 0; i < mostrar; i++) {
        cout << ordenado[i] << " ";
    }
    cout << endl;
}


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


void ejecutarPruebas() {
    cout << endl;
    cout << "========== PRUEBAS COMPARATIVAS ==========" << endl;
    
    int tamanos[] = {10, 50, 100};
    string nombres[] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort"};

    const int wAlgo = 18;
    const int wNum = 15;

    for (int t = 0; t < 3; t++) {
        int tam = tamanos[t];
        
        cout << endl;
        cout << "--- DATOS ALEATORIOS (" << tam << " elementos) ---" << endl;
        cout << left << setw(wAlgo) << "Algoritmo" << setw(wNum) << "Comparaciones" << setw(wNum) << "Intercambios" << "Tiempo (ms)" << endl;
        cout << "------------------------------------------------------------" << endl;

        vector<int> datosBase = generarAleatorios(tam);

        for (int i = 1; i <= 5; i++) {
            vector<int> datosCopia = datosBase;
            AlgoritmoOrdenamiento* algo = crearAlgoritmo(i, datosCopia);

            auto inicio = chrono::high_resolution_clock::now();

            while (!algo->terminado()) {
                algo->paso();
            }

            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, std::milli> tiempo = fin - inicio;

            cout << left << setw(wAlgo) << nombres[i-1]
                  << setw(wNum) << algo->comparaciones()
                  << setw(wNum) << algo->intercambios()
                  << fixed << setprecision(3) << tiempo.count() << " ms" << endl;

            delete algo;
        }
    }

    
    cout << endl;
    cout << "--- DATOS ORDENADOS ASCENDENTE (50 elementos) ---" << endl;
    cout << left << setw(wAlgo) << "Algoritmo" << setw(wNum) << "Comparaciones" << setw(wNum) << "Intercambios" << "Tiempo (ms)" << endl;
    cout << "------------------------------------------------------------" << endl;

    vector<int> datosAsc(50);
    for (int i = 0; i < 50; i++) {
        datosAsc[i] = i + 1;
    }

    for (int i = 1; i <= 5; i++) {
        vector<int> datosCopia = datosAsc;
        AlgoritmoOrdenamiento* algo = crearAlgoritmo(i, datosCopia);

        auto inicio = chrono::high_resolution_clock::now();

        while (!algo->terminado()) {
            algo->paso();
        }

        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> tiempo = fin - inicio;

        cout << left << setw(wAlgo) << nombres[i-1]
               << setw(wNum) << algo->comparaciones()
               << setw(wNum) << algo->intercambios()
               << fixed << setprecision(3) << tiempo.count() << " ms" << endl;

        delete algo;
    }

    
    cout << endl;
    cout << "--- DATOS ORDENADOS DESCENDENTE (50 elementos) ---" << endl;
    cout << left << setw(wAlgo) << "Algoritmo" << setw(wNum) << "Comparaciones" << setw(wNum) << "Intercambios" << "Tiempo (ms)" << endl;
    cout << "------------------------------------------------------------" << endl;

    vector<int> datosDesc(50);
    for (int i = 0; i < 50; i++) {
        datosDesc[i] = 50 - i;
    }

    for (int i = 1; i <= 5; i++) {
        vector<int> datosCopia = datosDesc;
        AlgoritmoOrdenamiento* algo = crearAlgoritmo(i, datosCopia);

        auto inicio = chrono::high_resolution_clock::now();

        while (!algo->terminado()) {
            algo->paso();
        }

        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> tiempo = fin - inicio;

        cout << left << setw(wAlgo) << nombres[i-1]
               << setw(wNum) << algo->comparaciones()
               << setw(wNum) << algo->intercambios()
               << fixed << setprecision(3) << tiempo.count() << " ms" << endl;

        delete algo;
    }
}


void analisisMemoria() {
    cout << endl;
    cout << "========== ANALISIS DE MEMORIA ==========" << endl;
    MemoryAnalysis::run();
}


int main() {
    
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