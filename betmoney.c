#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void betmoney()
/*�� �Ŵ� �� ���� �Լ�*/ 
{
	extern N_player;
	extern int mymoney[];
	extern int bet[];
	printf("�󸶸� �Žðڽ��ϱ�? \n ���� %i �޷��� ������ ��ʴϴ�.\n", mymoney[0]);
	bet[0] = getIntegerInput();
	mymoney[0] = mymoney[0] - bet[0];
	/* �� ���� �Ŵ� �κ�*/
	srand((unsigned)time(NULL));
	int tmpplr;
	for	(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		do
		{
		bet[tmpplr] = (rand()%N_MAXBET)+1;
		}
		while(bet[tmpplr]<0);
		/*0�޷� ���Ϸ� ���� ��� �������� ��� �Ŵ� �� �����ϱ� ���� ����*/ 
		printf("NPC %i ������%i �޷��� �ż̽��ϴ�.\n ", tmpplr, bet[tmpplr]);
		mymoney[tmpplr] = mymoney[tmpplr] - bet[tmpplr];
		printf("NPC %i�Բ� ���� ���� %i �޷��Դϴ�.\n ", tmpplr, mymoney[tmpplr]);
	}
	/*NPC�� ���� �Ŵ� �κ�*/ 
	/*�����Լ� �̿�, 1�� N_MAXBET ���̿� �����ϰ� ���� �Ǵ�.*/ 
}
