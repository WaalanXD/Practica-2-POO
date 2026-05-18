## Practica 2 - POO

Este proyecto genera dos ejecutables distintos:

- `practica2.exe`: menú interactivo de algoritmos de ordenamiento.
- `memory_analysis.exe`: análisis de memoria (separado del menú).

### Compilar con g++ (MinGW)

Menú interactivo:

```bash
g++ -std=c++17 -O2 -Wall -Wextra AlgoritmoOrdenamiento.cpp BubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp main.cpp -o practica2.exe
```

Análisis de memoria:

```bash
g++ -std=c++17 -O2 -Wall -Wextra AlgoritmoOrdenamiento.cpp BubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp memory_analysis_main.cpp -o memory_analysis.exe
```

### Ejecutar

```bash
./practica2.exe
./memory_analysis.exe
```
