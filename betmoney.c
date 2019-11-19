#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void betmoney()
/*돈 거는 데 쓰는 함수*/ 
{
	extern N_player;
	extern int mymoney[];
	extern int bet[];
	printf("얼마를 거시겠습니까? \n 현재 가진 금액 : %i\n", mymoney[0]);
	bet[0] = getIntegerInput();
	mymoney[0] = mymoney[0] - bet[0];
	/* 내 돈을 거는 부분*/
	srand((unsigned)time(NULL));
	int tmpplr;
	for	(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		bet[tmpplr] = (rand()%N_MAXBET)+1; 
		printf("NPC %i의 베팅 액수 : %i\n ", tmpplr, bet[tmpplr]);
		mymoney[tmpplr] = mymoney[tmpplr] - bet[tmpplr];
		printf("NPC %i의 소지금 : %i\n ", tmpplr, mymoney[tmpplr]);
	}
	/*NPC의 돈을 거는 부분*/ 
	/*랜덤함수 이용, N_MAXBET 사이에 랜덤하게 돈을 건다.*/ 
}
