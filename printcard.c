#include <stdio.h>
#include <stdlib.h>
#include "define.h"

char printcard(int playernum, int handnum)
/*무슨 카드인지 읽어주는(무늬, 숫자) 함수
천의 자리로 문자를 판단하고 1, 10의 자리로 무슨 카드인지 읽는다. printf로 출력하는 기능이다.*/ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	if (mycard[playernum][handnum]<1000) //스페이드  
	{
		printf (" ♠");
	
		if (mycard[playernum][handnum]%1000>10)
		{
			if (mycard[playernum][handnum]%1000 == 11)
			{
				printf ("J");
			}
			else if (mycard[playernum][handnum]%1000 == 12)
			{
				printf ("Q");
			}
			else
			{
				printf ("k");
			}
		}
		else if (mycard[playernum][handnum]%1000>1)
		{
			printf("%i", mycard[playernum][handnum]%1000);
		}
		else if (mycard[playernum][handnum]%1000>1)
		{
			printf("A");
		}
		else
		{
			printf("joker");
		}
	}
	else if (mycard[playernum][handnum]<2000) //다이아 
	{
		printf (" ◇");
	
		if (mycard[playernum][handnum]%1000>10)
		{
			if (mycard[playernum][handnum]%1000 == 11)
			{
				printf ("J");
			}
			else if (mycard[playernum][handnum]%1000 == 12)
			{
				printf ("Q");
			}
			else
			{
				printf ("k");
			}
		}
		else if (mycard[playernum][handnum]%1000>1)
		{
			printf("%i", mycard[playernum][handnum]%1000);
		}
		else
		{
			printf("A");
		}
	}
		else if (mycard[playernum][handnum]<3000)  //하 트  
	{
		printf (" ♡");
	
		if (mycard[playernum][handnum]%1000>10)
		{
			if (mycard[playernum][handnum]%1000 == 11)
			{
				printf ("J");
			}
			else if (mycard[playernum][handnum]%1000 == 12)
			{
				printf ("Q");
			}
			else
			{
				printf ("k");
			}
		}
		else if (mycard[playernum][handnum]%1000>1)
		{
			printf("%i", mycard[playernum][handnum]%1000);
		}
		else
		{
			printf("A");
		}
	}
		else  //클럽 
	{
		printf (" ♣");
	
		if (mycard[playernum][handnum]%1000>10)
		{
			if (mycard[playernum][handnum]%1000 == 11)
			{
				printf ("J");
			}
			else if (mycard[playernum][handnum]%1000 == 12)
			{
				printf ("Q");
			}
			else
			{
				printf ("k");
			}
		}
		else if (mycard[playernum][handnum]%1000>1)
		{
			printf("%i", mycard[playernum][handnum]%1000);
		}
		else
		{
			printf("A");
		}
	}
}

void printinitialcard()
/*처음 나눠준 카드를 읽어 주는 함수*/ 
{
	extern int N_player;
	extern int mycardsum[N_maxplayer+1];
	extern int playerstatus[N_maxplayer+1];
	printf ("\n카드를 나누어 드리겠습니다.");
	printf ("\n딜러의 카드 : 뒤집은 카드 한 장과");
	printcard(N_player, 1);
	/*딜러의 카드 출력*/ 
	printf ("\n");
	printf ("\n나의 카드 : ");	
	printcard(0, 0);
	printcard(0, 1);
	printf(" [%i]\n", mycardsum[0]);
	if (playerstatus[0] == 21)
	{
		/*블랙잭 여부 출력*/ 
		printf(" [BLACKJACK]");		
	}
	/*나의 카드 출력 [] 안에 들어있는건 합*/  
	int tmpplr;
	for(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		printf ("\nNPC %i의 카드 : ", tmpplr);	
		printcard(tmpplr, 0);
		printcard(tmpplr, 1);
		printf(" [%i]", mycardsum[tmpplr]);
		if (playerstatus[tmpplr] == 21)
		{
			printf(" [BLACKJACK]");	
		}
	}
	/*NPC의 카드 출력*/ 
	
}

void printingamecard(int playernum)
{
	extern int howmuchcard[N_maxplayer+1];
	extern int mycardsum[N_maxplayer+1];
	extern int playerstatus[N_maxplayer+1];
	int tmpcard;
	for(tmpcard=0; tmpcard<howmuchcard[playernum]; tmpcard++)
	{
		printcard(playernum, tmpcard);
	}
	printf(" [%i]", mycardsum[playernum]);
	if (playerstatus[0] == 21)
	{
		printf(" [BLACKJACK]");		
	}
}
/*게임 내에서 받은 카드들을 주루룩 늘어놓는 함수*/ 
