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
	/*�����Լ� �̿�, 1�� N_MAXBET ���̿� �����ϰ� ���� �Ǵ�.*/ 
}

int findwinner()
{
	/*���� mymoney �׼��� ����ڸ� ã�� ������� �÷��̾� ��ȣ�� ��ȯ�ϴ� �Լ�.*/ 
} 
