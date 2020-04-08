# ESTE REPOSITORIO CONTIENE LA CUARTA PRÁCTICA DE AyEDA.
*( Implementación de una tabla hash)*
***
## Resumen:

    En esta práctica se implementarán plantillas que darán lugar a clases
    que se emplearán para simular el TAD de tablas de dispersión
    Entre estas plantillas se encuentran la "Celda" y la "Tabla", ambas
    recibirán un tipo de clave.

    Para este caso desarrollamos la clave DNI, que también es una clase.

    El uso que el programa principal da a estas clases es el cálculo de unas estadísticas de rendimiento en cuanto a las variaciones de funciones hash, funciones de exploración y los fatores de carga.

## Contenido:
**En el include:**
- [Definición de la plantilla de clase tabla]()
- [Definición de la plantilla de clase Celda]()
- [Definición de la clase de clave DNI]()
- [Clase abstracta de función de dispersión]()
- [Clase abstracta de función de exploración]()

**En el src:**
- [Implementación de la clase de clave DNI]()
- [Implementación del programa principal]()

**En el tests:**
- [Test de la plantilla de clase tabla]()
- [Test de la plantilla de clase Celda]()
- [Test de la clase de clave DNI]()
- [Test de las funciones del programa principal]()

## Dependencias

- [Catch2](https://github.com/catchorg/Catch2)
  > Librería de testing para C++ con BDD
  
  
  **Para instalarla:**
  ```BASH
  git clone https://github.com/catchorg/Catch2.git 
  cd Catch2 
  cmake -Bbuild -H. -DBUILD_TESTING=OFF 
  sudo cmake --build build/ --target install
  ```

## funciones del makefile 

- make       :arow_right: compila el fichero fuente básico solicitado
- make test  :arow_right: compila los test
- make clean :arow_right: eliminar ejecutables
