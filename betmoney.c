#include <stdio.h>
#include <stdlib.h>

void betmoney()
/*�� �Ŵ� �� ���� �Լ�*/ 
{
	extern int mymoney[];
	extern int bet[];
	printf("�󸶸� �Žðڽ��ϱ�? \n ���� ���� �ݾ� : %i\n", mymoney[0]);
	bet[0] = getIntegerInput();
	mymoney[0] = mymoney[0] - bet[0];
	/* �� ���� �Ŵ� �κ�*/
	srand((unsigned)time(NULL));

	/*NPC�� ���� �Ŵ� �κ�*/ 
	/*�����Լ� �̿�, N_MAXBET ���̿� �����ϰ� ���� �Ǵ�.*/ 
}
