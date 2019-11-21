#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int carddraw()
/*ī�带 �� �� �̴� �Լ�*/ 
{
	extern currentcard;
	extern int cardtray[];
	extern int gameover;
	int temp;
	if (currentcard <= N_CARDSET*N_CARD)
	{
		temp = currentcard;
		currentcard++;
		return cardtray[temp];
	}
	else
	{
		gameover=3; 
		return cardtray[0];
	}
	/*Ȥ�ø��� ī�尡 �ٶ������� 0�� ��ȯ�ϵ��� �����.*/ 
	/*���� ���� ī�� �߿� ���� ���� �ִ� ī�带 �ҷ��� �����ְ� ������ �� ��ٰ� �����Ѵ�.*/ 
 } 

void offercards()
/*ó���� �� �� �ִ� �� ���� �Լ�*/ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	extern int N_player;
	extern int howmuchcard[];
	int i;
	//1. �� �÷��̾�� �� �徿 �������ش�. 
	for (i=0;i<N_player;i++)
	{
		mycard[i][0] = carddraw();
		howmuchcard[i]++;
		mycard[i][1] = carddraw();
		howmuchcard[i]++;
		sumcards(i);
	}
	//2. �������� �� ���� �������ش�. 
	mycard[N_player][0] = carddraw();
	howmuchcard[N_player]++;
	mycard[N_player][1] = carddraw();
	howmuchcard[N_player]++;
	sumcards(N_player);
	/*ī�带 �� ������ �ڵ����� �յ� ���� ����������*/ 
	
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
	
	checkIngameLastcard();
	
}

int sumcards(int playernum)
/*A��° �÷��̾ ���ݱ��� ���� ī���� ���� ����ϴ� �Լ�.*/ 
{
	extern mycardsum[];
	extern int acestatus[];
	int handA;
	int tempace;
	int cardsum = 0;
	/*���� ��ĥ��*/ 
	acestatus[playernum] = 0;
	for(handA=0; handA<N_maxhand; handA++)
	{
		cardsum = cardsum + thiscardnumber(playernum, handA);
		/*�׻� ���� ���� ���ϸ鼭 ������ ���̽� ���α��� �ٽ� üũ�ϱ� ������ ���⼭ ���̽����θ� �ʱ�ȭ���ְ� �ٽ� ������.*/ 
		tempace = acestatus[playernum];
	}
	if (cardsum > 21)
	{
		while (tempace>0)
		{
			cardsum = cardsum - 10;
			tempace = tempace - 1;
		}
	}
	mycardsum[playernum] = cardsum;
	/*�׳� �տ� �ִ� ��� ī���� ���� ���ϸ� �� ��.*/ 
}

int thiscardnumber(int playernum, int handnum)
/*ī���� ��(������ �� ������ ���̴�)�� �����ϴ� ��� playernum�� �÷��̾��� handnum��° ī�带 �Է¹޴´�. */ 
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
	/*���� ���ҋ� ��ü�� ���ع����ϱ� �̰� ������ �׳� ���� ����ī�嵵 ���̽��� �����ϴµ�*/ 
	else
	{
		acestatus[playernum]=acestatus[playernum]+1;
		return 11;
	}
}

int checksum21(int a)
/*���� 21���� üũ�ؾ� �ϴ� �κп� ������ üũ�ϴ� ��� checksum �Լ��� �� ���̴�.
playerstatus�� �ٸ� �Լ����� �ǵ���� �ϱ� ������ �׳� ���������� �ٲپ�ek.*/
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
	/*if  mycardsum[n]�� 21�� ��� �� �÷��̾�� �����̴�. ���� ���θ� �����Ϸ���?
	mycardsum[a] �� �̿�, �� �Լ��� ���� ����  0�� �� �ƹ��͵� �ƴ�, 1�� �� 21 �ʰ��� ���� ����, 2�� �� ī�� �ޱ� ���� , 21�� �� ���� �� ���� �����ش�.*/
 }
 
int checkIngameLastcard()
{
	extern int gameover;
	if(gameover==3)
	{
		printf("\n�̷�, ī�带 �� �豺��.\n������ �����ڽ��ϴ�.");
	}
	/*���� �߰��� ī�带 �� ����� Ȯ���ؼ� ������ ������ �뵵�� �Լ�. ���� �߰����� ����Ѵ�.*/
	/*�� ���� offercards ��ŭ �����ټ��ִ����� Ȯ���ϴ� ó�� ī�带 �����ٶ��� �������� �ʾƵ� �Ǵ� �Լ�.*/ 
}

