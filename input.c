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

int reading(){
	int ok = 0
;	do
	{
		printf("\n확인하셨다면 아무 키나 입력해주세요.(0 제외)");
		ok = getIntegerInput();
	}
	while(ok == 0);
	/*너무 많은 줄이 빠르게 지나가서, 스토리를 한줄씩 넘길 수 있는 게임처럼 중간중간에 끊어서 입력을 받는 기능을 구현 시도해본다.*/ 
}
