#ifndef HEADER_CALCULATORLIST
#define HEADER_CALCULATORLIST

#include "Header.h"

class CalculatorList
{
  public:
    CalculatorList();
    ~CalculatorList();
    
    // Mutators
    void AddToList(Calculator *auxCalcPtr);
    
    // Accessors
    void       DisplayList();
    Calculator *GetHead();
    int        GetSize();
    
  private:
    Calculator *head;
    int        count;
};

#endif
