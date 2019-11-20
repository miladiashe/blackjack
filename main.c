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
int trump[N_CARD];
/*카드 한 벌*/ 
int cardtray[N_CARDSET*N_CARD];
/*N_CARDSET벌의  카드를 쓰는 카드 한뭉치*/  
int acestatus[N_maxplayer+1];
/*몇 번째 플레이어가 에이스를 받았는지 여부 저장하는 곳. 일단 전역변수로 만들어보자.*/ 
int currentcard;
/*현재 카드를 몇 장 사용했는지 담아두는 변수*/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	int tmpplr;
	int tmpplr2;
	/*for 문을 돌리기 위한 임시변수*/ 
	int round=0;
	/*지금이 n번째 라운드인지 저장하는 변수*/ 
	int playerstatus[N_player];
	/*플레이어 또는 NPC의 상태를 나타낸다.  0일 시 아무것도 아님, 1일 시 21 초과로 게임 오버, 2일 시 카드 받기 중지 , 21일 시 블랙잭*/ 
	playerconfig();
		/*player 수를 설정한다. 돈도 미리 준다.*/ 
	makecards();
	/*디버깅을 위해 삽입한 부분. 카드가 잘 만들어졌는지 확인하려면 이 부분을 주석에서 뺴내보자.
			int i; 
			for (i=0; i<52; i++)
			{
				printf ("%i\n", cardtray[i]);
			}
		/*카드 수를 N_CARDSET 만큼  찍어내는 함수*/
	mixcards();
	/*디버깅을 위해 삽입한 부분. 카드가 섞이는지 확인하려면 이 부분을 주석에서 뺴내보자.
		for (i=0; i<52; i++)
		{
			printf ("%i\n", cardtray[i]);
		}
		/*카드를 섞는다*/
	do{
		
		/*여기서 한번 반복문 시작- 한 라운드를 나타낸다.*/

		++round;
		printf ("\n - ROUND %i - \n", round); 
		for (tmpplr=0; tmpplr<N_maxplayer; tmpplr++);
		{
			playerstatus[tmpplr]=0;
		}
		/*이번 라운드의 플레이어 상태 초기화*/ 
		for (tmpplr=0; tmpplr<N_maxplayer+1; tmpplr++);
		{
			for (tmpplr=0; tmpplr2<N_maxhand; tmpplr2++);
			{
				mycard[tmpplr][N_maxhand]=0;
			}
		}
		/*이번 라운드의 플레이어 핸드 초기화*/ 
		betmoney(); 
			/*배팅할 액수 결정*/
			//완료 
		offercards(); 
		/*일단 위에서부터  1장씩 2번  나눠갖는다(딜러는 한장 엎어둔다)*/
			for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			playerstatus[tmpplr] = checksum21(tmpplr);
		}
		/*카드를 나눠준 후 모든 플레이어의 블랙잭 여부를 확인*/ 
		printinitialcard();
		/*offercards에서 준 최초 두장을 보여주는 함수.*/ 

		for (tmpplr=1; tmpplr<N_player; tmpplr++);
		{
			/*각 플레이어의 턴을 나타내는 for 문이다.*/
			while (playerstatus[tmpplr]!=0)
			/*playerstatus[tmpplr] 이 0이 아닌 경우=위에서 미리 블랙잭이 된 경우 는 이 부분을 스킵하도록 while 사용*/ 
			/*이 while 이 한 번 돌아갈 때마다 카드를 받을지 말지 한번 결정한다.*/ 
			{
			}
			/*전부 다 끝나면 플레이어의 승패를 결정, 돈을 정산하고 파산 여부를 확인한다. 파산하거나 카드 거의다쓰면 게임오버를 1로 바꿈.*/ 
		}
			/*딜러의 턴을 마치고 승패 결정, 베팅액수 돌려주고 한 라운드 끝 반복문 1 끝
			끝나는 조건- 카드 (거의)다 쓰거나 플레이어 한명 파산시. 자본량으로 승리자 결정*/ 
	}
	while (gameover==0);
		 
		
	/*2- 세부적 구현방법- 정의서에 명시된 것*/

	/*3-세부적 구현방법- 만들다 필요해진 것*/ 
	
	return 0;
}
