#include <stdio.h>
#include <stdlib.h>


/*고정 상수들*/ 

#define N_maxplayer 5
/*최대 플레이어수*/ 
const int N_initmoney = 50;
/*초기 자본*/
#define N_maxhand 11

#define N_CARD 52
#define N_CARDSET 1
/*카드 세트 개수*/ 

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

char *trump[N_CARD];
/*카드 한 벌의 갯수는 그냥 전역 상수로 지정하지 않겠습니다*/ 
char *cardtray[N_CARDSET*52];
/*N_CARDSET벌의  카드를 쓰는 카드 한뭉치*/  


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	
	int round=0;
	/*지금이 n번째 라운드인지 저장하는 변수*/ 
	playerconfig();
		/*player 수를 설정한다. 돈도 미리 준다.*/ 
	makecards();
		/*카드 수를 N_CARDSET 만큼  찍어내는 함수*/
	mixcards();
		/*카드를 섞는다-포인터 배열로 카드 섞는 순서 정하기?*/
	do{
		
		/*여기서 한번 반복문 시작*/
		round++; 
		betmoney(); 
			/*배팅할 액수 결정*/
		offercards();
		/*일단 위에서부터  1장씩 2번  나눠갖는다(딜러는 한장 엎어둔다)
		일단 이 상황에 21인지 체크히고 21인 사람 자동 승리
		반복문 1-	더 받을지 아닐지 결정-플레이어부터 순서대로
				반복문 2-	(블랙잭이 되거나 스톱하거나 21을 넘을때까지 반복문으로)반복2 끝 
				딜러의 턴을 마치고 승패 결정, 베팅액수 돌려주고 한 라운드 끝 반복문 1 끝
				끝나는 조건- 카드 다쓰거나 플레이어 한명 파산시. 자본량으로 승리자 결정*/ 
	}
	while (gameover==0);
		 
		
	/*2- 세부적 구현방법- 정의서에 명시된 것*/

	/*3-세부적 구현방법- 만들다 필요해진 것*/ 
	
	return 0;
}
