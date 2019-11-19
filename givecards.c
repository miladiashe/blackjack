#include "define.h"

int carddraw()
/*카드를 한 장 뽑는 함수*/ 
{
 } 

void offercards()
/*처음에 두 장 주는 데 쓰는 함수*/ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	extern int N_player;
	int i;
	//1. give two card for each players
	for (i=0;i<N_player;i++)
	{
		mycard[i][0] = carddraw();
		mycard[i][1] = carddraw();
	}
	//2. give two card for the operator
	mycard[N_player][0] = carddraw();
	mycard[N_player][1] = carddraw();
	
	return;
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
