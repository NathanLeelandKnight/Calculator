#include "Header.h"

Calculator::Calculator()
{
  next      = NULL;
  prev      = NULL;
}

Calculator::~Calculator(){}

void Calculator::SetNext(Calculator *auxPtr)
{
  next = auxPtr;
}

void Calculator::SetPrev(Calculator *auxPtr)
{
  prev = auxPtr;
}

void Calculator::DisplayObject(){}

Calculator *Calculator::GetNext()
{
  return next;
}

Calculator *Calculator::GetPrev()
{
  return prev;
}
