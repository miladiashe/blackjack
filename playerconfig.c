#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void playerconfig(){
	extern int N_player;
	do
	{
	/*�÷��̾��� ���� �����ϴ� ����*/ 
	printf("���� ���̺� ���� ���� ȯ���մϴ�. �� ���� ���� �Բ��Ͻðڽ��ϱ�?(�ִ� 4��)\n");
	N_player = getIntegerInput();
	}
	while ( N_player<1 || N_player>N_maxplayer-1);
	N_player++;
	
	extern mymoney[]; 
	int intm;
	for (intm=0; intm<N_player; intm++)
	{
		mymoney[intm] = N_initmoney;
	}
	/*money[0]�� �÷��̾�, 1���� ��ǻ�� ��� 1, 2, 3, 4*/ 

}
