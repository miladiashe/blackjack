#include <stdio.h>
#include <stdlib.h>

void playerconfig(){
	extern int N_player;
	do
	{
	/*�÷��̾��� ���� �����ϴ� ����*/ 
	printf("�� ���� ���� �Բ��Ͻðڽ��ϱ�?(�ִ� 4��)\n");
	N_player = getIntegerInput();
	}
	while ( N_player>0 || N_player<5);
	
	extern mymoney[]; 
	extern N_initmoney;
	int intm;
		for (intm=0; intm<N_player; intm++)
		{
			mymoney[intm] = N_initmoney;
		}
			/*���� �����ϴ� ������. �÷��̾� ���� �������̱� ������ �迭�� ����� �ô�. money[0]�� �÷��̾�, 1���� ��ǻ�� ��� 1, 2, 3, 4...*/ 
	/*if �Է¹��� ���ڰ� N_max_player ���� ������ �����޽��� ���� �ٽ� �Է¹޴� �� �ݺ��ϴ� ��� �߰��ϱ�.*/ 
	
}
