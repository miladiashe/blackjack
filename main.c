#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "head.h"

/*���� ����*/
 
/*�÷��̾� ����*/ 
int N_player;
/*�÷��̾��� ��*/ 
int mymoney[N_maxplayer];
/*�÷��̾ ���� ��*/ 
int mycard[N_maxplayer+1][N_maxhand]; 
/*�÷��̾ ���� ī��*/
int mycardsum[N_maxplayer+1];
/*�÷��̾ ���� ī���� ��*/ 


/*���� ����*/

int bet[N_maxplayer]; 
/*������ �׼��� ��� �δ� ����*/ 
int gameover = 0;
/*������ ������ �������� �˸��� ����. 0�� ��� ������. ī�尡 �� �������� ��� 1, �� ���� �Ļ����� ��� 2*/  
int trump[N_CARD];
/*ī�� �� ��*/ 
int cardtray[N_CARDSET*N_CARD];
/*N_CARDSET����  ī�带 ���� ī�� �ѹ�ġ*/  
int acestatus[N_maxplayer+1];
/*�� ��° �÷��̾ ���̽��� �޾Ҵ��� ���� �����ϴ� ��. �ϴ� ���������� ������.*/ 
int currentcard;
/*���� ī�带 �� �� ����ߴ��� ��Ƶδ� ����*/ 
int howmuchcard[N_maxplayer+1];
/*�� �Ͽ� �÷��̾�� ī�带 �� ���̳� �޾Ҵ��� ��Ƶδ� ����*/ 
int playerstatus[N_maxplayer+1];
/*�÷��̾� �Ǵ� NPC�� ���¸� ��Ÿ����.  0�� �� �ƹ��͵� �ƴ�, 1�� �� 21 �ʰ��� ���� ����, 2�� �� ī�� �ޱ� ���� , 21�� �� ����*/ 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	int tmpplr;
	int tmpplr2;
	/*for ���� ������ ���� �ӽú���*/ 
	int round=0;
	/*������ n��° �������� �����ϴ� ����*/ 
	playerconfig();
		/*player ���� �����Ѵ�. ���� �̸� �ش�.*/ 
	int winner = N_player;
	/*����ڸ� ����ϴ� ���� �̸� �����Ѵ�. ���� ���ο� ���׸� Ȯ���ϱ� ���� �ʱⰪ�� ������ �� �д�*/ 
	makecards();
	/*������� ���� ������ �κ�. ī�尡 �� ����������� Ȯ���Ϸ��� �� �κ��� �ּ����� ��������.
			int i; 
			for (i=0; i<52; i++)
			{
				printf ("%i\n", cardtray[i]);
			}
		/*ī�� ���� N_CARDSET ��ŭ  ���� �Լ�*/
	mixcards();
	/*������� ���� ������ �κ�. ī�尡 ���̴��� Ȯ���Ϸ��� �� �κ��� �ּ����� ��������.
		for (i=0; i<52; i++)
		{
			printf ("%i\n", cardtray[i]);
		}
		/*ī�带 ���´�*/
	do{
		
		/*���⼭ �ѹ� �ݺ��� ����- �� ���带 ��Ÿ����.*/

		++round;
		printf ("\n - ROUND %i - \n", round); 
		int wtf2;
		for (wtf2=0; wtf2<N_maxplayer; wtf2++);
		{
			playerstatus[wtf2]=0;
		}
		/*�̹� ������ �÷��̾� ���� �ʱ�ȭ*/ 
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
		/*�̹� ������ ���� ī�� ��, ���� ī�� ��, ���̽� ����, �÷��̾� �ڵ� �ʱ�ȭ*/
		/*��ü ���� �����̱淡 �۵��� �� �ϴ� ���� �𸣰ڴ�..*/ 
		betmoney(); 
			/*������ �׼� ����*/
			//�Ϸ� 
		offercards(); 
		/*�ϴ� ����������  1�徿 2��  �������´�(������ ���� ����д�)*/
		//�Ϸ� 
			for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			checksum21(tmpplr);
		}
		/*ī�带 ������ �� ��� �÷��̾��� ���� ���θ� Ȯ��*/ 
		printinitialcard();
		/*offercards���� �� ���� ������ �����ִ� �Լ�.*/ 
		//�Ϸ� 

		for (tmpplr=0; tmpplr2<N_player+1; tmpplr2++);
		{
			if (tmpplr == 0)
			{
				printf ("\n\n����� �����Դϴ�.\n");
				while (playerstatus[tmpplr] == 0)
				{
					printf("\n�� �� �� �����ðڽ��ϱ�? �ƴϸ� ���⼭ ���߽ðڽ��ϱ�?\n");
					gostop();
				}
				
			} 
			else if (tmpplr == N_player)
			{
				printf ("\n\n����������, �� �����Դϴ�.\n");
				printf ("���� ���� ù ���� ī��� ");
				printcard(N_player, 0);
				printf (" �Դϴ�.");
				printf(" �� [%i]", mycardsum[N_player]);
				/*������ ī�带 �����Ѵ�.*/  
				printingamecard(N_player);
				npcgo(tmpplr);
				
			}
			else
			{
				printf ("\n\nNPC %i ���� �����Դϴ�.\n", tmpplr);
				while (playerstatus[tmpplr] == 0)
				{
					npcgo(tmpplr);
				}
			}
			/*�� �÷��̾��� ���� ��Ÿ���� for ���̴�.if ���� �̿��� ������� �ϰ� NPC�� ���� �����ϰ� ��ü�����δ� ���� ������ �ִ´�.*/
			/*playerstatus[tmpplr] �� 0�� �ƴ� ���=������ �̸� ������ �� ��� �� �� �κ��� ��ŵ�ϵ��� while ���*/ 
			/*�� while �� �� �� ���ư� ������ ī�带 ������ ���� �ѹ� �����Ѵ�.*/ 

			/*���� �� ������ �÷��̾��� ���и� ����, ���� �����ϰ� �Ļ� ���θ� Ȯ���Ѵ�. �Ļ��ϰų� ī�� ���Ǵپ��� ���ӿ����� 1�� �ٲ�.*/ 
		}
			/*������ ���� ��ġ�� ���� ����, ���þ׼� �����ְ� �� ���� �� �ݺ��� 1 ��
			������ ����- ī�� (����)�� ���ų� �÷��̾� �Ѹ� �Ļ��. �ں������� �¸��� ����
			mymoney ������ ���� ���� �÷��̾ �¸��Ѵ�.*/
		if (currentcard>((N_CARDSET*N_CARD)-(N_player+1*2)))
		{
			gameover = 1;
		/*ī�尡 2�徿 ������ �� ���� ��ŭ �پ��� ������ ������.*/
		}
		int wtf;
		for (wtf=0; wtf<N_player; wtf++)
		{
			if (mymoney[wtf]<=0)
			{
				gameover=2;
			}
				/*mymoney[N_player]�� ���� 0���� �˻��غ��� �Լ�*/
			/*�÷��̾� �Ѹ� �Ļ�� ������ ������.*/ 
		}
	}
	while (gameover==0);
	
	if (gameover==2)
	{
		/*�� ���� �Ļ����� �� ������ ����*/ 
		printf ("\n\n�� ���� �Ļ��ϼ����Ƿ� ���⿡�� ������ �����ϴ�.\n");
	} 
	else if (gameover==1)
	{
		/*ī�带 �� ���� �� ������ ����*/ 
		printf ("\n\nī�带 �� �����Ƿ� ���⿡�� ������ �����ϴ�.\n");
	}
	
	winner = findwinner();
	
	if (winner==0)
	{
		printf ("\n\n���ϵ帳�ϴ�, ����ϼ̱���.\n");
	}
	else if (winner==N_player) 
	{
		printf ("\n\n����ڰ�.. ���ΰ���? �̷� �� ���µ�. ������ �� �����ϴ�.\n");
	}
	else
	{
		printf ("\n\nNPC %i �� ��� ���ϵ帳�ϴ�.\n", winner);
	} 
	
	
	/*2- ������ �������- ���Ǽ��� ��õ� ��*/

	/*3-������ �������- ����� �ʿ����� ��*/ 
	
	return 0;
}
