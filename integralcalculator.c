
#include <stdio.h>
#include "hw1_lib.h"
#include <math.h>
/* please add -lm when compiling at the end of the command */

/* for the calculations of the integral we need a function which returns the evaluated value of the polynomial at given point 
so that i decided to create an extra function to do that job instead of complicated loops in the integral functions*/
/*poly3_i: FUNCTION FOR INTEGRAL 3 poly4_i: FUNCTION FOR INTEGRAL 4*/
double poly3_i(double a0, double a1, double a2, double a3,double x){ /* x variable is the given point which will be calculated in polynomial */
	double coeffs[4]; /* coefficient array of the polynomial */
	int i;		
	double sum=0.0; /* sum value is 0 at the beginning */
	coeffs[3]= a0; coeffs[2]= a1; coeffs[1]= a2; coeffs[0]= a3; /* coefficients  of the given polynomial assigned to the array manually */
	for(i=3;i>-1;i--){ /* at each iteration, each term of the polynomial is calculated one by one and it's value added to variable "sum" */
		sum+=coeffs[i]*pow(x,i);
	}
	return sum; /* function returns the sum value which is result of the given polynomial at the given point */
}
double poly4_i(double a0, double a1, double a2, double a3, double a4, double x){ /* x variable is the given point which will be calculated in polynomial */
	double coeffs[5]; /* coefficient array of the polynomial */
	int i;
	double sum=0.0; /* sum value is 0 at the beginning */
	coeffs[4]= a0; coeffs[3]= a1; coeffs[2]= a2; coeffs[1]= a3; coeffs[0]= a4; /* coefficients  of the given polynomial assigned to the array manually */
	for(i=4;i>-1;i--){	/* at each iteration, each term of the polynomial is calculated one by one and it's value added to variable "sum" */
		sum+=coeffs[i]*pow(x,i);
	}
	return sum; /* function returns the sum value which is result of the given polynomial at the given point */
}
double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
  double h,x,sum=0.0,result;
  int n= fabs(xe-xs)/delta; /* n:number of intervals, delta: given step size */
  int i=0;
  while(i<n-1){ /* until we reach the last interval...*/
    	x=xs+(i+1)*delta; /* we are adding the step size to start point at each iteration of the loop and finding the new point which is "x" */
    	sum+=poly3_i(a0,a1,a2,a3,x); /*then we are calculating the new point's(x) value in polynomial and adding that result to sum at each iteration */
    	i++;
  }
  double avarage = 0.5*(poly3_i(a0,a1,a2,a3,xs)+poly3_i(a0,a1,a2,a3,xe)); /* we have to find the avarage of the start and final's points values */
  result=(delta)*(avarage+sum); /* if we add up delta.avarage + delta.sum then according to trapozodial sum, result will give us the calculated value of the integral */
  printf("%f",result);
  return result;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
  double x,sum=0.0,result;
  int n=fabs(xe-xs)/delta; /* n:number of intervals, delta: step size */
  int i=0;
  	while(i<n-1){	/* until we reach the last interval...*/
    x=xs+(i+1)*delta; /* we are adding the step size to start point at each iteration of the loop */
    sum+=poly4_i(a0,a1,a2,a3,a4,x); /*then we are calculating the new point's(x) value in polynomial and adding that result to sum at each iteration */
    i++;
  }
  double avarage = 0.5*(poly4_i(a0,a1,a2,a3,a4,xs)+poly4_i(a0,a1,a2,a3,a4,xe)); /* we have to find the avarage of the start and final's points values */
  result=(delta)*(avarage+sum);	/* if we add up delta.avarage + delta.sum then according to trapozodial sum, result will give us the calculated value of the integral */
  printf("%f",result);
  return result;
}
