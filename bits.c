/* 
 * <Please put your name and userid here>
 * Pranav Kanchi, pk2296
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions confor *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int a, b;
  a = ~(x & y);
  b =  ~(~x & ~y);
  return a & b;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  int onePlus, y;
  onePlus = x+1;
  y = x+onePlus;
  onePlus = !onePlus;
  y = ~y;
  y = y | onePlus;
  y = !y;
  return y;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  x = x & x >> 16;
  x = x & x >> 8;
  x = x & x >> 4;
  x = x & x >> 2;
  return (x >> 1) & 1;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int returnMe = (!((x+~48+1)>>31))&!!((x+~58+1)>>31);
  return returnMe;
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int a;
  x = !!x;
  x = ~x+1;
  a = (x&y) |(~x&z);
  return a;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {  
  int signx, signy, yMinusX, signYMinusX, bothPos, result;
  signx = (x>>31);
  signy = (y >> 31);
  signx = !!signx;
  signy = !!signy;
  yMinusX = y + (~x+1);
  signYMinusX = yMinusX>>31;
  signYMinusX = !!signYMinusX;
  bothPos = !(signx^signy);
  result = (signx & !signy) | (bothPos & !signYMinusX);
  return result;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int y = ((x | (~x + 1)) >> 31) + 1;
  return y;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int sign, y, z, sixteenth_bit, eighth_bit, fourth_bit, second_bit, first_bit, returnMe;
  sign = x >> 31;
  y = (sign & ~x);
  z = (~sign & x);
  x = y | z;
  sixteenth_bit = !!(x >> 16) << 4;
  x = x >> sixteenth_bit;
  eighth_bit = !!(x >> 8) << 3;
  x = x >> eighth_bit;
  fourth_bit = !!(x >> 4) << 2;
  x = x >> fourth_bit;
  second_bit = !!(x >> 2) << 1;
  x = x >> second_bit;
  first_bit = !!(x >> 1);
  x = x >> first_bit;
  returnMe = sixteenth_bit+eighth_bit+fourth_bit+second_bit+first_bit+x+1; 
 return returnMe;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned exp = uf & 0x7f800000;
  unsigned mantissa = uf&0x007fffff;
  unsigned returnMe;
  if (exp == 0){
	return sign | uf << 1;
  }
  if (exp == 0x7f800000) {
	return uf;
  }
  exp = exp + 0x00800000;
  if (exp == 0x7f800000) {
	mantissa = 0;
  }
  returnMe = sign | exp | mantissa;
  return returnMe;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int sign, bits, mantissa, exp, round;
  unsigned returnMe;
  //outside cases
  if(x == 0){
	return 0;
  }
  if(x == 0x80000000){
	return 0xCF000000;
  }
  //isolate the sign
  sign =!!(x>>31);
  if(sign){
	x = -x;
  }
  //calculate the number of bits used
  bits = 1;
  while ((x >> bits) != 0){
	bits += 1;
  }
  bits -= 1;
  //build parts of float
  exp = 0x7f + bits;  
  x = x << (31-bits);
  mantissa = (x>>8)&0x7fffff;
  if(bits > 23){
	round = x &0xff;
	if ((round > 0x80) || ((round == 0x80) && (mantissa & 1))) {
		mantissa += 1;
		if(mantissa >> 23){
			exp += 1;
			mantissa = 0;
		}
	}
  }
  returnMe = (sign << 31) | (exp << 23) | mantissa;
  return returnMe;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  int sign, exp, mantissa;
  sign = uf >> 31;
  exp = (uf & 0x7f800000)>>23;
  exp = exp - 0x7F;
  mantissa = (uf&0x007FFFFF) | 0x00800000;
  //fraction case, round to zero
  if(exp <0){
	return 0;
  }
  if (exp > 31) {
	return 0x80000000;
  }
  if (exp <= 23) {
	mantissa = mantissa >> (23 - exp);
  }
  if (exp > 23) {
  	mantissa  = mantissa << (exp - 23);
  } 
  if (!((mantissa >> 31) ^ sign)) {
	return mantissa;
  } else if(mantissa  >> 31){
	return 0x80000000;
  } else {
	return ~mantissa + 1;
  }
  }
