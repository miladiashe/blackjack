#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void playerconfig(){
	extern int N_player;
	do
	{
	/*플레이어의 수를 지정하는 변수*/ 
	printf("블랙잭 테이블에 오신 것을 환영합니다. 몇 명의 상대와 함께하시겠습니까?(최대 4명)\n");
	N_player = getIntegerInput();
	}
	while ( N_player<1 || N_player>N_maxplayer-1);
	N_player++;
	
	extern mymoney[]; 
	int intm;
	for (intm=0; intm<N_player; intm++)
	{
		mymoney[intm] = N_initmoney;
	}
	/*money[0]은 플레이어, 1부터 컴퓨터 상대 1, 2, 3, 4*/ 

}
