#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const float PI = 3.14;

struct humanData {
    float firstNumber;
    float secondNumber;
    char symbol;
};

struct isResult {
    bool isCorrect;
    float number;
};


void showResult(struct humanData data, float number){
  printf("\033[1;32m");  // Verde brillante
  printf("    %.2f\n%c   %.2f\n  -------\n    %.2f", data.firstNumber, data.symbol, data.secondNumber, number);
  printf("\033[0m");  // Restaurar color predeterminado
}



// Declaración de la función getResult
struct isResult getResult(struct humanData data);

float getNumber() {
    char humanInput[5];
    float number;

    printf("\033[1;34m");  // Azul brillante
    printf("Enter a number (a for pi): ");
    printf("\033[0m");  // Restaurar color predeterminado

    scanf("%s", humanInput);

    if (strcmp(humanInput, "a") == 0) {
        number = PI;
    } else {
        number = atof(humanInput);
    }
    return number;
}


// Implementación de la función getResult
struct isResult getResult(struct humanData data) {
    struct isResult resultObj;
    resultObj.isCorrect = true;

    float firstNumber = data.firstNumber;
    float secondNumber = data.secondNumber;
    char symbol = data.symbol;

    switch (symbol) {
        case '+':
            resultObj.number = firstNumber + secondNumber;
            break;
        case '-':
            resultObj.number = firstNumber - secondNumber;
            break;
        case 'x':
            resultObj.number = firstNumber * secondNumber;
            break;
        default:
            resultObj.isCorrect = false;
            break;
    }

    return resultObj;
}

// Devuelve el símbolo introducido
char getSymbol() {
    char symbol;

    printf("\033[1;34m");  // Azul brillante
    printf("Enter an operation (+, -, x): ");
    printf("\033[0m");  // Restaurar color predeterminado

    scanf(" %c", &symbol);

    return symbol;
}

int main() {
    struct humanData data;
    struct isResult result;

    printf("\033[1;34m");  // Azul brillante
    printf("--------------- Calculator ---------------\n");
    printf("\033[0m");  // Restaurar color predeterminado

    data.firstNumber = getNumber();

    printf("\033[1;34m");  // Azul brillante
    printf("----------------------------------------\n");
    printf("\033[0m");  // Restaurar color predeterminado

    data.secondNumber = getNumber();

    printf("\033[1;34m");  // Azul brillante
    printf("----------------------------------------\n");
    printf("\033[0m");  // Restaurar color predeterminado

    data.symbol = getSymbol();

    result = getResult(data);

    printf("\033[1;34m");
    printf("----------------------------------------\n");
    printf("\033[0m");

    if (result.isCorrect) {
       showResult(data, result.number);
    } else {
        printf("\033[1;31m");  // Rojo brillante
        printf("Invalid parameters\n");
        printf("\033[0m");  // Restaurar color predeterminado
    }

    return 0;
}

