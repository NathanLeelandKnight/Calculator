#include "Header.h"
LiquidCrystal lcd4(8,9,10,11,12,13);

CalculatorList::CalculatorList()
{
  head  = NULL;
  count = 0;
}

CalculatorList::~CalculatorList(){}

void CalculatorList::AddToList(Calculator *auxCalcPtr)
{ 
  auxCalcPtr->SetNext(head);
  
  if(GetSize() > 0)
  {
    auxCalcPtr->GetNext()->SetPrev(auxCalcPtr);
  }
  
  auxCalcPtr->SetPrev(NULL);
  head = auxCalcPtr;
  count++;
  
  auxCalcPtr = NULL;
}

void CalculatorList::DisplayList()
{
  Calculator *auxPtr;
  auxPtr = head;
  
  while(auxPtr != NULL)
  {
    lcd4.clear();
    lcd4.setCursor(0, 0);
    auxPtr->DisplayObject();
    auxPtr = auxPtr->GetNext();
    delay(2000);
  }
  auxPtr = NULL;
}

Calculator *CalculatorList::GetHead()
{
  return head;
}

int CalculatorList::GetSize()
{
  return count;
}

