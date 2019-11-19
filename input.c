#include <stdio.h>
#include <stdlib.h>

int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    //문법 받을함수 = getIntegerInput(); 
    
    return input;
}
