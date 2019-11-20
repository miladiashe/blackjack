#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

void makecards(){
	extern int trump[];
	extern int cardtray[];
	if (N_CARD<52)
	printf("잃어버린 카드를 찾아야 합니다\n");
	else{
		/*천의 자리는 카드의 무늬, 앞의 두자리가 카드의 숫자를 나타낸다. 천으로 나눠서 남은 나머지를 계산해보면 카드의 숫자만 읽을 수 있다.*/ 
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
	/*기준이 되는 카드 한 벌.*/
	
	int tempcard;
	int tempcard2;
	/*for 돌리기 위한 임시변수*/
	for(tempcard=0; tempcard<N_CARDSET; tempcard++)
	{
		for(tempcard2=0; tempcard2<N_CARD; tempcard2++)
		{
			cardtray[tempcard2+tempcard*N_CARD]= trump [tempcard2];
		}
	}
	
	printf ("\n카드 %i벌이 준비되었습니다.\n", N_CARDSET);
	 
	}
}
void mixcards()
{
	srand((unsigned)time(NULL));
	/*원래 여기 둬야 할걸 다른 함수에 두고 잊어버렸었다. 시간 기반해서 랜덤함수의 시드를 심자*/
	int bfmix, afmix;
	int tmpcard;
	extern int cardtray[];
	/*임시변수*/ 
	for(bfmix=0; bfmix<(N_CARDSET*N_CARD); bfmix++)
	{
		afmix = rand()%(N_CARDSET*N_CARD);
		tmpcard = cardtray[bfmix];
		cardtray[bfmix] = cardtray[afmix];
		cardtray[afmix] = tmpcard; 
	}
	
	/*swap 방식으로 하되 랜덤한 순서로 섞고, 그걸 끝까지 다 하면 모든 카드가 평균적으로 두번 위치 이동하게 되니까 다 섞이는 듯 하다.*/ 
	printf ("\n카드를 섞었습니다.\n");	
/*배열의 순서를 서순으로 바꾸는 법..*/ 

}

/* 항상 이런 생각으로 개발에 임하라. “내 소스를 유지보수하게 되는 개발자가 내가 어디 살고 있는지 알고 있는 과격한 사이코패스일 것이다.” (Martin Golding)
 "난 죽음을 택하겠다."(가로쉬 헬스크림)*/ 
