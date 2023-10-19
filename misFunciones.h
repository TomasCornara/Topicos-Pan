#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//Ejercicio 1 Factorial
int factorial(int);

//Ejercicio 2 Combinatorio
float combinatorio(int, int);

//Ejercicio 3 e a la x
float eALaX(int, float);

//Ejercicio 4 raiz cuadrada
float raiz(int,float);

//Ejercicio 5 Fibonacci
bool esFibo(int);

//Ejercicio 6 Seno
float seno(int, float);

//Ejercicio 7 natural perfecto
void perfecto(int);
int sumaDivisores(int);

//Ejercicio 8 producto por sumas
int producto(int, int);

//Ejercicio 9 division
int division(int,int);

//Ejercicicio 10 suma primeros N naturales
int sumNNaturales(int);

//Ejercicio 11 suma primeros N naturales pares
int sumNNaturalesPares(int);

//Ejercicio 12 suma de pares menores que N
int sumNPMen(int);

//Ejercicio 13
bool esPrimo(int);

//EJERCICIOS DE VECTORES

//Ejercicio 1.1 insertar un vector
void insertar(int*,int, int);

//Ejercicio 1.2 Insertar ordenado
void insOrd(int*,int,int);
void hacerEspacio(int*, int*);

//Ejercicio 1.3 eliminar una posicion en un arreglo de int
void eliminar(int*,int);

//Ejercicio 1.4 eliminar primera aparicion
void elimPrim(int*,int,int);

//Ejercicio 1.5 eliminar todas las apariciones
int elimTodas(int*,int,int);

//Ejercicio 1.6 Palindromo
void esPalindromo(const char*);
int tamString (const char*);

//Ejercicio 1.7 Valor numerico
int charAInt(const char*);

//Ejercicio 1.8 apariciones de una palabra
int contarPalabra(char*, char*);

//Ejercicio 1.9 Normalizar una cadena
char *normalizar(char *);
char *buscarPalabra(char *);
bool esChar(char);

//Ejercicio 1.10 Desosfuscar
char* desOsfuscar(char *);
bool estaEnGrupo(char);
char charDes(char caracter, int cant);

//Ejercicio 1,11

//EJERCICIOS DE MATRICES

//Ejercicio 1.12 Sumatoria triangulo superior
int sumTrianSup (int col, int mat[][col]);
int sumTrianSupPrimDiag(int col, int mat[][col]);
int sumTrianSupSec(int col, int mat[][col]);
int sumTrianSupSecDiag(int col, int mat[][col]);

//Ejercicio 1.13 Suma diagonal
int trazaPrincipal(int col, int mat[][col]);
int trazaSecu(int col, int mat[][col]);

//Ejercicio 1.14 Matriz Diagonal
bool esDiag(int col, int mat[][col]);

//Ejercicio 1.14 Matriz Diagonal
bool esIdent(int col, int mat[][col]);

//Ejercicio 1.16 Matriz simetrica
bool esSimetrica(int col, int mat[][col]);

//Ejercicio 1.17 Transponer un matriz
void transponer(int col, int mat[][col]);

//Ejercicio 1.18 Transponer usando referencia
void transRef(int col, int mat[][col], int result[][col]);


//Ejercicio 1.19 Producto matricial
void productoMatricial(int col, int mat1[][col], int mat2[][col], int result[][col]);

#endif // MISFUNCIONES_H_INCLUDED
