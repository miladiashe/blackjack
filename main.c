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
/*게임이 완전히 끝났음을 알리는 변수. 0인 경우 진행중. 카드가 다 떨어졌을 경우 1, 한 명이 파산했을 경우 2*/  
int trump[N_CARD];
/*카드 한 벌*/ 
int cardtray[N_CARDSET*N_CARD];
/*N_CARDSET벌의  카드를 쓰는 카드 한뭉치*/  
int acestatus[N_maxplayer+1];
/*몇 번째 플레이어가 에이스를 받았는지 여부 저장하는 곳. 일단 전역변수로 만들어보자.*/ 
int currentcard;
/*현재 카드를 몇 장 사용했는지 담아두는 변수*/ 
int howmuchcard[N_maxplayer+1];
/*각 턴에 플레이어별로 카드를 몇 장이나 받았는지 담아두는 변수*/ 
int playerstatus[N_maxplayer+1];
/*플레이어 또는 NPC의 상태를 나타낸다.  0일 시 아무것도 아님, 1일 시 21 초과로 게임 오버, 2일 시 카드 받기 중지 , 21일 시 블랙잭*/ 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	int tmpplr;
	int tmpplr2;
	/*for 문을 돌리기 위한 임시변수*/ 
	int round=0;
	/*지금이 n번째 라운드인지 저장하는 변수*/ 
	playerconfig();
		/*player 수를 설정한다. 돈도 미리 준다.*/ 
	int winner = N_player;
	/*우승자를 기록하는 변수 미리 선언한다. 동작 여부와 버그를 확인하기 위해 초기값은 딜러로 해 둔다*/ 
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
		int wtf2;
		for (wtf2=0; wtf2<N_maxplayer; wtf2++);
		{
			playerstatus[wtf2]=0;
		}
		/*이번 라운드의 플레이어 상태 초기화*/ 
		for (tmpplr=0; tmpplr<(N_maxplayer+1); tmpplr++);
		{	
			howmuchcard[tmpplr] = 0;
			mycardsum[tmpplr] = 0;
			acestatus[tmpplr] = 0;
			for (tmpplr2=0; tmpplr2<N_maxhand; tmpplr2++);
			{
				mycard[tmpplr][tmpplr2]=0;
			}
		}
		/*이번 라운드의 받은 카드 수, 받은 카드 합, 에이스 여부, 플레이어 핸드 초기화*/
		/*대체 뭐가 문제이길래 작동을 안 하는 건지 모르겠다..*/ 
		betmoney(); 
			/*배팅할 액수 결정*/
			//완료 
		offercards(); 
		/*일단 위에서부터  1장씩 2번  나눠갖는다(딜러는 한장 엎어둔다)*/
		//완료 
			for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			checksum21(tmpplr);
		}
		/*카드를 나눠준 후 모든 플레이어의 블랙잭 여부를 확인*/ 
		printinitialcard();
		/*offercards에서 준 최초 두장을 보여주는 함수.*/ 
		//완료 

		for (tmpplr=0; tmpplr2<N_player+1; tmpplr2++);
		{
			if (tmpplr == 0)
			{
				printf ("\n\n당신의 차례입니다.\n");
				while (playerstatus[tmpplr] == 0)
				{
					printf("\n한 장 더 받으시겠습니까? 아니면 여기서 멈추시겠습니까?\n");
					gostop();
				}
				
			} 
			else if (tmpplr == N_player)
			{
				printf ("\n\n마지막으로, 제 차례입니다.\n");
				printf ("제가 받은 첫 번쨰 카드는 ");
				printcard(N_player, 0);
				printf (" 입니다.");
				printf(" 합 [%i]", mycardsum[N_player]);
				/*딜러가 카드를 공개한다.*/  
				printingamecard(N_player);
				npcgo(tmpplr);
				
			}
			else
			{
				printf ("\n\nNPC %i 님의 차례입니다.\n", tmpplr);
				while (playerstatus[tmpplr] == 0)
				{
					npcgo(tmpplr);
				}
			}
			/*각 플레이어의 턴을 나타내는 for 문이다.if 문을 이용해 사용자의 턴과 NPC의 턴을 구분하고 전체적으로는 같은 루프에 넣는다.*/
			/*playerstatus[tmpplr] 이 0이 아닌 경우=위에서 미리 블랙잭이 된 경우 는 이 부분을 스킵하도록 while 사용*/ 
			/*이 while 이 한 번 돌아갈 때마다 카드를 받을지 말지 한번 결정한다.*/ 

			/*전부 다 끝나면 플레이어의 승패를 결정, 돈을 정산하고 파산 여부를 확인한다. 파산하거나 카드 거의다쓰면 게임오버를 1로 바꿈.*/ 
		}
			/*딜러의 턴을 마치고 승패 결정, 베팅액수 돌려주고 한 라운드 끝 반복문 1 끝
			끝나는 조건- 카드 (거의)다 쓰거나 플레이어 한명 파산시. 자본량으로 승리자 결정
			mymoney 변수가 가장 많은 플레이어가 승리한다.*/
		if (currentcard>((N_CARDSET*N_CARD)-(N_player+1*2)))
		{
			gameover = 1;
		/*카드가 2장씩 나눠줄 수 없을 만큼 줄어들면 게임을 끝낸다.*/
		}
		int wtf;
		for (wtf=0; wtf<N_player; wtf++)
		{
			if (mymoney[wtf]<=0)
			{
				gameover=2;
			}
				/*mymoney[N_player]가 전부 0인지 검사해보는 함수*/
			/*플레이어 한명 파산시 게임을 끝낸다.*/ 
		}
	}
	while (gameover==0);
	
	if (gameover==2)
	{
		/*한 명이 파산했을 때 게임의 엔딩*/ 
		printf ("\n\n한 분이 파산하셨으므로 여기에서 게임을 끝냅니다.\n");
	} 
	else if (gameover==1)
	{
		/*카드를 다 썼을 때 게임의 엔딩*/ 
		printf ("\n\n카드를 다 썼으므로 여기에서 게임을 끝냅니다.\n");
	}
	
	winner = findwinner();
	
	if (winner==0)
	{
		printf ("\n\n축하드립니다, 우승하셨군요.\n");
	}
	else if (winner==N_player) 
	{
		printf ("\n\n우승자가.. 저인가요? 이럴 리 없는데. 오류인 것 같습니다.\n");
	}
	else
	{
		printf ("\n\nNPC %i 님 우승 축하드립니다.\n", winner);
	} 
	
	
	/*2- 세부적 구현방법- 정의서에 명시된 것*/

	/*3-세부적 구현방법- 만들다 필요해진 것*/ 
	
	return 0;
}
