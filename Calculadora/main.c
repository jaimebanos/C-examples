#include <stdio.h>
#include <stdbool.h>


struct humanData{
  int firstNumber;
  int secondNumber;
  char symbol;
};

int getNumber()
{
  int number;
  printf("Write a number: ");
  scanf("%d", &number);

  return number;
}

char getSymbol()
{
  char symbol;
  printf("Write a symbol (+, -, x): ");
  scanf(" %c", &symbol);

  return symbol;
}

int getResult(struct humanData data)
{
  int result;
  int firstNumber = data.firstNumber;
  int secondNumber = data.secondNumber;
  char symbol = data.symbol;

  switch (symbol)
  {
    case '+':
      result = firstNumber + secondNumber;
      break;
      
    case '-':
      result = firstNumber - secondNumber;
      break;

    case 'x':
      result = firstNumber * secondNumber;
      break;

    default:
      result = 0;
      break;
  }

  return result;
  
}



int main()
{

  struct humanData data;
  int result;

  printf("------- Welcome to MY CALCULATOR -------\n");
  
  data.firstNumber = getNumber();

  printf("---------------------------\n");

  data.secondNumber = getNumber();

  printf("---------------------------\n");

  data.symbol = getSymbol();

  result = getResult(data);

  
  printf("Result %d %c %d = %d", data.firstNumber, data.symbol, data.secondNumber, result);
  
  return 0;

}