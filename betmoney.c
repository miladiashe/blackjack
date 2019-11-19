#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void betmoney()
/*돈 거는 데 쓰는 함수*/ 
{
	extern N_player;
	extern int mymoney[];
	extern int bet[];
	printf("얼마를 거시겠습니까? \n 현재 %i 달러를 가지고 계십니다.\n", mymoney[0]);
	bet[0] = getIntegerInput();
	mymoney[0] = mymoney[0] - bet[0];
	/* 내 돈을 거는 부분*/
	srand((unsigned)time(NULL));
	int tmpplr;
	for	(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		do
		{
		bet[tmpplr] = (rand()%N_MAXBET)+1;
		}
		while(bet[tmpplr]<0);
		/*0달러 이하로 돈이 계속 내려가도 계속 거는 걸 방지하기 위한 조건*/ 
		printf("NPC %i 꼐서는%i 달러를 거셨습니다.\n ", tmpplr, bet[tmpplr]);
		mymoney[tmpplr] = mymoney[tmpplr] - bet[tmpplr];
		printf("NPC %i님께 남은 돈은 %i 달러입니다.\n ", tmpplr, mymoney[tmpplr]);
	}
	/*NPC의 돈을 거는 부분*/ 
	/*랜덤함수 이용, 1과 N_MAXBET 사이에 랜덤하게 돈을 건다.*/ 
}
