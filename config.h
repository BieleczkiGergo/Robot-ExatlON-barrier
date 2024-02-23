#ifndef CONFIG_H
#define CONFIG_H

/* Pinouts config
 * 
 */

//----- LCD --------------
#define RS 0
#define EN 1
#define DB4 2
#define DB5 3
#define DB6 4
#define DB7 5


//----- servo motor ------
#define SERVO 10


//----- keymatrix --------
// see: keyMatrix.h


/* Servo config
 * 
 */
#define SERVO_OPEN 127
#define SERVO_CLOSED 0


/* Password
 * 
 */
#define CORRECT_PASS "12345678"
#define PASS_LEN 8

#endif
