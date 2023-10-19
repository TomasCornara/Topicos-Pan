#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "misFunciones.h"
#include <ctype.h>

//Ejercicio 1 Factorial
int factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return(num * factorial(num - 1));
}

//Ejercicio 2 Combinatorio
float combinatorio(int m, int n)
{
    int result = factorial(m)/(factorial(n) * factorial(m-n));
    return(result);
}

//Ejercicio 3 e a la x
float termino(int x, int itr, float tol)
{
    return (pow(x,itr)/factorial(itr));
}

float eALaX(int x, float tol)
{
    float term,
          acu = 1;

    for(int y = 1; (term = termino(x,y,tol)) >= tol; y++)
    {
        acu += term;
    }

    return (acu);
}

//Ejercicio 4 raiz cuadrada
float raiz(int numA, float tol)
{
    float actual = 1,
          anterior = 0;
    while((actual - anterior) > tol)
    {
        anterior = actual;
        actual = 0.5 * (anterior + (numA/anterior));
    }

    return actual;
}

//Ejercicio 5 Fibonacci
bool esFibo(int num)
{
    int terminoActual = 1,
        terminoAnterior = 1,
        terminoSiguiente;

    while(terminoActual < num)
    {
        terminoSiguiente = terminoActual + terminoAnterior;
        terminoAnterior = terminoActual;
        terminoActual = terminoSiguiente;

        if (terminoActual == num)
        {
            return true;
        }
    }

    return false;
}

//Ejercicio 6 Seno
float seno(int x, float tol)
{

    float termino = x;
    float acu = x;
    int signo = -1;

    for(int cont = 3; fabs(termino) > tol; cont += 2)
    {
        termino = signo * pow(x, cont)/factorial(cont);
        acu += termino;
        signo *= -1;
    }

    return acu;
}

//Ejercicio 7 natural perfecto
void perfecto(int num)
{
    int sum = sumaDivisores(num);

    if(sum == num)
    {
        printf("Perfecto.\n");
        return;
    }

    if(sum < num)
    {
        printf("Deficiente.\n");
        return;
    }
    printf("Abundante.\n");
}

int sumaDivisores(int num)
{
    int acu = 0;
    for(int aux = num - 1; aux > 0; aux--)
    {
        if(num % aux == 0)
        {
            acu+= aux;
        }
    }
    return acu;
}

//Ejercicio 8 producto por sumas
int producto(int numA, int numB)
{
    int acu = 0;
    for(; numB != 0; numB--)
    {
        acu += numA;
    }
    return acu;
}

//Ejercicio 9 division
int division(int A, int B)
{
    if (B == 0)
    {
        return -1;
    }

    int result = 0;

    for(; A > 0 && A > B; A -= B )
    {
        result++;
    }

    return result;
}

//Ejercicicio 10 suma primeros N naturales
int sumNNaturales(int num)
{
    int acu = 0;
    for(int cont = 1; cont <= num; cont++)
    {
        acu += cont;
    }
    return acu;
}

//Ejercicio 11 suma primeros N naturales pares
int sumNNaturalesPares(int num)
{
    int acu = 0;
    for(int par = 2; par <= 2 * num; par += 2)
    {
        acu += par;
    }
    return acu;
}

//Ejercicio 12 suma de pares menores que N
int sumNPMen(int num)
{
    int acu = 0;
    for(int cont = 2; cont < num; cont += 2)
    {
        acu += cont;
    }
    return acu;
}

//Ejercicio 13 definir si un natural es primo
bool esPrimo(int num)
{
    int divisores = sumaDivisores(num);
    if( divisores + num == num + 1)
    {
        return true;
    }
    return false;
}

//EJERCICIOS VECTORES

//Ejercicio 1.1 insertar un vector
void insertar(int* inicial, int pos, int elem)
{
    *(inicial + pos -1) = elem;
}

//Ejercicio 1.2 Insertar ordenado
void insOrd(int* inicial,int cantElem,int elem)
{
    int* aux = inicial,
         *fin = inicial + cantElem;

    while(aux != fin && *aux < elem)
    {
        if(*aux == elem)
        {
            return;
        }
        aux++;
    }

    hacerEspacio(aux,fin);
    *aux = elem;
}

void hacerEspacio(int* posLib, int* posFin)
{
    if(posLib == posFin)
    {
        return;
    }

    while(posLib < posFin)
    {
        *posFin = *(posFin - 1);
        posFin--;
    }
}

//Ejercicio 1.3
void eliminar(int* inicio, int cantElem)
{
    int *fin = inicio + cantElem,
         *aux = inicio;
    while(aux != fin)
    {
        *aux = *(aux + 1);
        aux++;
    }
}

//Ejercicio 1.4
void elimPrim(int* inicio,int cantElem, int elem)
{
    int* fin = inicio + cantElem,
         *aux = inicio;

    while(aux != fin && *aux != elem)
    {
        aux++;
    }

    if(*aux == elem)
    {
        eliminar(aux, fin - aux);
    }
}

//Ejercicio 1.5 eliminar todas las apariciones
int elimTodas(int* inicio, int cantElem, int elem)
{
    int* fin = inicio + cantElem,
         *aux = inicio;

    int cantBorrados = 0;

    while(aux != fin)
    {
        if(*aux == elem)
        {
            eliminar(aux, fin - aux);
            aux--;
            cantBorrados++;
        }
        aux++;
    }

    return cantBorrados;
}

//Ejercicio 1.6 Palindromo
void esPalindromo(const char* cadena)
{
    const char* aux = cadena;
    const char* fin = cadena + tamString(cadena) - 1;

    while(aux < fin)
    {
        if(*aux != *fin)
        {
            printf("No palindromo.\n");
            return;
        }
        aux++;
        fin--;
    }

    printf("Palindromo.\n");
    return;
}

int tamString (const char* cadena)
{
    int cont = 0;
    while(*cadena != 0)
    {
        cont++;
        cadena++;
    }
    return cont;
}

//Ejercicio 1.7 Valor numerico
int charAInt(const char* vec)
{
    int cont = 0;

    for(int x = 0; *vec != '\0'; x++, vec++)
    {
        cont *= 10;
        cont += (*vec) - 48;
    }
    return cont;
}

//Ejercicio 1.8 apariciones de una palabra
int contarPalabra(char* texto, char* palabra)
{
    char* aux = palabra;
    int cont = 0;
    while(*texto != '\0')
    {
        if(*texto == *aux)
        {
            aux++;
            if(*aux =='\0')
            {
                cont++;
                aux = palabra;
            }
        }
        else
        {
            aux = palabra;
        }
        texto++;
    }
    return cont;
}

//Ejercicio 1.9 Normalizar una cadena
char *normalizar(char* cadena)
{
    char *normalizado = cadena;
    char *auxGeneral = cadena;
    char *auxIniPalabra = cadena;
    int banPrimPal = 0;

    while(*auxGeneral != '\0')
    {
        while(!esChar(*auxGeneral))
        {
            auxGeneral++;
        }
        auxIniPalabra = auxGeneral;
        auxGeneral = buscarPalabra(auxGeneral);

        while(auxIniPalabra != auxGeneral)
        {
            *normalizado = *auxIniPalabra;
            if (banPrimPal == 0)
            {
                banPrimPal = 1;
                *normalizado = toupper(*normalizado);
            }
            normalizado++;
            auxIniPalabra++;
        }

        *normalizado = ' ';
        normalizado++;
    }
    *normalizado = '\0';
    return cadena;
}

char *buscarPalabra(char *cadena)
{
    char* aux = cadena;
    while(*aux != ' ' && *aux != '\0')
    {
        aux++;
    }
    return aux;
}

bool esChar(char caracter)
{
    if((caracter >= '0' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'))
    {
        return true;
    }
    return false;
}

//Ejercicio 1.10 Desosfuscar
char *desOsfuscar(char *cadena)
{
    char *aux = cadena;
    int posPalabra = 1;

    while(*aux != '\0'){
        if(estaEnGrupo(*aux)){
            *aux = charDes(*aux, posPalabra);
        }
        aux++;
        posPalabra++;
        if(*aux == ' ' || !esChar(*aux)){
            posPalabra = 0;
        }
    }
    return cadena;
}

char charDes(char caracter, int cant){
    char grupo[]= "abcdghijkoqtuv";
    char *aux = grupo;
    while(*aux != caracter){
        aux++;
    }

    while(cant != 0){
        aux++;
        cant--;
        if(*aux == '\0'){
            aux = grupo;
        }
    }
    return *aux;
}

bool estaEnGrupo(char caracter)
{
    char grupo[]= "abcdghijkoqtuv";
    char *aux = grupo;
    while(*aux != '\0')
    {
        if(*aux == caracter)
        {
            return true;
        }
        aux++;
    }
    return false;
}

//Ejercicio 1.11


//EJERCICIOS CON MATRICES

//Ejercicio 1.12 Sumatoria triangulo superior
int sumTrianSupPrim (int col, int mat[][col]){
    int sum = 0;
    for(int x = 0; x < col; x++){
        for(int y = x + 1; y < col; y++ ){
            sum += mat[x][y];
        }
    }
    return sum;
}

int sumTrianSupPrimDiag(int col, int mat[][col]){
    int sum = 0;
    for(int x = 0; x < col; x++){
        for(int y = x; y < col; y++ ){
            sum += mat[x][y];
        }
    }
    return sum;
}

int sumTrianSupSec(int col, int mat[][col]){
    int sum = 0;
    for(int x = 0; x < col; x++){
        for(int y = x + 1; y < col; y++ ){
            sum += mat[y][x];
        }
    }
    return sum;
}

int sumTrianSupSecDiag(int col, int mat[][col]){
    int sum = 0;
    for(int x = 0; x < col; x++){
        for(int y = x; y < col; y++ ){
            sum += mat[y][x];
        }
    }
    return sum;
}

//Ejercicio 1.13 Suma diagonal
int trazaPrincipal(int col, int mat[][col]){
    int sum = 0;
    for(int x = 0; x < col; x++){
        sum += mat[x][x];
    }
    return sum;
}

int trazaSecu(int col, int mat[][col]){
    int sum = 0;
    for(int x = col - 1; x >= 0; x--){
        sum += mat[x][x];
    }
    return sum;
}

//Ejercicio 1.14 Matriz Diagonal
bool esDiag(int col, int mat[][col]){
    bool result = ((trazaPrincipal(col,mat) > 0) &&
                  (sumTrianSupSec(col,mat) == 0) &&
                  (sumTrianSupPrim(col,mat) == 0));
    return result;
}

//Ejercicio 1.15 Matriz identidad
bool esIdent(int col, int mat[][col]){
    bool result = ((trazaPrincipal(col,mat) == 1*col) &&
                  (sumTrianSupSec(col,mat) == 0) &&
                  (sumTrianSupPrim(col,mat) == 0));
    return result;
}

//Ejercicio 1.16 Matriz simetrica
bool esSimetrica(int col, int mat[][col]){
    for(int x = 0; x < col; x++){
        for(int y = x + 1; y < col; y++ ){
            if(mat[y][x] != mat[x][y])
                return false;
        }
    }
    return true;
}

//Ejercicio 1.17 Transponer un matriz
void transponer(int col,int mat[][col]){
    for(int x = 0; x < col; x++){
        for(int y = x + 1; y < col; y++ ){
            int aux= mat[y][x];
            mat[y][x] = mat[x][y];
            mat[x][y] = aux;
        }
    }
}

//Ejercicio 1.18 Transponer usando referencia
void transRef(int col, int mat[][col], int result[][col]){
    for(int x = 0; x < col; x++){
        for(int y = 0; y < col; y++){
            result[y][x] = mat[x][y];
        }
    }
}

//Ejercicio 1.19 Producto matricial
void productoMatricial(int col, int mat1[][col], int mat2[][col], int result[][col]){
    for(int x = 0; x < col; x++){
        for(int y = 0; y < col; y++){
            for(int z = 0; z < col; z++){
                result[x][z] += mat1[x][y] * mat2[y][z];
            }
        }
    }

}
