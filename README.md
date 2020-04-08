# ESTE REPOSITORIO CONTIENE LA CUARTA PRÁCTICA DE AyEDA.
*( Implementación de una tabla hash)*
***

## Contenido:

- []()
- []()
- []()

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

- make  -> compila el fichero fuente básico solicitado

- make graphic  -> compila la versión gráfica del programa
> debe tener en cuenta que para que esto funcione la macro
> INFINITE debe retener un valor 1 (true), ya que debido 
> a la implementación que se ha hecho es necesario.

- make clean -> eliminar ejecutables

## Modificación del aula
 Consta de calcular la célula con máximos vecinos vivos cada turno.

 Se encuentra en la carpeta modif.

 Aún no tiene una regla make por cuestiones de tiempo.

## Respecto a ideas futuras
 - otorgar a las células varios puntos de vida
  > esto podría emplearse con OpenGL para otorgar un color 
  > distinto a cada estado y asi generar un mapa de calor.
