#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int carddraw()
/*ī�带 �� �� �̴� �Լ�*/ 
{
	extern currentcard;
	extern int cardtray[];
	int temp;
	temp = currentcard;
	currentcard++;
	return cardtray[temp];
	/*���� ���� ī�� �߿� ���� ���� �ִ� ī�带 �ҷ��� �����ְ� ������ �� ��ٰ� �����Ѵ�.*/ 
 } 

void offercards()
/*ó���� �� �� �ִ� �� ���� �Լ�*/ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	extern int N_player;
	int i;
	//1. �� �÷��̾�� �� �徿 �������ش�. 
	for (i=0;i<N_player;i++)
	{
		mycard[i][0] = carddraw();
		mycard[i][1] = carddraw();
	}
	//2. �������� �� ���� �������ش�. 
	mycard[N_player][0] = carddraw();
	mycard[N_player][1] = carddraw();
	
	return;
}

int sumcards(int playernum)
/*A��° �÷��̾ ���ݱ��� ���� ī���� ���� ����ϴ� �Լ�.*/ 
{
	extern mycardsum[];
	int handA;
	int cardsum = 0;
	for(handA=0; handA<N_maxhand; handA++)
	{
		cardsum = cardsum + thiscardnumber(playernum, handA);
	}
	mycardsum[playernum] = cardsum;
	/*�׳� �տ� �ִ� ��� ī���� ���� ���ϸ� �� ��.*/ 
}

int thiscardnumber(int playernum, int handnum)
/*ī���� ��(������ �� ������ ���̴�)�� �����ϴ� ��� playernum�� �÷��̾��� handnum��° ī�带 �Է¹޴´�. */ 
{
}

int checksum21(int a)
/*���� 21���� üũ�ؾ� �ϴ� �κп� ������ üũ�ϴ� ��� checksum �Լ��� �� ���̴�.
���������� �ʹ� �ø��� �� ���Ƽ� playerstatus�� ���������� ���� ��� �� �Լ��� �̿��� ���� ��ȯ�� �־��ֱ�� �ߴ�.*/
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
	/*if  mycardsum[n]�� 21�� ��� �� �÷��̾�� �����̴�. ���� ���θ� �����Ϸ���?
	mycardsum[a] �� �̿�, �� �Լ��� ���� ����  0�� �� �ƹ��͵� �ƴ�, 1�� �� 21 �ʰ��� ���� ����, 2�� �� ī�� �ޱ� ���� , 21�� �� ���� �� ���� �����ش�.*/
 }
 
void printcard()
/*���� ī������ �о��ִ�(����, ����) �Լ�*/ 
{
}

void printinitialcard()
/*ó�� ������ ī�带 �о� �ִ� �Լ�*/ 
{
}
