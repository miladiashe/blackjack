#include <stdio.h>
#include <stdlib.h>

void playerconfig(){
	int N_player;
	/*플레이어의 수를 지정하는 변수*/ 
	printf("몇 명의 상대와 함께하시겠습니까?(최대 4명)\n");
	scanf("%d", &N_player);
	
	int money[N_player+1]; 
		extern N_initmoney;
		/*이부분을 새로 함수처리해서  돈을 관리하는 다른 함수들과 같은.c 파일로 이동할 것*/ 
		int intm;
		for (intm=0; intm<(N_player+1); intm++)
			money[intm] = N_initmoney;
	
}
