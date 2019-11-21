#include <stdio.h>
#include <stdlib.h>
int gostop()
{
	extern int playerstatus[];
	int gostop;
	printf("한 장 더 받고 싶으시면 1을, 그만 받고 싶으시면 0을 입력해 주세요. \n");
	printf("다른 입력은 0으로 간주합니다. 주의하세요.\n");
	gostop = getIntegerInput();
	if (gostop == 1)
	{
		printf("\n한 장 더 드리겠습니다.\n");
		givemorecard(0);
		sumcards(0);
		checksum21(0);
		printingamecard(0);
		if (playerstatus[0] == 21)
		{
			printf("\n축하드립니다.\n"); 
		}
		else if (playerstatus[0]>21)
		{
			printf("\n 안타깝군요.\n"); 
		}
		else
		{
		}
	}
	else
	{
		printf("\n알겠습니다.\n");
		playerstatus[0] = 2;

	} 
}
/*플레이어 턴 전용, 카드를 받을지 말지 행동을 정하는 함수*/ 
int npcgo(int playernum)
{
	extern int mycardsum[];
	extern int N_player;
	extern int playerstatus[];
	if (mycardsum[playernum]<17)
	{
		/*자동 go*/ 
		printf("\n한 장 더 드리겠습니다.\n");
		givemorecard(playernum);
		sumcards(playernum);
		checksum21(playernum);
		printingamecard(playernum);
		if (playerstatus[playernum] == 21)
		{
			printf("\n축하드립니다.\n"); 
		}
		else if (playerstatus[playernum]>21)
		{
			printf("\n 안타깝군요.\n"); 
		}
		else
		{
		}
	}
	else
	{
		/*stop*/ 
		printf("\n알겠습니다.\n");
		playerstatus[playernum] = 2;
	}
}
/*npc의 행동을 결정하는 함수*/ 

int dealergo()
{
	extern int mycardsum[];
	extern int N_player;
	extern int playerstatus[];
	if (mycardsum[N_player]<17)
	{
		/*자동 go*/ 
		printf("\n한 장 더 받겠습니다.\n");
		givemorecard(N_player);
		sumcards(N_player);
		checksum21(N_player);
		printingamecard(N_player);
		if (playerstatus[N_player] == 21)
		{
			printf("\n블랙잭.\n"); 
		}
		else if (playerstatus[N_player]>21)
		{
			printf("\n 안타깝군요.\n"); 
		}
		else
		{
		}
	}
	else
	{
		/*stop*/ 
		printf("\n스톱.\n");
		playerstatus[N_player] = 2;
	}
}
/*딜러의 행동을 결정하는 함수. 대사만 다르다.*/ 
