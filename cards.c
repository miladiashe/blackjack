#include <stdio.h>
#include <stdlib.h>
void makecards(){
	extern N_CARDSET;
	char *trump[52];
	/* *trump �� ��� Ʈ����ī�� ���̸� �ְ� cardset�� trump�� ����, ���°͵� �����͸� ���� */
	trump[0] = "spade A";
	trump[1] = "spade 2";
	trump[2] = "spade 3";
	trump[3] = "spade 4";
	trump[4] = "spade 5";
	trump[5] = "spade 6";
	trump[6] = "spade 7";
	trump[7] = "spade 8";
	trump[8] = "spade 9";
	trump[9] = "spade 10";
	trump[10] = "spade J";
	trump[11] = "spade Q";
	trump[12] = "spade K";
	
	
	
	
	char *cardset[N_CARDSET];
	/* ���� N_CARDSET�� 13���� ���� ��� �����̵� 1 2 3 4 5 6 7 8 9 10 j q k�� �ְ� ���̾�, ��Ʈ, Ŭ�ι��� �� �� 52���� ũ�� �ݺ�.. �ϴ� ������ ©��?*/ 
	
	
	if (N_CARDSET>0)
	{
		int tempcard;
		for(tempcard=0; tempcard<N_CARDSET; tempcard++)
		cardset[tempcard] = trump[tempcard];
	}
	else
	{
		printf("�÷����� ī���� ���� �ʹ� �����ϴ�. N_CARDSET ������ �߸��� ���� ����Ǿ� �ֽ��ϴ�.");
	}
	
}
void mixcards(){
}
