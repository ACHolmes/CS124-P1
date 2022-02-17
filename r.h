#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <float.h>

float rand01(void)
{
    return (float) rand()/RAND_MAX;
}
