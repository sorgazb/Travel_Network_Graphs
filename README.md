# Travel Network Graphs

![C++](https://img.shields.io/badge/C++-POO%20%26%20LPI-00599c?style=for-the-badge&logo=c%2B%2B)&nbsp;![Grafos](https://img.shields.io/badge/Grafos-Algoritmos-6a0dad?style=for-the-badge)&nbsp;![Ficheros](https://img.shields.io/badge/Lectura-Ficheros-555555?style=for-the-badge)&nbsp;![POO](https://img.shields.io/badge/POO-Programaci%C3%B3n-ff6f00?style=for-the-badge)

> **Travel Network Graphs** es un proyecto desarrollado en **C++** que implementa una red de viajes mediante **grafos**, aplicando **Programación Orientada a Objetos**, lectura de ficheros y algoritmos de grafos.

---

## 📋 Descripción

Aplicación de consola que modela una red de ciudades y viajes como un grafo, con los siguientes algoritmos y operaciones disponibles:

- **Insertar una ciudad** en el grafo.
- **Insertar un viaje nuevo** entre dos ciudades.
- **Obtener el grado** de un nodo/viaje.
- **Mostrar adyacencia** entre dos ciudades.
- **Mostrar todo el grafo** con sus nodos y aristas.
- **Lectura desde fichero**: carga automática de ciudades y viajes desde archivo.
- **POO**: clases y objetos para representar ciudades, viajes y el grafo.
- **Algoritmos de recorrido**: BFS/DFS para exploración del grafo.

---

## 🏗️ Estructura del Proyecto

```txt
Travel_Network_Graphs/
├── src/
│   ├── main.cpp           # Punto de entrada del programa
│   ├── Grafo.cpp / .h     # Clase Grafo con algoritmos
│   ├── Ciudad.cpp / .h    # Clase Ciudad (nodo del grafo)
│   └── Viaje.cpp / .h     # Clase Viaje (arista del grafo)
├── data/
│   └── ciudades.txt       # Fichero de datos de ciudades y viajes
├── .gitignore
└── README.md
```

---

## ⚙️ Compilación y Ejecución

Clona el repositorio:
```txt
git clone https://github.com/sorgazb/Travel_Network_Graphs.git
cd Travel_Network_Graphs
```

Compila con g++:
```txt
g++ -o travel src/main.cpp src/Grafo.cpp src/Ciudad.cpp src/Viaje.cpp
```

Ejecuta el programa:
```txt
./travel
```

---

## 🖥️ Ejemplos de Ejecución

<p align="center">
  <img src="https://github.com/sorgazb/Travel_Network_Graphs/assets/150727714/58e833e3-9cd0-48b5-b8ee-4e715ad6ea8d" alt="Captura 1" width="700"/>
</p>
<p align="center">
  <img src="https://github.com/sorgazb/Travel_Network_Graphs/assets/150727714/761fe524-831d-44e0-aebe-b1ebd3cbe3e5" alt="Captura 2" width="700"/>
</p>
<p align="center">
  <img src="https://github.com/sorgazb/Travel_Network_Graphs/assets/150727714/5842b29d-c1ca-48b8-bb4f-bf37539134c7" alt="Captura 3" width="700"/>
</p>
<p align="center">
  <img src="https://github.com/sorgazb/Travel_Network_Graphs/assets/150727714/9dd126f2-9dca-4901-922d-91fdac5eccd4" alt="Captura 4" width="700"/>
</p>

---

## 🤝 Contribución

Haz fork del repositorio.

Crea una rama de trabajo:

```txt
git checkout -b feature/nueva-funcionalidad
```

Realiza tus cambios y haz commit.

Abre un Pull Request describiendo tus mejoras.

---

<p align="center">
  <strong>Proyecto de Programación</strong> &nbsp;&middot;&nbsp; Sergio Orgaz Bravo
</p>
