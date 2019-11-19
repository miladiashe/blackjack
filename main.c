#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "head.h"

/*전역 변수*/
 
/*플레이어 정보*/ 
int N_player;
/*플레이어의 수*/ 
int mymoney[N_maxplayer];
/*플레이어가 가진 돈*/ 
int mycard[N_maxplayer+1][N_maxhand]; 
/*플레이어가 가진 카드*/
int mycardsum[N_maxplayer+1];
/*플레이어가 가진 카드의 합*/ 


/*게임 정보*/
int bet[N_maxplayer]; 
/*베팅한 액수를 담아 두는 변수*/ 
int gameover = 0;
/*게임이 완전히 끝났음을 알리는 변수*/  

char *trump[N_CARD];
/*카드 한 벌*/ 
char *cardtray[N_CARDSET*N_CARD];
/*N_CARDSET벌의  카드를 쓰는 카드 한뭉치*/  


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	
	int round=0;
	/*지금이 n번째 라운드인지 저장하는 변수*/ 
	int playerstatus[N_player];
	/*플레이어 또는 NPC의 상태를 나타낸다.  0일 시 아무것도 아님, 1일 시 21 초과로 게임 오버, 2일 시 카드 받기 중지 , 21일 시 블랙잭*/ 
	playerconfig();
		/*player 수를 설정한다. 돈도 미리 준다.*/ 
	makecards();
		/*카드 수를 N_CARDSET 만큼  찍어내는 함수*/
	mixcards();
		/*카드를 섞는다-포인터 배열로 카드 섞는 순서 정하기?*/
	do{
		
		/*여기서 한번 반복문 시작- 한 라운드를 나타낸다.*/
		int tmpplr;
		/*for 문을 돌리기 위한 임시변수*/ 
		++round;
		printf ("\n - ROUND %i - \n", round); 
		for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			playerstatus[tmpplr]=0;
		}
		/*이번 라운드의 플레이어 상태 초기화*/ 
		betmoney(); 
			/*배팅할 액수 결정*/
		offercards(); 
		/*일단 위에서부터  1장씩 2번  나눠갖는다(딜러는 한장 엎어둔다)*/
			for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			playerstatus[tmpplr] = checksum21(tmpplr);
		}
		/*카드를 나눠준 후 모든 플레이어의 블랙잭 여부를 확인*/ 

		for (tmpplr=1; tmpplr<N_player; tmpplr++);
		{
			/*각 플레이어의 턴을 나타내는 for 문이다.*/
			while (playerstatus[tmpplr]!=0)
			/*playerstatus[tmpplr] 이 0이 아닌 경우=위에서 미리 블랙잭이 된 경우 는 이 부분을 스킵하도록 while 사용*/ 
			/*이 while 이 한 번 돌아갈 때마다 카드를 받을지 말지 한번 결정한다.*/ 
			{
			}
		}

			/*딜러의 턴을 마치고 승패 결정, 베팅액수 돌려주고 한 라운드 끝 반복문 1 끝
			끝나는 조건- 카드 다쓰거나 플레이어 한명 파산시. 자본량으로 승리자 결정*/ 
	}
	while (gameover==0);
		 
		
	/*2- 세부적 구현방법- 정의서에 명시된 것*/

	/*3-세부적 구현방법- 만들다 필요해진 것*/ 
	
	return 0;
}
