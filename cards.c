#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

void makecards(){
	extern char *trump[];
	extern char *cardtray[];
	if (N_CARD<52)
	printf("�Ҿ���� ī�带 ã�ƾ� �մϴ�\n");
	else{
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
		trump[13] = "diamond A";
		trump[14] = "diamond 2";
		trump[15] = "diamond 3";
		trump[16] = "diamond 4";
		trump[17] = "diamond 5";
		trump[18] = "diamond 6";
		trump[19] = "diamond 7";
		trump[20] = "diamond 8";
		trump[21] = "diamond 9";
		trump[22] = "diamond 10";
		trump[23] = "diamond J";
		trump[24] = "diamond Q";
		trump[25] = "diamond K";
		trump[26] = "heart A";
		trump[27] = "heart 2";
		trump[28] = "heart 3";
		trump[29] = "heart 4";
		trump[30] = "heart 5";
		trump[31] = "heart 6";
		trump[32] = "heart 7";
		trump[33] = "heart 8";
		trump[34] = "heart 9";
		trump[35] = "heart 10";
		trump[36] = "heart J";
		trump[37] = "heart Q";
		trump[38] = "heart K";
		trump[39] = "club A";
		trump[40] = "club 2";
		trump[41] = "club 3";
		trump[42] = "club 4";
		trump[43] = "club 5";
		trump[44] = "club 6";
		trump[45] = "club 7";
		trump[46] = "club 8";
		trump[47] = "club 9";
		trump[48] = "club 10";
		trump[49] = "club J";
		trump[50] = "club Q";
		trump[51] = "club K";
	/*������ �Ǵ� ī�� �� ��.*/
	
	int tempcard;
	int tempcard2;
	/*for ������ ���� �ӽú���*/
	for(tempcard=0; tempcard<N_CARDSET; tempcard++)
	{
		for(tempcard2=0; tempcard2<N_CARD; tempcard2++)
		{
			cardtray[tempcard2+tempcard*N_CARD]= trump [tempcard2];
		}
	}
	
	printf ("%s, %s", trump[3], cardtray[3]);
	printf ("\nī�� %i���� �غ�Ǿ����ϴ�.\n", N_CARDSET);
	 
	}
}
void mixcards()
{
	extern char *cardtray[];
	srand((unsigned)time(NULL));
	/*���� ���� �־� �Ұ� �ٸ� �Լ��� �ΰ� �ؾ���Ⱦ���. �ð� ����ؼ� �����Լ��� �õ带 ����*/
	int bfmix, afmix;
	char tmpcard;
	/*�ӽú���*/ 
	for(bfmix=0; bfmix<N_CARD; bfmix++)
	{
		afmix = rand()%N_CARD;
		tmpcard = cardtray[bfmix];
		cardtray[bfmix] = cardtray[afmix];
		cardtray[afmix] = tmpcard; 
	}
	printf ("%s", cardtray[3]);
	/*swap ������� �ϵ� ������ ������ ����, �װ� ������ �� �ϸ� ��� ī�尡 ��������� �ι� ��ġ �̵��ϰ� �Ǵϱ� �� ���̴� �� �ϴ�.*/ 
	printf ("\nī�带 �������ϴ�.\n");	
/*�迭�� ������ �������� �ٲٴ� ��..*/ 
}
