#include "Header.h"
LiquidCrystal lcd(8,9,10,11,12,13);

BinaryKeypad   myKey;
CalculatorList myList;
Number         *myNumber;
Operation      *myOper;
Calculator     *myCalc;

// Special characters that we'll use
byte UP_ARROW [8] = 
{
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte POW_SYMBOL [8] =
{
  B00100,
  B01010,
  B10001,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup()
{
  initDisplay();
  showWelcome();
  Serial.begin(9600);
}

void loop()
{
  myNumber = new Number;
  myOper   = new Operation;
  
  while(!myKey.GetSpecialChar())
  {
    myKey.SetKeyValue();
    
    if(!myKey.GetSpecialChar())
    {
      myNumber->CalculateNumber(myKey.GetKeyValue());
      lcd.clear();
      lcd.setCursor(0, 0);
      myNumber->DisplayObject();
    }
    else
    {
      switch(myKey.GetKeyValue())
      {
        /*******************************************************
         * FOR DECIMAL
         *******************************************************/
        case 16: myNumber->ToggleDecimal();
                 myNumber->DisplayObject();
                 myKey.ToggleSpecialChar();
                 break;
                 
        /*******************************************************
         * FOR NEGATING
         *******************************************************/
        case 17: // For negating number
                 break;
                 
        /*******************************************************
         * FOR OPERATION INPUT
         *******************************************************/
        case 18: lcd.clear();
                 lcd.setCursor(0, 0);
                 lcd.print("Enter Operator");
                 myKey.PauseUntilButtonReleased();
                 if(myNumber->GetDeciCount() != 1 || myNumber->GetCount() != 0)
                 {
                   myCalc = myNumber;
                   myList.AddToList(myCalc); // Add previous number to the list
                   myNumber = NULL;
                 }
                 myKey.SetKeyValue();
                 myOper->SetOper(myKey.GetKeyValue());
                 myCalc = myOper;
                 myList.AddToList(myCalc);     // Add operation to list
                 lcd.clear();
                 lcd.setCursor(0, 0);
                 myOper->DisplayObject();
                 myOper = NULL;
                 myCalc = NULL;
                 break;
                 
        /*******************************************************
         * FOR CLEARING INPUT
         *******************************************************/
        //case 20: // For clear button
        
        /*******************************************************
         * EQUAL BUTTON
         *******************************************************/
        //case 24: // for equal button
      }//END OF SWITCH
      
    }//END OF IF

    /***************************************************************
     * PAUSE
     ***************************************************************/
    myKey.PauseUntilButtonReleased();
  }//END OF WHILE LOOP
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Displaying");
  delay(2000);
  
  myList.DisplayList();
  
  lcd.clear();
  myKey.ToggleSpecialChar();
}//END OF VOID LOOP





/*****************************************************************************
 * DISPLAY PURPOSES ONLY
 *****************************************************************************/
void showWelcome() 
{
  lcd.clear();
  lcd.print(" -=> Yoooo! <=-");
  for (byte i = 0; i < 16; i += 1) 
  {
    delay(100);
    lcd.setCursor(i, 1);
    lcd.write(byte(255));
  }
  delay(500);
  lcd.clear();
}

void initDisplay() 
{
  // Create special characters
  lcd.createChar(0, UP_ARROW);
  
  // Initialize it
  lcd.begin(16,2);  
}





