#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

void makecards(){
	extern int trump[];
	extern int cardtray[];
	if (N_CARD<52)
	printf("�Ҿ���� ī�带 ã�ƾ� �մϴ�\n");
	else{
		/*õ�� �ڸ��� ī���� ����, ���� ���ڸ��� ī���� ���ڸ� ��Ÿ����. õ���� ������ ���� �������� ����غ��� ī���� ���ڸ� ���� �� �ִ�.*/ 
		trump[0] = 1;
		trump[1] = 2;
		trump[2] = 3;
		trump[3] = 4;
		trump[4] = 5;
		trump[5] = 6;
		trump[6] = 7;
		trump[7] = 8;
		trump[8] = 9;
		trump[9] = 10;
		trump[10] = 11;
		trump[11] = 12;
		trump[12] = 13;
		trump[13] = 1001;
		trump[14] = 1002;
		trump[15] = 1003;
		trump[16] = 1004;
		trump[17] = 1005;
		trump[18] = 1006;
		trump[19] = 1007;
		trump[20] = 1008;
		trump[21] = 1009;
		trump[22] = 1010;
		trump[23] = 1011;
		trump[24] = 1012;
		trump[25] = 1013;
		trump[26] = 2001;
		trump[27] = 2002;
		trump[28] = 2003;
		trump[29] = 2004;
		trump[30] = 2005;
		trump[31] = 2006;
		trump[32] = 2007;
		trump[33] = 2008;
		trump[34] = 2009;
		trump[35] = 2010;
		trump[36] = 2011;
		trump[37] = 2012;
		trump[38] = 2013;
		trump[39] = 3001;
		trump[40] = 3002;
		trump[41] = 3003;
		trump[42] = 3004;
		trump[43] = 3005;
		trump[44] = 3006;
		trump[45] = 3007;
		trump[46] = 3008;
		trump[47] = 3009;
		trump[48] = 3010;
		trump[49] = 3011;
		trump[50] = 3012;
		trump[51] = 3013;
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
	
	printf ("\nī�� %i���� �غ�Ǿ����ϴ�.\n", N_CARDSET);
	 
	}
}
void mixcards()
{
	srand((unsigned)time(NULL));
	/*���� ���� �־� �Ұ� �ٸ� �Լ��� �ΰ� �ؾ���Ⱦ���. �ð� ����ؼ� �����Լ��� �õ带 ����*/
	int bfmix, afmix;
	int tmpcard;
	extern int cardtray[];
	/*�ӽú���*/ 
	for(bfmix=0; bfmix<(N_CARDSET*N_CARD); bfmix++)
	{
		afmix = rand()%(N_CARDSET*N_CARD);
		tmpcard = cardtray[bfmix];
		cardtray[bfmix] = cardtray[afmix];
		cardtray[afmix] = tmpcard; 
	}
	
	/*swap ������� �ϵ� ������ ������ ����, �װ� ������ �� �ϸ� ��� ī�尡 ��������� �ι� ��ġ �̵��ϰ� �Ǵϱ� �� ���̴� �� �ϴ�.*/ 
	printf ("\nī�带 �������ϴ�.\n");	
/*�迭�� ������ �������� �ٲٴ� ��..*/ 

}

/* �׻� �̷� �������� ���߿� ���϶�. ���� �ҽ��� ���������ϰ� �Ǵ� �����ڰ� ���� ��� ��� �ִ��� �˰� �ִ� ������ �������н��� ���̴�.�� (Martin Golding)
 "�� ������ ���ϰڴ�."(���ν� �ｺũ��)*/ 
