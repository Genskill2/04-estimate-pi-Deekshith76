#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float wallis_pi(int x){
  float product = 1;
  float val;
  float pi_value;
  for (int i=1; i<=x;i++){
    val = (4*pow(i,2))/((4*pow(i,2))-1);
    product *= val;
  }
  pi_value = 2*product;
  return pi_value;
}
float wallis_pi(int);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

