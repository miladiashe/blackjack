#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void makecards(){
	extern char *trump[];
	if (N_CARD<52)
	printf("잃어버린 카드를 찾아야 합니다\n");
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
	/*기준이 되는 카드 한 벌.*/
	}
}
void mixcards(){
}
