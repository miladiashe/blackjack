#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int carddraw()
/*카드를 한 장 뽑는 함수*/ 
{
	extern currentcard;
	extern int cardtray[];
	int temp;
	temp = currentcard;
	currentcard++;
	return cardtray[temp];
	/*현재 남은 카드 중에 제일 위에 있는 카드를 불러와 나눠주고 한장을 더 썼다고 저장한다.*/ 
 } 

void offercards()
/*처음에 두 장 주는 데 쓰는 함수*/ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	extern int N_player;
	int i;
	//1. 각 플레이어에게 두 장씩 나누어준다. 
	for (i=0;i<N_player;i++)
	{
		mycard[i][0] = carddraw();
		mycard[i][1] = carddraw();
	}
	//2. 딜러에게 두 장을 나누어준다. 
	mycard[N_player][0] = carddraw();
	mycard[N_player][1] = carddraw();
	
	return;
}

int sumcards(int playernum)
/*A번째 플레이어가 지금까지 받은 카드의 합을 계산하는 함수.*/ 
{
	extern mycardsum[];
	int handA;
	int cardsum = 0;
	for(handA=0; handA<N_maxhand; handA++)
	{
		cardsum = cardsum + thiscardnumber(playernum, handA);
	}
	mycardsum[playernum] = cardsum;
	/*그냥 손에 있는 모든 카드의 합을 구하면 될 것.*/ 
}

int thiscardnumber(int playernum, int handnum)
/*카드의 값(게임할 때 실제로 쓰이는)를 추출하는 기능 playernum번 플레이어의 handnum번째 카드를 입력받는다. */ 
{
}

int checksum21(int a)
/*합이 21인지 체크해야 하는 부분에 일일이 체크하는 대신 checksum 함수를 쓸 것이다.
전역변수를 너무 늘리는 것 같아서 playerstatus를 전역변수로 쓰는 대신 이 함수를 이용해 값을 반환해 넣어주기로 했다.*/
{
	extern mycardsum[];
	if (mycardsum[a]>21)
	{
		return 1;
	}
	else if (mycardsum[a]<21)
	{
		return 0;
	}
	else
	{
		return 21;
	 }
	/*if  mycardsum[n]이 21일 경우 그 플레이어는 블랙잭이다. 블랙잭 여부를 구현하려면?
	mycardsum[a] 를 이용, 이 함수의 힙에 따라  0일 시 아무것도 아님, 1일 시 21 초과로 게임 오버, 2일 시 카드 받기 중지 , 21일 시 블랙잭 의 값을 돌려준다.*/
 }
 
void printcard()
/*무슨 카드인지 읽어주는(무늬, 숫자) 함수*/ 
{
}

void printinitialcard()
/*처음 나눠준 카드를 읽어 주는 함수*/ 
{
}
