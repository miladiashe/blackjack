#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void betmoney()
/*�� �Ŵ� �� ���� �Լ�*/ 
{
	extern N_player;
	extern int mymoney[];
	extern int bet[];
	printf("�󸶸� �Žðڽ��ϱ�? \n ���� ���� �ݾ� : %i\n", mymoney[0]);
	bet[0] = getIntegerInput();
	mymoney[0] = mymoney[0] - bet[0];
	/* �� ���� �Ŵ� �κ�*/
	srand((unsigned)time(NULL));
	int tmpplr;
	for	(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		bet[tmpplr] = (rand()%N_MAXBET)+1; 
		printf("NPC %i�� ���� �׼� : %i\n ", tmpplr, bet[tmpplr]);
		mymoney[tmpplr] = mymoney[tmpplr] - bet[tmpplr];
		printf("NPC %i�� ������ : %i\n ", tmpplr, mymoney[tmpplr]);
	}
	/*NPC�� ���� �Ŵ� �κ�*/ 
	/*�����Լ� �̿�, N_MAXBET ���̿� �����ϰ� ���� �Ǵ�.*/ 
}
