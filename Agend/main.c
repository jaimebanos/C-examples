#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char address[100];
};

void addContact(FILE *fptr, char *file_name);
void viewContacts(FILE *fptr, char *file_name);
void searchContact(FILE *fptr, char *file_name);
void deleteContact(FILE *fptr, char *file_name);

int main() {
    int choice;
    char file_name[20] = "contactos.txt";
    FILE *fptr;


    do {
        printf("\033[1;32m");
        printf("\n----------------------------------");
        printf("\033[1;34m");
        
        printf("\nSistema de Gestion de Contactos\n");
        printf("1. Agregar Contacto\n");
        printf("2. Ver Lista de Contactos\n");
        printf("3. Buscar Contacto\n");
        printf("4. Eliminar Contacto\n");
        printf("0. Salir\n");
        printf("Ingrese su eleccion: ");
        printf("\033[1;32m");
        printf("\n----------------------------------\n");
        printf("\033[0m");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(fptr, file_name);
                break;
            case 2:
                viewContacts(fptr, file_name);
                break;
            case 3:
                searchContact(fptr, file_name);
                break;
            case 4:
                deleteContact(fptr, file_name);
                break;
            case 0:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida. Intentelo de nuevo.\n");
        }

    } while (choice != 0);

    return 0;
}

void addContact(FILE *fptr, char *file_name) {
    struct Contact contacto;

    printf("\033[1;34m");
    printf("Escriba su nombre: \n");
    printf("\033[0m");
    scanf("%s", contacto.name);

    printf("\033[1;34m");
    printf("Escriba su email: \n");
    printf("\033[0m");
    scanf("%s", contacto.address);

    printf("\033[1;34m");
    printf("Escriba su telefono: \n");
    printf("\033[0m");
    scanf("%s", contacto.phone);

    fptr = fopen(file_name, "a");

    fprintf(fptr, 
        "Nombre: %s\nEmail: %s\nTelefono: %s\n*\n",contacto.name, contacto.address, contacto.phone
    );

    fclose(fptr);
}

void viewContacts(FILE *fptr, char *file_name) {

    printf("---------Agenda-----------\n");
    
    fptr = fopen(file_name, "r");
    
    if (fptr != NULL){
        char context[40];
        while(fgets(context, 40, fptr)) {
            if (context[0] != '*'){
                printf("%s", context);
            }else{
                printf("--------------------------\n");
            }
            
        }
        
    }else{
        printf("No hay ningún contacto");
    }

    fclose(fptr);

}

void searchContact(FILE *fptr, char *file_name) {
    char email [40];
    char context [40];
    int i = 0;
    struct Contact tempContact;
    bool isFind = false;

    printf("Escriba el email del usuario: ");
    scanf("%s", &email);

    fptr = fopen(file_name, "r");
    while(fgets(context, 40, fptr)) {
        char *token = strtok(context, " ");
        token = strtok(NULL, " ");
        if (context[0] != '*')
        {   
            char *token2 = strtok(token, "\n");
            
            switch (i)
            {
            case 0:
            
                strcpy(tempContact.name, token2);
                break;
            case 1:
                strcpy(tempContact.address, token2);
                break;
            case 2:
                strcpy(tempContact.phone, token2);
                break;
            default:
                break;
            }
            
            i++;
        }else

        {   
            if (strcmp(tempContact.address, email) == 0) {
                isFind = true;
                printf("---------CONTACTO-----------\n");
                printf("Nombre: %s\n", tempContact.name);
                printf("Email: %s\n", tempContact.address);
                printf("Telefono: %s\n", tempContact.phone);
                printf("--------------------------\n");
            }
        }
          
    }

    fclose(fptr);

    if (!isFind){
        printf("\nNo se ha encontrado el contacto");
    }
    
}

void deleteContact(FILE *fptr, char *file_name) {
    struct Contact tempContact;
    char context[40];
    char newText[200] = "";
    char email[40];
    int i = 0;
    
    printf("Escriba el email del usuario: ");
    scanf("%s", &email);

    fptr = fopen(file_name, "r");
    while(fgets(context, 40, fptr)) {
        char *token = strtok(context, " ");
        token = strtok(NULL, " ");
        
        if (context[0] != '*'){
            char *token2 = strtok(token, "\n");
            switch (i)
            {
            case 0:
                strcpy(tempContact.name, token2);
                break;
            case 1:
                strcpy(tempContact.address, token2);
                break;
            case 2:
                strcpy(tempContact.phone, token2);
                break;
            default:
                break;
            }
            
            i++;
            
        }else{

            i=0;

            if (strcmp(tempContact.address, email) != 0){
                snprintf(newText, sizeof(newText), "%sNombre: %s\nEmail: %s\nTelefono: %s\n*\n", newText, tempContact.name, tempContact.address, tempContact.phone);
            }
        }

    }

    fclose(fptr);


    fptr = fopen(file_name, "w");
    fprintf(fptr, newText);
    fclose(fptr);
    
}
