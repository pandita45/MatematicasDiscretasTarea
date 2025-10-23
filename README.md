# MatematicasDiscretasTarea
## Requisitos
- Sistema operativo: linux X86_64
- Compilador: Gcc
- CMake (Herramienta de compilación)
- Dependencias necesarias para compilar en c

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
./matematicas (Vertice A) (Vertice B) (Archivo.txt)
Donde 'A' es el vertice de inicio y 'B' el de destino, para el tercer parametro se puede seleccionar
entre los distintos tipos de grafos
planar.txt, arbol.txt, euleriano.txt

#Ejemplo de ejecucion
./matematicas a f src/planar.txt
```
