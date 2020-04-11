# ESTE REPOSITORIO CONTIENE LA CUARTA PRÁCTICA DE AyEDA.
*( Implementación de una tabla hash)*
***
## Resumen:

    En esta práctica se implementarán plantillas que darán lugar a clases
    que se emplearán para simular el TAD de tablas de dispersión
    Entre estas plantillas se encuentran la "Celda" y la "Tabla", ambas
    recibirán un tipo de clave.

    Para este caso desarrollamos la clave DNI, que también es una clase.

    El uso que el programa principal da a estas clases es el cálculo de unas estadísticas 
    de rendimiento en cuanto a las variaciones de funciones hash, funciones de exploración 
    y los fatores de carga.

## Contenido:
**En el include:**
- [Definición de la plantilla de clase tabla]()
- [Definición de la plantilla de clase Celda]()
- [Definición de la clase de clave DNI]()
- [Clase abstracta de función de dispersión]()
- [Clase abstracta de función de exploración]()

> Además de cada una de las implementaciones (sobrecargas) de las 
> funciones de dispersión y de exploración (en el mismo subdirectorio).
 

**En el src:**
- [Implementación de la clase de clave DNI]()
- [Implementación del programa principal]()

**En el tests:**
- [Fichero de unión de los test]()
- [Test de la plantilla de clase tabla]()
- [Test de la plantilla de clase Celda]()
- [Test de la clase de clave DNI]()
- [Tests de la función de dispersión y sus sobrecargas]()
- [Tests de la función de exploración y sus sobrecargas]()
- [Test de las funciones del programa principal]()

## Dependencias

- [Catch2](https://github.com/catchorg/Catch2)
  > Librería de testing para C++ con BDD
  
  
  **Para instalarla:**
  ```BASH
    ~$ git clone https://github.com/catchorg/Catch2.git 
    ~$ cd Catch2 
    ~$ cmake -Bbuild -H. -DBUILD_TESTING=OFF 
    ~$ sudo cmake --build build/ --target install
  ```

## funciones del makefile 

- make       :arrow_right: compila el fichero fuente básico solicitado
> genera el ejecutable como "runner" 
- make test  :arrow_right: compila los test
> genera el ejecutable como "test_runner". Si se ejecuta con "-s" se despliegan todos 
> los test
- make clean :arrow_right: eliminar ejecutables

