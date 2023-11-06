#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const float PI = 3.14;

struct humanData{
  float firstNumber;
  float secondNumber;
  char symbol;
};

struct isResult{
  bool isCorrect;
  float number;
};

float getNumber() {
    char humanInput[5];
    float number;

    printf("Write a number (a for pi(3.14)): ");
  
    scanf("%s", &humanInput);

    if (strcmp(humanInput, "a") == 0) {
        number = PI;
    } else {
       number = atof(humanInput);
    }
    return number;
}

char getSymbol()
{
  char symbol;
  printf("Write a symbol (+, -, x): ");
  scanf(" %c", &symbol);

  return symbol;
}

struct isResult getResult(struct humanData data) 
{

  struct isResult resultObj; 
  resultObj.isCorrect = true;

  float firstNumber = data.firstNumber;
  float secondNumber = data.secondNumber;
  char symbol = data.symbol;

  switch (symbol)
  {
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


int main()
{

  struct humanData data;
  struct isResult result;

  printf("------- Welcome to MY CALCULATOR -------\n");
  
  data.firstNumber = getNumber();

  printf("---------------------------\n");

  data.secondNumber = getNumber();

  printf("---------------------------\n");

  data.symbol = getSymbol();

  result = getResult(data);

  system("cls");

  if (result.isCorrect){
    printf("Result %.2f %c %.2f = %.2f", data.firstNumber, data.symbol, data.secondNumber, result.number);
  }else{
    printf("Los parámetros no son correctos");
  }

  
  
  return 0;

}
