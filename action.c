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
	}
	else
	{
		playerstatus[0] = 2;
	} 
}
/*�÷��̾� �� ����, ī�带 ������ ���� �ൿ�� ���ϴ� �Լ�*/ 
int npcgo(int playernum)
{
	extern int N_player;
	int dealer = 0;
	/*���� ����, �ٸ� ��� ����ϴ� �뵵*/ 
	if (playernum =  N_player)
	{
		dealer = 1;
	}
}
/*npc�� �ൿ�� �����ϴ� �Լ�*/ 
