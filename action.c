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
	extern int N_player;
	int dealer = 0;
	/*딜러 여부, 다른 대사 출력하는 용도*/ 
	if (playernum =  N_player)
	{
		dealer = 1;
	}
}
/*npc의 행동을 결정하는 함수*/ 
