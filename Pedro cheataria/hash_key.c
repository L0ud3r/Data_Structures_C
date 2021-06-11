#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 1000000

//Resolucao PeRaDi (modificada)
int getHash(const char * x) {
   int counter = 0;

   for (int i = 0; i < strlen(x); i++) {
       counter += x[i];
   }

   return counter % M;
}
