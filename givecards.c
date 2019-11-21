#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int carddraw()
/*카드를 한 장 뽑는 함수*/ 
{
	extern currentcard;
	extern int cardtray[];
	int temp;
	if (currentcard != N_CARDSET*N_CARD)
	{
		temp = currentcard;
		currentcard++;
		return cardtray[temp];
	}
	else
	{
		return 0;
	}
	/*혹시몰라서 카드가 다떨어지면 0을 반환하도록 해줬다.*/ 
	/*현재 남은 카드 중에 제일 위에 있는 카드를 불러와 나눠주고 한장을 더 썼다고 저장한다.*/ 
 } 

void offercards()
/*처음에 두 장 주는 데 쓰는 함수*/ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	extern int N_player;
	extern int howmuchcard[];
	int i;
	//1. 각 플레이어에게 두 장씩 나누어준다. 
	for (i=0;i<N_player;i++)
	{
		mycard[i][0] = carddraw();
		howmuchcard[i]++;
		mycard[i][1] = carddraw();
		howmuchcard[i]++;
		sumcards(i);
	}
	//2. 딜러에게 두 장을 나누어준다. 
	mycard[N_player][0] = carddraw();
	howmuchcard[N_player]++;
	mycard[N_player][1] = carddraw();
	howmuchcard[N_player]++;
	sumcards(N_player);
	/*카드를 줄 떄마다 자동으로 합도 같이 구해지도록*/ 
	
	return;
}

void givemorecard(int playernum)
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	extern int N_player;
	extern int howmuchcard[];
	int i;
	i = howmuchcard[playernum];
	
	mycard[playernum][i]= carddraw();
	
	howmuchcard[playernum]++;
	
	
}

int sumcards(int playernum)
/*A번째 플레이어가 지금까지 받은 카드의 합을 계산하는 함수.*/ 
{
	extern mycardsum[];
	extern int acestatus[];
	int handA;
	int cardsum = 0;
	for(handA=0; handA<N_maxhand; handA++)
	{
		cardsum = cardsum + thiscardnumber(playernum, handA);
	}
	if (cardsum > 21)
	{
		
		if (acestatus[playernum]>0)
		{
			cardsum - 10;
			acestatus[playernum] - 1;
		}
	}
	mycardsum[playernum] = cardsum;
	/*그냥 손에 있는 모든 카드의 합을 구하면 될 것.*/ 
}

int thiscardnumber(int playernum, int handnum)
/*카드의 값(게임할 때 실제로 쓰이는)를 추출하는 기능 playernum번 플레이어의 handnum번째 카드를 입력받는다. */ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	extern int acestatus[];
	if (mycard[playernum][handnum]%1000>9)
	{
		return 10;
	}
	else if (mycard[playernum][handnum]%1000>1)
	{
		return mycard[playernum][handnum]%1000;
	}
	else if (mycard[playernum][handnum]==0)
	{
		return 0;
	}
	/*합을 구할떄 전체를 더해버리니까 이게 없으면 그냥 아직 없는카드도 에이스로 판정하는듯*/ 
	else
	{
		acestatus[playernum]=acestatus[playernum]+1;
		return 11;
	}
}

int checksum21(int a)
/*합이 21인지 체크해야 하는 부분에 일일이 체크하는 대신 checksum 함수를 쓸 것이다.
playerstatus를 다른 함수에도 건드려야 하기 떄문에 그냥 전역변수로 바꾸었ek.*/
{
	extern mycardsum[];
	extern int playerstatus[];
	
	if (mycardsum[a]>21)
	{
		playerstatus[a] = 1;
	}
	else if (mycardsum[a] == 21)
	{
		playerstatus[a] = 21;
	}
	else
	{
		playerstatus[a] = 0;
	}
	/*if  mycardsum[n]이 21일 경우 그 플레이어는 블랙잭이다. 블랙잭 여부를 구현하려면?
	mycardsum[a] 를 이용, 이 함수의 힙에 따라  0일 시 아무것도 아님, 1일 시 21 초과로 게임 오버, 2일 시 카드 받기 중지 , 21일 시 블랙잭 의 값을 돌려준다.*/
 }
 
