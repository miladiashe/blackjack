#include <stdio.h>
#include <stdlib.h>

void playerconfig(){
	int N_player;
	/*�÷��̾��� ���� �����ϴ� ����*/ 
	printf("�� ���� ���� �Բ��Ͻðڽ��ϱ�?(�ִ� 4��)\n");
	scanf("%d", &N_player);
	
	int money[N_player+1]; 
		extern N_initmoney;
		/*�̺κ��� ���� �Լ�ó���ؼ�  ���� �����ϴ� �ٸ� �Լ���� ����.c ���Ϸ� �̵��� ��*/ 
		int intm;
		for (intm=0; intm<(N_player+1); intm++)
			money[intm] = N_initmoney;
	
}
