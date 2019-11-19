#include <stdio.h>
#include <stdlib.h>
void makecards(){
	extern N_CARDSET;
	char *trump[52];
	/* *trump 에 모든 트럼프카드 무늬를 넣고 cardset를 trump와 대응, 섞는것도 포인터를 섞자 */
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
	/* 만약 N_CARDSET이 13보다 작을 경우 스페이드 1 2 3 4 5 6 7 8 9 10 j q k를 넣고 다이아, 하트, 클로버로 한 뒤 52보다 크면 반복.. 하는 식으로 짤까?*/ 
	
	
	if (N_CARDSET>0)
	{
		int tempcard;
		for(tempcard=0; tempcard<N_CARDSET; tempcard++)
		cardset[tempcard] = trump[tempcard];
	}
	else
	{
		printf("플레이할 카드의 수가 너무 적습니다. N_CARDSET 변수에 잘못된 값이 저장되어 있습니다.");
	}
	
}
void mixcards(){
}
