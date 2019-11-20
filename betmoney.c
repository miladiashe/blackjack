#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void betmoney()
/*돈 거는 데 쓰는 함수*/ 
{
	extern N_player;
	extern int mymoney[];
	extern int bet[];
	printf("\n얼마를 거시겠습니까?\n현재 %i 달러를 가지고 계십니다.\n", mymoney[0]);
	do
	{
		bet[0] = getIntegerInput();
	}
	while(bet[0] > mymoney[0]);
	/*시간이 남으면 다시 입력할 떄 입력이 어떻게 틀렸는지 말해주는 조건문 구성*/ 
	mymoney[0] = mymoney[0] - bet[0];
	if (mymoney[0]>0)
	{
		printf("남은 돈은 %i 달러입니니다.\n", mymoney[0]);
	}
	else
	{
	printf("남은 돈을 모두 거셨습니다. 과연 승리할 수 있을까요?\n");
	}

	
	/* 내 돈을 거는 부분*/
	srand((unsigned)time(NULL));
	int tmpplr;
	for	(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		do
		{
		bet[tmpplr] = (rand()%N_MAXBET)+1;
		}
		while(bet[tmpplr] > mymoney[tmpplr]);
		/*0달러 이하로 돈이 계속 내려가도 계속 거는 걸 방지하기 위한 조건*/ 
		printf("\nNPC %i 님은 %i 달러를 거셨습니다.\n", tmpplr, bet[tmpplr]);
		mymoney[tmpplr] = mymoney[tmpplr]-bet[tmpplr];
		if (mymoney[tmpplr]>0)
		{
		printf("NPC %i 님께 남은 돈은 %i 달러입니다.\n", tmpplr, mymoney[tmpplr]);
		}
		else
		{
			printf("남은 돈을 모두 거셨습니다. 과연 승리할 수 있을까요?\n");
		}
		/*그냥 플레이의 재미를 위해 남은 돈이 없을 경우 다른 대사가 출력되도록 하였다.*/ 
	}
	/*NPC의 돈을 거는 부분*/ 
	/*랜덤함수 이용, 1과 N_MAXBET 사이에 랜덤하게 돈을 건다.*/ 
}

int findwinner()
{
	int maxmoney = 0;
	extern int mymoney[N_maxplayer];
	
	
	/*남은 mymoney 액수로 우승자를 찾아 우승자의 플레이어 번호를 반환하는 함수.*/ 
} 

int roundwinner()
{
	extern int playerstatus[N_maxplayer+1];
	extern int N_player;
	extern int iamwinner[N_maxplayer+1];
	if (playerstatus[N_player] == 21)
	{
		iamwinner[N_player] = 1
		/*딜러승리*/
		/*iamwinner[N_maxplayer+1]에 딜러 칸 말고 전부 0*/
	}
	/*각 라운드마다 이 함수로 우승자를 찾자*/ 
	takemymoney();
	
}
int takemymoney()
{
	extern int mymoney[N_maxplayer];
	extern int bet[N_maxplayer]; 
	extern int N_player;
	extern int iamwinner[N_maxplayer+1];
	int h;
	
	for (h=0; h<N_player; h++)
	{
		if (iamwinner[h]=0)
		{
			bet[h] = 0;
			/*베팅 액수는 초기화를 여기서 한다*/ 
		}
		else
		{
			mymoney[h] = (2*bet[h]);
			/*베팅한 금액의 두 배를 돌려준다.*/ 
			bet[h] = 0;
		}
	}
	/*베팅한 돈을 돌려주는 함수*/ 
}
