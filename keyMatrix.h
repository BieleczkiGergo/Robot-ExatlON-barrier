#ifndef KEYMATRIX_H
#define KEYMATRIX_H

#define COLS 4
#define ROWS 4

byte row_pins[COLS] = { 6, 7, 8, 9 };
byte col_pins[ROWS] = { A3, A2, A1, A0 };

char keys[COLS][ROWS] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
  
};

#endif
