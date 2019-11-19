#include <stdio.h>
#include <stdlib.h>


/*고정 상수들*/ 

#define N_maxplayer 4
/*최대 플레이어수*/ 
const int N_initmoney = 50;
/*초기 자본*/
#define N_CARD 52
/*카드 한 세트 개수*/
#define N_CARDSET 1
/*카드 세트 개수*/ 

#include "head.h"

/*전역 변수*/
 
/*플레이어 정보*/ 
int N_player;
int mymoney[N_maxplayer+1];

char *trump[N_CARD];
char *cardtray[N_CARDSET*52];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	/*1-게임의 전체적인 흐름에 따라  코드의 뼈대를 짤 것*/
		/*1. 블랙잭 게임의 흐름을 제대로 이해하자-난 아직까지 1대1밖에 생각을 못 한다*/
		/*플레이어 수를 입력받는다-간단한 scanf 함수로 playernumber 변수에 직접적으로 영향주기*/
	playerconfig();

	makecards();

		/*카드 수를 N_CARDSET 만큼 찍어내는 함수*/
	mixcards();
		/*카드를 섞는다-포인터 배열로 카드 섞는 순서 정하기?
	
		배팅할 액수 결정 
		일단 위에서부터  1장씩 2번  나눠갖는다(딜러는 한장 엎어둔다)-개인별로 받은 카드를 저장하는 함수를 정의해야 하나?
		일단 이 상황에 21인지 체크히고 21인 사람 자동 승리
		반복문 1-	더 받을지 아닐지 결정-플레이어부터 순서대로
				반복문 2-	(블랙잭이 되거나 스톱하거나 21을 넘을때까지 반복문으로)반복2 끝 
				딜러의 턴을 마치고 승패 결정, 베팅액수 돌려주고 한 라운드 끝 반복문 1 끝
				끝나는 조건- 카드 다쓰거나 플레이어 한명 파산시. 자본량으로 승리자 결정*/ 
		
		 
		
	/*2- 세부적 구현방법- 정의서에 명시된 것*/
		/*1. 다른 .c 파일에 담긴 함수 정의를 불러오는 법을 공부하기*/
		/*성공!!!!!!!!!!!!! 프로젝트에 병합하니 된다....*/ 
	/*3-세부적 구현방법- 만들다 필요해진 것*/ 
	
	return 0;
}
