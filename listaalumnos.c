#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Alumno
struct Alumno {
    char *nombre;
    int creditos;
    int semestre;
};

// Definición de la estructura Nodo
struct Nodo {
    struct Alumno alumno;
    struct Nodo *siguiente;
};

// Prototipos de funciones
struct Alumno crearAlumno(const char[], int, int);
struct Nodo* crearNodo(struct Alumno);
int insertarNodoOrdenadoCreditos(struct Nodo**, struct Nodo*);
void imprimirLista(struct Nodo*);

int main() {
    // Crear 5 instancias de estructuras Alumno
    struct Alumno alumno1 = crearAlumno("Juan Perez", 120, 6);
    struct Alumno alumno2 = crearAlumno("Maria Lopez", 90, 4);
    struct Alumno alumno3 = crearAlumno("Carlos Gomez", 150, 7);
    struct Alumno alumno4 = crearAlumno("Ana Martinez", 110, 5);
    struct Alumno alumno5 = crearAlumno("Pedro Rodriguez", 130, 6);
    
    // Crear la lista con las 5 instancias de Alumno
    struct Nodo *lista = NULL;
    
    // Insertar los nodos en la lista de forma ordenada por créditos
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno1));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno2));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno3));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno4));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(alumno5));
    
    // Imprimir la lista
    printf("Lista de Alumnos:\n");
    imprimirLista(lista);
    
    return 0;
}

// Función para crear un Alumno
struct Alumno crearAlumno(const char nombre[], int creditos, int semestre) {
    struct Alumno alumno;
    alumno.nombre = strdup(nombre);
    alumno.creditos = creditos;
    alumno.semestre = semestre;
    return alumno;
}

// Función para crear un Nodo
struct Nodo* crearNodo(struct Alumno alumno) {
    struct Nodo *nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->alumno = alumno;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un Nodo en la lista de forma ordenada por créditos
int insertarNodoOrdenadoCreditos(struct Nodo **lista, struct Nodo *nuevoNodo) {
    if (*lista == NULL || nuevoNodo->alumno.creditos >= (*lista)->alumno.creditos) {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
        return 1;
    }
    
    struct Nodo *temp = *lista;
    while (temp->siguiente != NULL && temp->siguiente->alumno.creditos > nuevoNodo->alumno.creditos) {
        temp = temp->siguiente;
    }
    
    nuevoNodo->siguiente = temp->siguiente;
    temp->siguiente = nuevoNodo;
    return 1;
}

// Función para imprimir la lista de Alumnos
void imprimirLista(struct Nodo *lista) {
    struct Nodo *temp = lista;
    while (temp != NULL) {
        printf("Nombre: %s, Créditos: %d, Semestre: %d\n", temp->alumno.nombre, temp->alumno.creditos, temp->alumno.semestre);
        temp = temp->siguiente;
    }
}
