#include <stdio.h>
#include <stdlib.h>
int gostop()
{
	extern int playerstatus[];
	int gostop;
	printf("�� �� �� �ް� �����ø� 1��, �׸� �ް� �����ø� 0�� �Է��� �ּ���. \n");
	printf("�ٸ� �Է��� 0���� �����մϴ�. �����ϼ���.\n");
	gostop = getIntegerInput();
	if (gostop == 1)
	{
		printf("\n�� �� �� �帮�ڽ��ϴ�.\n");
		givemorecard(0);
		sumcards(0);
		checksum21(0);
		printingamecard(0);
		if (playerstatus[0] == 21)
		{
			printf("\n���ϵ帳�ϴ�.\n"); 
		}
		else if (playerstatus[0] > 21)
		{
			printf("\n ��Ÿ������.\n"); 
		}
		
		
	}
	else
	{
		printf("\n�˰ڽ��ϴ�.\n");
		playerstatus[0] = 2;

	} 
}
/*�÷��̾� �� ����, ī�带 ������ ���� �ൿ�� ���ϴ� �Լ�*/ 
int npcgo(int playernum)
{
	extern int mycardsum[];
	extern int N_player;
	extern int playerstatus[];
	int dealer = 0;
	/*���� ����, �ٸ� ��� ����ϴ� �뵵*/ 
	if (playernum =  N_player)
	{
		dealer = 1;
	}
	if (mycardsum[playernum]<17)
	{
		/*�ڵ� go*/ 
		givemorecard(playernum);
		sumcards(playernum);
		checksum21(playernum);
		printingamecard(playernum);
	}
	else
	{
		/*stop*/ 
		playerstatus[playernum] = 2;
	}
}
/*npc�� �ൿ�� �����ϴ� �Լ�*/ 
