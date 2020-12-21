#ifdef DataStructure_Practice
/* C version */
#   ifndef DataStructure_Object
#       include <stdio.h>
#       include <stdlib.h>
#       include <stdbool.h>
#       include <string.h>
#   endif

/* C++ version */
#   ifdef DataStructure_Object
#       include <iostream>
#       include <string>
        using std::string;
#   endif

    typedef int Status;
#   define TRUE 1
#   define FALSE 0
#   define OK 1
#   define ERROR 0
#   define INFEASIBLE -1
#   define OVERFLOW -2

#   ifndef DataStructure_Work
#       ifndef DataStructure_Object
            typedef int ElemType;
#       endif
#   endif

#   ifdef DataStructure_Linear
#       define InitSize 100
#       define IncrementSize 10
#   endif

#   ifdef DataStructure_Matrix
#       define MaxSize 12500
#   endif
#endif

