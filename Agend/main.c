#include <stdio.h>
#include <stdlib.h>

// Ejercicio para practicar malloc, free y realloc 

struct Contact *listaContactos;
int size = 0;

struct Contact {
    char name[100];
    char phoneNumber[20];
    char email[100];
};


void menu(){
    printf("AGENDA DE CONTACTOS\n");
    printf("--------------------\n");
    printf("1) Agregar un nuevo contacto\n");
    printf("2) Listar contactos\n");
    printf("3) Eliminar contacto\n");
    printf("--------------------\n");

}

void addUser(){
    struct Contact contacto;

    printf("Escriba el nombre: ");
    scanf("%s",contacto.name);
    printf("Escribe el numero de telefono: ");
    scanf("%s",contacto.phoneNumber);
    printf("Escribe el email: ");
    scanf("%s",contacto.email);

    size = size + 1;
    struct Contact *newContactList = (struct Contact *)realloc(listaContactos, size * sizeof(int));

    if (newContactList != NULL){
        listaContactos = newContactList;
        listaContactos[size -1] = contacto;
        printf("USUARIO AGREGADO CON EXITO");
    }else{
        printf("ERROR AL CREAR EL USUARIO");
    }
}

int main(){
    
    int userSelect;
    listaContactos = (struct Contact *)malloc(size * sizeof(int));

    menu();
    scanf("%d", &userSelect);

    switch (userSelect)
    {
    case 1:
        addUser();
        break;
    case 2:
        printf("2");
        break;
    case 3:
        printf("4");
        break;
    default:
        printf("Opción no valida");
        break;
    }

    for (item)

    free(listaContactos);

    return 0;
}