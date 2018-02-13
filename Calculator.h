#ifndef HEADER_CALCULATOR
#define HEADER_CALCULATOR

#include "Header.h"

class Calculator
{
  public:
    Calculator();
    virtual ~Calculator();
    
    // Mutators
    void SetNext(Calculator *auxPtr);
    void SetPrev(Calculator *auxPtr);
    
    // Accessors
    virtual void  DisplayObject();
    Calculator    *GetNext();
    Calculator    *GetPrev();
    
  private:
    Calculator *next;
    Calculator *prev;
};

#endif
