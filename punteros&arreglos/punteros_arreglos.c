#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ¿Cuál es el valor de a y b luego de ejecutar el programa? */

void myFunc( int* a, int b) {
    (*a)++;
    b++;
    printf("Value of a inside the function: %d\n", *a);
    printf("Value of b inside the function: %d\n", b);
}

//int main() {
//    int a = 10;
//   int b = 10;
//    myFunc(&a, b);
//   printf("Value of a in main: %d\n", a);
//    printf("Value of b in main: %d\n", b);
//    return 0;
//}

/* ¿Qué valor se imprime por consola luego de cada llamado a printf? */
//int main() {
//    int x = 10;
//    int* px = &x;
//
//    printf( "%p \n", px );
//    printf( "%d \n", *px);
//
//    (*px)++;

//    printf( "%p \n", px);
//    printf( "%d \n", *px);

//    return 0;
//}
/* cambiar el valor de x, no cambia donde x se aloja en la memoria */

//Implementar las siguientes funciones:
void createArray( int v ) {
    //int myArray[8] = {v, v, v, v, v, v, v, v}; //lo creo y lo declaro
    
    int myArray[8]; // declaro el array
    for (int elem = 0; elem < 8; ++elem) {
        myArray[elem] = v; // lo inicializo con el valor i en todos sus elems
    }
    printf("First element: %d\n", myArray[0]);
    printf("Second element: %d\n", myArray[1]);
    printf("Third element: %d\n", myArray[2]);
    printf("Fourth element: %d\n", myArray[3]);
    printf("Fifth element: %d\n", myArray[4]);
    printf("Sixth element: %d\n", myArray[5]);
    printf("Seventh element: %d\n", myArray[6]);
    printf("Eighth element: %d\n", myArray[7]);
}

//int main() {
//    createArray(6);
//    return 0;
//}


int* createArrayDyn( int n, int v) {
    int *myArray = malloc(n * sizeof(int));
    if (myArray == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed.\n");
        return 0;
    }
    for (int elem = 0; elem < n; ++elem) {
        myArray[elem] = v;
    }
    return myArray;
}

//int main() {
//    int* x = createArrayDyn( 5, 1 );
//    if (x == NULL) {
//        printf("Failed to create array.\n");
//        return 1;
//    }
//    printf("Puntero al arreglo de tamaño 5 con elementos 1: %p\n", x);
//    free(x);  // free the dynamically allocated memory
//    return 0;
//}


void mostrarMemoria( int* arr, int size ) {
    for( int i = 0; i < size; ++i ) {
        printf("Elemento: %d, Direccion:%p\n", i, &arr[i]);
    }
}

//int main() {
//    int* x = createArrayDyn( 5, 1 );
//    if (x == NULL) {
//        printf("Failed to create array.\n");
//        return 1;
//    }
//    printf("Puntero al arreglo de tamaño 5 con elementos 1: %p\n", x);
//    mostrarMemoria(x, 5);
//    free(x);
//    return 0;
//}

/*
¿Cuál es la diferencia entre malloc y calloc? ¿Cuándo utilizamos la función free?
1. malloc
- asigna un bloque de memoria sin inicializar
- no garantiza que la memoria esté inicializada en cero
- La sintaxis es void* malloc(size_t size) donde size es el tamaño del bloque de memoria que se va a asignar en bytes.

2. calloc
- asigna un bloque de memoria inicializado
- garantiza que este inicializado en 0
- La sintaxis es void* calloc(size_t num_elements, size_t element_size) donde num_elements es el número de elementos que se van a asignar y element_size es el tamaño en bytes de cada elemento.

Utilizo la función free cuando:
- al momento que termine de usar memoria dinámica
- antes de perder la referencia al puntero que apunta a ella, ya que sino se produce una fuga de mem
- NO hay que hacerlo cuando no se ha asignado dinamicamente a un puntero
*/

//Dado el siguiente struct que representa una persona
typedef struct Persona{
    int edad;
    char* nombre;
} Persona;

Persona* inicializarPersonasMall(int n) {
    Persona* personas = malloc(n * sizeof(Persona));
    if (personas == NULL) {
        return NULL;
    }
    return personas;
}

Persona* inicializarPersonasCall(int n) {
    Persona* personas = calloc(n, sizeof(Persona));
    if (personas == NULL) {
        return NULL;
    }
    return personas;
}

//int main() {
//    int num_personas = 3; // Número de personas a inicializar

//    // Llamada a la función inicializarPersonas para crear un array de personas
//    Persona* personas = inicializarPersonasCall(num_personas);
//
//    if (personas == NULL) {
//        printf("Error: No se pudo inicializar el array de personas.\n");
//        return 1; // Salir del programa con código de error
//    }

//    // Imprimir información de las personas inicializadas
//    for (int i = 0; i < num_personas; i++) {
//        printf("Persona %d:\n", i + 1);
//        printf("  Edad: %d\n", personas[i].edad);
//        printf("  Nombre: %s\n", personas[i].nombre != NULL ? personas[i].nombre : "N/A");
//        printf("\n");
//   }

//    // Liberar la memoria asignada para el array de personas
//    free(personas);

//    return 0;
//}

/* Programar las siguientes funciones en C */
int maximo( int* arr, int size ) {
    int max = 0;
    for( int elem = 0; elem < size; ++elem ) {
        if (max < arr[elem]) {
            max = arr[elem];
        }
    }
    return max;
}

//int main() {
//    int myArray[] = {5, 3, 9, 11, 7, 2};
//    int tamano = sizeof(myArray) / sizeof(myArray[0]); 
    
//    int max = maximo(myArray, tamano);
//    printf("El máximo del arreglo es: %d\n", max);

//    return 0;
//}

void sumador( int* arr, int size, int c) {
    for (int elem = 0; elem < size; ++elem) {
        arr[elem] += c;
    }
}

//int main() {
//    int arreglo[] = {11, 2, 7, 1, 10};
//    int tamano = sizeof(arreglo) / sizeof(arreglo[0]); 

//    // imprimo el arreglo antes de sumar c
//    printf("Arreglo antes de sumar %d a cada elemento:\n", 3);
//    for (int i = 0; i < tamano; ++i) {
//        printf("%d ", arreglo[i]);
//    }
//    printf("\n\n");

//    // imprimo el arreglo despues de sumar c
//    sumador(arreglo, tamano, 3);

//    printf("Arreglo después de sumar %d a cada elemento:\n", 3);
//    for (int i = 0; i < tamano; ++i) {
//        printf("%d ", arreglo[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

char* copiar( char* arr ) {
    int tamano = strlen(arr); //strlen calcula el tamaño de un array de chars
    
    char* copied_array = malloc((tamano + 1) * sizeof(char)); // +1 para el carácter nulo de terminación
    if (copied_array == NULL) {
        return NULL; // por si malloc falla
    }
    
    strcpy(copied_array, arr); //strcpy copia el arreglo original a la copia

    return copied_array;
}

//int main() {
//    char original[] = "Hello, world!";

//    char* copia = copiar(original);

//    if (copia == NULL) {
//        printf("Error: No se pudo copiar el array de caracteres.\n");
//        return 1;
//    }

//    // Imprimir el array original y la copia
//   printf("Array original: %s\n", original);
//    printf("Array copia: %s\n", copia);

//    free(copia); // libero la memoria que use para hacer la copia

//   return 0;
//}


int* reverse( int* arr, int size ) {
    int* reversed_arr = createArrayDyn(size, 0);
    if (reversed_arr == NULL) {
        printf("Failed to create array.\n");
        return NULL;
    } 

    for (int i = 0; i < size; ++i ) {
        reversed_arr[i] = arr[size - i - 1];
    }

    return reversed_arr;
}


int main() {
    int original[] = {1, 2, 3, 4, 5}; // Ejemplo de un array de enteros
    int tamano = sizeof(original) / sizeof(original[0]); // Calculamos el tamaño del array

    // Llamada a la función reverse para obtener el array invertido
    int* invertido = reverse(original, tamano);
    if (invertido == NULL) {
        printf("Error: No se pudo invertir el array.\n");
        return 1; // Salir del programa con un código de error
    }

    // Imprimir el array original y el array invertido
    printf("Array original: ");
    for (int i = 0; i < tamano; ++i) {
        printf("%d ", original[i]);
    }
    printf("\n");

    printf("Array invertido: ");
    for (int i = 0; i < tamano; ++i) {
        printf("%d ", invertido[i]);
    }
    printf("\n");

    // Liberar la memoria asignada para el array invertido
    free(invertido);

    return 0; // Salir del programa con éxito
}