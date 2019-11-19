#include <stdio.h>
#include <stdlib.h>

void playerconfig(){
	int N_player;
	/*플레이어의 수를 지정하는 변수*/ 
	/*이게 함수 안에 들어가면... 메인함수에서 다시 호출 및 사용이 불가능할까? 좀더 고민해보자.*/ 
	printf("몇 명의 상대와 함께하시겠습니까?(최대 4명)\n");
	scanf("%d", &N_player);
	
	int money[N_player+1]; 
		extern N_initmoney;
		int intm;
		for (intm=0; intm<(N_player+1); intm++)
			money[intm] = N_initmoney;
			/*돈을 관리하는 변수들. 플레이어 수가 유동적이기 떄문에 배열로 만들어 봤다. money[0]은 플레이어, 1부터 컴퓨터 상대 1, 2, 3, 4...*/ 
	/*if 입력받은 숫자가 N_max_player 보다 적으면 에러메시지 내고 다시 입력받는 걸 반복하는 기능 추가하기.*/ 
	
}
