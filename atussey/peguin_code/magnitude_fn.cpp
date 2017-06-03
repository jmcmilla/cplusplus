#include "magnitude_fn.h"

float mag(int array[]){
	float prod = 0;
	float sum = 0;
	float sqr = 0;
	for(int i=0; i <3; ++i){
		prod = array[i]*array[i];
		sum += prod;
	}
	return sum;
}
