#include "Header.h"

LiquidCrystal lcd3(8,9,10,11,12,13);

Operation::Operation()
{
  oper = 0;
}

Operation::~Operation(){}

void Operation::SetOper(int auxValue)
{
  oper = auxValue;
}

void      Operation::DisplayObject()
{
  char outputString[2] = {' ', '\0'};
  
  switch(oper)
  {
    case 1: outputString[0] = '+';
            break;
    case 2: outputString[0] = '-';
  }
  
  lcd3.print(outputString);
}

const int Operation::GetOper()
{
  return oper;
}
