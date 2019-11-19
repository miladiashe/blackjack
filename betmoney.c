#include <stdio.h>
#include <stdlib.h>

void betmoney()
/*돈 거는 데 쓰는 함수*/ 
{
	extern int mymoney[];
	extern int bet[];
	printf("얼마를 거시겠습니까? \n 현재 가진 금액 : %i\n", mymoney[0]);
	bet[0] = getIntegerInput();
	mymoney[0] = mymoney[0] - bet[0];
	/* 내 돈을 거는 부분*/
	srand((unsigned)time(NULL));

	/*NPC의 돈을 거는 부분*/ 
	/*랜덤함수 이용, N_MAXBET 사이에 랜덤하게 돈을 건다.*/ 
}
