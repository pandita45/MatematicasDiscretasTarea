# MatematicasDiscretasTarea

## Requisitos
- Sistema operativo: linux X86_64
- Compilador: Gcc
- CMake (Herramienta de compilación)
- Dependencias necesarias para compilar en c
- 
## Instalar dependencias (si es necesario)

En Debian/Ubuntu:

```bash
sudo apt update
sudo apt install build-essential cmake git
```

## Compilación
```bash
# Clonar repositorio
git clone https://github.com/pandita45/MatematicasDiscretasTarea.git
cd MatematicasDiscretasTarea
# Compilar con CMake
CMake . 
make
```
## Ejecucion
```bash
Ejemplo de ejecucion
./matematicas a b src/planar.txt
Donde "a" es el vertice de inicio y "b" el vertice de destino
El tercer argumento es la ruta del grafo guardado en forma de txt
Se debe respetar la ruta y se puede elegir entre, planar.txt , euleriano.txt y arbol.txt
Los cuales contienen los diferentes tipos de grados a los que se les puede aplicar el algoritmo
```
