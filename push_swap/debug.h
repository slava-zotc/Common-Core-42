#ifndef DEBUG_H
# define DEBUG_H
#include <stdio.h>

# ifdef DEBUG
#  define DEBUG_PRINT(x) x
# else
#  define DEBUG_PRINT(x)
# endif

#endif
