/*********************************************************
 * Diego Lopez
 *
 * quadratic_solver.c - This program calculates the roots
 * of a  quadratic equation using the quadratic formula.
 *********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define GUESS_THRESHOLD 0.000000001

#define EXIT_VALID 0
#define EXIT_BADINPUT 1
#define EXIT_DISCRIMINANT_NEGATIVE 2
#define EXIT_DISCRIMINANT_ZERO 3

int main();
double myreaddouble();
double mysqrt(double n);
double myabs(double n);
double getroot(double a, double b, double c, int positive);

int main() {
  double a, b, c;
  double result;

  printf("This program solves a quadratic equation using the quadratic "
         "formula.\n");
  printf("For the form ax^2 + bx + c = 0 please enter the following:\n");

  printf("a=");
  a = myreaddouble();

  printf("b=");
  b = myreaddouble();

  printf("c=");
  c = myreaddouble();

  // You could uncomment this to debug the values or a b and c:
  printf("a b c %lf %lf %lf\n", a, b, c);

  result = getroot(a, b, c, 1);
  printf("The positive root is %lf\n", result);

  result = getroot(a, b, c, 0);
  printf("The negative root is %lf\n", result);

  return 0;
}

/*
 * This function reads a 'double' from the keyboard (standard intput)
 * and returns it.
 */
double myreaddouble() {
  // TODO: Implement this function.
   
  double n;
  int numChecker;

  //Origional scanf() solution
  // char txtChecker;
  //  scanf("%lf", &n);
  // numChecker = (int)n;
  // txtChecker = (char)n;
  

  // if(n != numChecker || txtChecker != n){
  //   printf("Invalid input.\n");
  //   exit(EXIT_VALID);
  // }
  //  return n;

  //Using getchar() bonus!!! //****************************
  char c = getchar();
  n = (double)c;
  numChecker = (int)c;

  if(c != numChecker || c != n){
    printf("Invalid input.\n");
    exit(EXIT_VALID);
  }
  
  return ((int)c-48);
}

//****************************

/*
 * This function returns the square root of a provided double.
 */
double mysqrt(double n) {
  
  if (n == 0.0) {
    return (0);
  }
  if (n < 0.0) {
     printf("mysqrt cannot accept negative numbers.\n");
      exit(EXIT_BADINPUT);
  }
  
  double guess = n;

  double movementDistance = n / 2.0;

  while (myabs((guess * guess) - n) > GUESS_THRESHOLD) {
    if (guess * guess < n) {
      guess = guess + movementDistance;
    } else {
      guess = guess - movementDistance;
    }
    movementDistance = movementDistance / 2.0; 
    
  }
  return guess;
  }

  /*
   * This function returns the absolute value of a provided double.
   * ie, 123 returns 123
   *     -456 returns 456
   *     0 returns 0
   */
  double myabs(double n) {
    
    if (n < 0.0) {
      n *= -1.0;
      return n;
    }

    return n;
  }

/*
 * This function returns the positive or negative root of the quadratic formula provided with      * three variable doubles and an integer 1 or 0.
 */
  double getroot(double a, double b, double c, int positive) {
    double discriminat = (b*b - 4 * a * c);
      if (discriminat < 0) {
        printf("The discriminant is negative. There are no real roots.\n");
        exit (EXIT_DISCRIMINANT_NEGATIVE);
      }
      if (discriminat == 0) {
        printf("The discriminant is zero. There is only one real root.\n");
        exit (EXIT_DISCRIMINANT_ZERO);
      }
  // calculate roots using quadratic formula
  // positive root
  double positiveRoot = ((-b + mysqrt(discriminat))) / (2.0 * a);
  // negitive root
  double negativeRoot = ((-b - mysqrt(discriminat))) / (2.0 * a);
    
      if(positive == 0){
        return negativeRoot;
      }
        return positiveRoot;
    
    return 0;
    
  }

// to compile: gcc -Wall -std=c99 quadratic_solver.c -o start1
// to run: ./start1
