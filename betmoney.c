#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void betmoney()
/*�� �Ŵ� �� ���� �Լ�*/ 
{
	extern N_player;
	extern int mymoney[];
	extern int bet[];
	printf("\n�󸶸� �Žðڽ��ϱ�?\n���� %i �޷��� ������ ��ʴϴ�.\n", mymoney[0]);
	do
	{
		bet[0] = getIntegerInput();
	}
	while(bet[0] > mymoney[0]);
	/*�ð��� ������ �ٽ� �Է��� �� �Է��� ��� Ʋ�ȴ��� �����ִ� ���ǹ� ����*/ 
	mymoney[0] = mymoney[0] - bet[0];
	if (mymoney[0]>0)
	{
		printf("���� ���� %i �޷��Դϴϴ�.\n", mymoney[0]);
	}
	else
	{
	printf("���� ���� ��� �ż̽��ϴ�. ���� �¸��� �� �������?\n");
	}

	
	/* �� ���� �Ŵ� �κ�*/
	srand((unsigned)time(NULL));
	int tmpplr;
	for	(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		do
		{
		bet[tmpplr] = (rand()%N_MAXBET)+1;
		}
		while(bet[tmpplr] > mymoney[tmpplr]);
		/*0�޷� ���Ϸ� ���� ��� �������� ��� �Ŵ� �� �����ϱ� ���� ����*/ 
		printf("\nNPC %i ���� %i �޷��� �ż̽��ϴ�.\n", tmpplr, bet[tmpplr]);
		mymoney[tmpplr] = mymoney[tmpplr]-bet[tmpplr];
		if (mymoney[tmpplr]>0)
		{
		printf("NPC %i �Բ� ���� ���� %i �޷��Դϴ�.\n", tmpplr, mymoney[tmpplr]);
		}
		else
		{
			printf("���� ���� ��� �ż̽��ϴ�. ���� �¸��� �� �������?\n");
		}
		/*�׳� �÷����� ��̸� ���� ���� ���� ���� ��� �ٸ� ��簡 ��µǵ��� �Ͽ���.*/ 
	}
	/*NPC�� ���� �Ŵ� �κ�*/ 
	/*�����Լ� �̿�, 1�� N_MAXBET �����̿� �����ϰ� ���� �Ǵ�.*/ 
}

int findwinner()
{
	int maxmoney = 0;
	int i;
	int tmpwinner; 
	extern int mymoney[N_maxplayer];
	
	for(i = 0; i<N_maxplayer; i++)
    {
        if(mymoney[i] > maxmoney) 
            maxmoney = mymoney[i]; 
            /*mymoney[i]�� �� �� ���� ū ��  maxmoney��  ��� ��*/ 
    }
    for(i = 0; i<N_maxplayer; i++)
    {
        if(mymoney[i] == maxmoney) 
            tmpwinner = i; 
            /*maxmoney�� �� i���� tmpwinner�� �ִ´�.*/ 
    }
	return tmpwinner;
	
	/*���� mymoney �׼��� ����ڸ� ã�� ������� �÷��̾� ��ȣ�� ��ȯ�ϴ� �Լ�.*/ 
} 

int roundwinner()
{
	extern int playerstatus[N_maxplayer+1];
	extern int N_player;
	extern int iamwinner[N_maxplayer+1];
	extern int mycardsum[N_maxplayer+1];
	int s;
	if (playerstatus[N_player] == 21)
	{
		printf("���� �̰���ϴ�.\n");
		iamwinner[N_player] = 1;
		for(s=0; s<N_player; s++)
		{
			iamwinner[N_player] = 0;
		}
		/*�����¸�*/
		/*iamwinner[N_maxplayer+1]�� ���� ĭ ���� ���� 0*/
	}
	else if (playerstatus[N_player] == 1)
	{
		iamwinner[N_player] = 0;
		for(s=0; s<N_player; s++)
		{
			if(playerstatus[s] != 1)
			{
				iamwinner[s] = 0;
			}
			/*�������*/ 
		}
	}
	else
	{
		iamwinner[N_player] = 0;
		for(s=0; s<N_player; s++)
		{
			if (playerstatus[s] == 21)
			{
				iamwinner[s] = 1;
			}
			else if (mycardsum[N_player] < mycardsum[s])
			{
				iamwinner[s] = 1;
			}
			else
			{
				iamwinner[s] = 0;
			}
		}
	}

	
	/*�� ���帶�� �� �Լ��� ����ڸ� ã��*/ 
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
			/*���� �׼��� �ʱ�ȭ�� ���⼭ �Ѵ�*/ 
		}
		else
		{
			mymoney[h] = (2*bet[h]);
			/*������ �ݾ��� �� �踦 �����ش�.*/ 
			bet[h] = 0;
		}
	}
	printf ("\n%i�޷� �����̽��ϴ�. \n", mymoney[0]);
	for (h=1; h<N_player; h++)
	{
		printf ("\nNPC %i��, %i�޷� �����̽��ϴ�. \n", h, mymoney[h]);
	}
	/*������ ���� �����ִ� �Լ�*/ 
}
