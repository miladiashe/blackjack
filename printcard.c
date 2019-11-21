#include <stdio.h>
#include <stdlib.h>
#include "define.h"

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
		else if (mycard[playernum][handnum]%1000>1)
		{
			printf("A");
		}
		else
		{
			printf("joker");
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
	extern int mycardsum[N_maxplayer+1];
	extern int playerstatus[N_maxplayer+1];
	printf ("\nī�带 ������ �帮�ڽ��ϴ�.");
	printf ("\n������ ī�� : ������ ī�� �� ���");
	printcard(N_player, 1);
	/*������ ī�� ���*/ 
	printf ("\n");
	printf ("\n���� ī�� : ");	
	printcard(0, 0);
	printcard(0, 1);
	printf(" [%i]\n", mycardsum[0]);
	if (playerstatus[0] == 21)
	{
		/*���� ���� ���*/ 
		printf(" [BLACKJACK]");		
	}
	/*���� ī�� ��� [] �ȿ� ����ִ°� ��*/  
	int tmpplr;
	for(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		printf ("\nNPC %i�� ī�� : ", tmpplr);	
		printcard(tmpplr, 0);
		printcard(tmpplr, 1);
		printf(" [%i]", mycardsum[tmpplr]);
		if (playerstatus[tmpplr] == 21)
		{
			printf(" [BLACKJACK]");	
		}
	}
	/*NPC�� ī�� ���*/ 
	
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
/*���� ������ ���� ī����� �ַ�� �þ���� �Լ�*/ 
