#ifndef HEADER_NUMBER
#define HEADER_NUMBER

#include "Header.h"

class Number: public Calculator
{
  public:
    Number();
    virtual ~Number();
    
    //Mutators
    void SetNumber(double auxNumber);
    void CalculateNumber(int auxNumber);
    void ToggleDecimal();
    
    //Accessors
    virtual void  DisplayObject();
    const double  GetNumber();
    const boolean GetDecimal();
    const int     GetDeciCount();
    const int     GetCount();
    
  private:
    double     number;
    boolean    decimal;
    int        count;
    int        deciCount;
};

#endif
