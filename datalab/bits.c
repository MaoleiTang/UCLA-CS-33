/*
 * CS:APP Data Lab
 *
 * Maolei Tang   UID:604501038
 *
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
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
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
  int x_sign, inverse_x, sample, count, index, shift, test_zero_at_last_bit,
      shift_sign, temp, test;
  x_sign=x>>31;               //get sign bit
  inverse_x=x^x_sign;         //get inverse x
  sample=inverse_x;           
  count=0;
  count=count+!sample;            
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  sample=sample>>2;
  count=count+!sample;
  count=count+count;
  index=count;
  shift=32+~index+1;
  test_zero_at_last_bit=!shift;
  shift_sign=32+~index+test_zero_at_last_bit;   //prevent overflow
  temp=inverse_x;
  temp=temp>>shift_sign;
  test=temp&1;
  shift=shift+test+test_zero_at_last_bit;  
  return shift;
}
/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  int sign, constant, result, sign_increment;
  sign=x>>31;    //sign=111... if x negative; sign=000.. if x nonnegative
  constant=127;    //constant = 01111111
  constant=constant<<8;
  constant=constant+0xff;
  constant=constant<<8;
  constant=constant+0xff;
  constant=constant<<8;
  constant=constant+0xff;   //constant =0111111...
  sign=sign&constant; //sign =0111...if x negative; sign=0000..if x nonnegative
  result=x^sign;  //get -x if x negative; x if x nonegative
  sign_increment=!!sign; //=1 if x negative; =0 if x nonnegative
  result=result+sign_increment; 
  return result;
}
/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  int x1=x>>31;             //x=0xffffffff=-1 if x is negative, otherwise 0;
  return x1+1;
}

/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
  //--rotate left version
  // int remain_bits=32+~n+1;      //get 32-n
  // //-32*!(n)
  // int eliminate_zero_effect1=!n;
  // eliminate_zero_effect1=eliminate_zero_effect1<<5;
  // eliminate_zero_effect1=~eliminate_zero_effect1+1;
  // // int test_zero=!n;
  // // remain_bits=remain_bits+~test_zero+1;
  // remain_bits=remain_bits+eliminate_zero_effect1; //get 0~31
  // int constant=1<<31;
  // constant=constant>>remain_bits;
  // int eliminate_zero_effect2=!n;
  // int shift=1+~eliminate_zero_effect2+1;
  // constant=constant<<shift;
  // constant=~constant;           //get 0000...1111
  // int x1=x>>remain_bits;
  // x1=x1&constant;
  // int x2=x<<n;
  // int result=x1+x2;
  // return result;

  //   8   7
  // 10000111
  //   8  0
  // 10000000 00000000 .....  00000000
  // 0100
  //================================================

  int remain_bits, eliminate_zero_effect, x1, constant, x2, result;
  remain_bits=32+~n+1;      //get 32-n
  eliminate_zero_effect=!n;
  eliminate_zero_effect=eliminate_zero_effect<<5;
  eliminate_zero_effect=~eliminate_zero_effect+1;
  remain_bits=remain_bits+eliminate_zero_effect; //get 0~31
  x1=x>>n;
  constant=~0;
  constant=constant<<remain_bits;
  constant=~constant;
  x1=x1&constant;
  x2=x<<remain_bits;
  result =x1+x2;
  return result;

// no sign overflow version, but exceed 4 operators
// int remain_bits, eliminate_zero_effect, x1, constant, x3,result,
//   negative_n, not_zero, x4, x5, n_minor_one;
//   not_zero=~0;
//   negative_n=~n+1;                 //-n
//   remain_bits=32+negative_n;      //get 32-n
//   eliminate_zero_effect=!n;       // not n
//   eliminate_zero_effect=eliminate_zero_effect<<5;  //32*n
//   eliminate_zero_effect=~eliminate_zero_effect+1;  //-32*n
//   remain_bits=remain_bits+eliminate_zero_effect; //get 0~31
//   x1=x>>n;
//   constant=not_zero;
//   constant=constant<<remain_bits;
//   constant=~constant;
//   x1=x1&constant;   //first part

//   n_minor_one=n+~1+1+eliminate_zero_effect;  //n-1
//   x3=x>>n_minor_one;
//   x3=x3&1;
//   x4=(not_zero+(!x3))>>31;
//   x4=x4<<31;                  //get 1000...  negative,  0000..positve
//   x5=~(not_zero<<n_minor_one);
//   x5=x5&x;
//   x5=x5<<remain_bits;
//   result=x5+x4+x1;
//   return result;
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  int sign, test_zero, sign_test, temp3, temp4, temp5, contain_zero,
      test_contain_zero, result;
  sign=x>>31;     
  test_zero=!!n;    //get 0 when n=0; elsewise 1
  sign_test=sign&1;    //get 1 when negative; elsewise 0      
  temp3=sign_test&test_zero;
  temp4=x>>n;
  temp5=temp4<<n;
  contain_zero=x^temp5;
  test_contain_zero=!!contain_zero;
  temp3=temp3&test_contain_zero;
  result=temp3+temp4;
  return result;
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int n;
  int step;
  int negative_n;
  int result;
  n=0x55;
  n=n<<8;
  n=n+0x55;
  n=n<<8;
  n=n+0x55;
  n=n<<8;
  n=n+0x55;   
  n=~n;         //n=0xaaaaaaaa
  step=x&n;  //get 0xaaaaaaaa if all odd-numbered bits set to 1
  negative_n=~n+1;
  result=step+negative_n;  //get 0 if satisfy
  return !result;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int exp1, not_x, not_y, exp2, exp3, exp4;
  exp1=x&y;      //get int where 1 represents both have 1 at that bit
  not_x=~x;
  not_y=~y;
  exp2=not_x&not_y;  //get int where 1 represents both have 0 at that bit
  exp3=~exp1;    //get int where 0 represents both have 1 at that bit
  exp4=~exp2;    //get int where 0 represents both have 0 at that bit
  return exp3&exp4;
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
 int isTmin(int x) {
  int exp1;
  int exp2;
  int exp3;
  exp1=x+x;       //get 0 when x =Tmin or 0, elsewise other value
  exp2=!exp1;      //get 1 when x =Tmin or 0, elsewise 0
  exp3=!!x;       //get 0 when x =0, elsewise 1 
  return exp2&exp3;
}

