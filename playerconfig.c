#include <stdio.h>
#include <stdlib.h>

void playerconfig(){
	int N_player;
	/*�÷��̾��� ���� �����ϴ� ����*/ 
	/*�̰� �Լ� �ȿ� ����... �����Լ����� �ٽ� ȣ�� �� ����� �Ұ����ұ�? ���� ����غ���.*/ 
	printf("�� ���� ���� �Բ��Ͻðڽ��ϱ�?(�ִ� 4��)\n");
	scanf("%d", &N_player);
	
	int money[N_player+1]; 
		extern N_initmoney;
		int intm;
		for (intm=0; intm<(N_player+1); intm++)
			money[intm] = N_initmoney;
			/*���� �����ϴ� ������. �÷��̾� ���� �������̱� ������ �迭�� ����� �ô�. money[0]�� �÷��̾�, 1���� ��ǻ�� ��� 1, 2, 3, 4...*/ 
	/*if �Է¹��� ���ڰ� N_max_player ���� ������ �����޽��� ���� �ٽ� �Է¹޴� �� �ݺ��ϴ� ��� �߰��ϱ�.*/ 
	
}
