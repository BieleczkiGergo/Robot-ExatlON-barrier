/* 
 * Robot ExatlON password-protected barrier
 */

#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

#include "config.h"
#include "version.h"
#include "keyMatrix.h"

char pass[PASS_LEN];
byte cursor = 0;


LiquidCrystal lcd( RS, EN, DB4, DB5, DB6, DB7 );
Keypad kp = Keypad( makeKeymap(keys), row_pins, col_pins, ROWS, COLS );

void print_pass();

void setup()
{
  lcd.begin( 16, 2 );
  lcd.print( "*UwU* " VERSION );
  pass[0] = '\0';
  print_pass();
  pinMode(SERVO, OUTPUT);
  
}

void loop()
{
  char key = kp.getKey(); // For some reason, it doesn't work if key is static

  if( !key )
    return;

  if(key == 'C') // Delete 1 character backwards
  {
    pass[min(cursor, PASS_LEN - 1)] = '\0';
    cursor = max(0, cursor-1);

  }else if(key == 'D') // Delete whole line
  {
    cursor = 0;
    for(int i=0; i<PASS_LEN; i++)
    {
      pass[i] = '\0';
    }


  }else
  {
    if(cursor < PASS_LEN)
      pass[cursor] = key;
    cursor = min( cursor + 1, PASS_LEN );

  }
    
  print_pass();

  if( 0 == strncmp(pass, CORRECT_PASS, PASS_LEN) )
    analogWrite(SERVO, SERVO_OPEN);
  else
    analogWrite(SERVO, SERVO_CLOSED);
    
  delay(50);
  
}

void print_pass()
{
  byte i = 0;
  for(; i < cursor; i++)
  {
    lcd.setCursor(i, 1);
    lcd.write(pass[i]);

  }
  for(; i < PASS_LEN; i++)
  {
    lcd.setCursor(i, 1);
    lcd.write((char) '_'); // It's there so that if you decide to use an integer, you are free to do so

  }
  
}
