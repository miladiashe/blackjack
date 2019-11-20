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
	else
	{
		acestatus[playernum]=1;
		return 11;
	}
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
 
char printcard(int playernum, int handnum)
/*���� ī������ �о��ִ�(����, ����) �Լ�
õ�� �ڸ��� ���ڸ� �Ǵ��ϰ� 1, 10�� �ڸ��� ���� ī������ �д´�. printf�� ����ϴ� ����̴�.*/ 
{
	extern int mycard[N_maxplayer+1][N_maxhand];
	if (mycard[playernum][handnum]<1000) //�����̵�  
	{
		printf (" ��");
	
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
	else if (mycard[playernum][handnum]<2000) //���̾� 
	{
		printf (" ��");
	
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
		else if (mycard[playernum][handnum]<3000)  //�� Ʈ  
	{
		printf (" ��");
	
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
		else  //Ŭ�� 
	{
		printf (" ��");
	
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
/*ó�� ������ ī�带 �о� �ִ� �Լ�*/ 
{
	extern int N_player;
	printf ("\n������ ī�� : ������ ī�� �� ���");
	printcard(N_player, 1);
	/*������ ī�� ���*/ 
	printf ("\n");
	printf ("\n���� ī�� : ");	
	printcard(0, 0);
	printcard(0, 1);
	/*���� ī�� ���*/ 
	int tmpplr;
	for(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
	 	printf ("\n");
		printf ("\nNPC %i�� ī�� : ", tmpplr);	
		printcard(tmpplr, 0);
		printcard(tmpplr, 1);
	}
	/*NPC�� ī�� ���*/ 
	
}
