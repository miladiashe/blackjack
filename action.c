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
		else if (playerstatus[0]>21)
		{
			printf("\n ��Ÿ������.\n"); 
		}
		else
		{
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
	if (mycardsum[playernum]<17)
	{
		/*�ڵ� go*/ 
		printf("\n�� �� �� �帮�ڽ��ϴ�.\n");
		givemorecard(playernum);
		sumcards(playernum);
		checksum21(playernum);
		printingamecard(playernum);
		if (playerstatus[playernum] == 21)
		{
			printf("\n���ϵ帳�ϴ�.\n"); 
		}
		else if (playerstatus[playernum]>21)
		{
			printf("\n ��Ÿ������.\n"); 
		}
		else
		{
		}
	}
	else
	{
		/*stop*/ 
		printf("\n�˰ڽ��ϴ�.\n");
		playerstatus[playernum] = 2;
	}
}
/*npc�� �ൿ�� �����ϴ� �Լ�*/ 

int dealergo()
{
	extern int mycardsum[];
	extern int N_player;
	extern int playerstatus[];
	if (mycardsum[N_player]<17)
	{
		/*�ڵ� go*/ 
		printf("\n�� �� �� �ްڽ��ϴ�.\n");
		givemorecard(N_player);
		sumcards(N_player);
		checksum21(N_player);
		printingamecard(N_player);
		if (playerstatus[N_player] == 21)
		{
			printf("\n����.\n"); 
		}
		else if (playerstatus[N_player]>21)
		{
			printf("\n ��Ÿ������.\n"); 
		}
		else
		{
		}
	}
	else
	{
		/*stop*/ 
		printf("\n����.\n");
		playerstatus[N_player] = 2;
	}
}
/*������ �ൿ�� �����ϴ� �Լ�. ��縸 �ٸ���.*/ 
