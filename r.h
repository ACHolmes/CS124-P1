#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <float.h>
#include "time.h"

// Random number in 0-1 helper function
float rand01(void)
{
    return (float) rand()/RAND_MAX;
} 