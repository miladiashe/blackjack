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
/*������ ������ �������� �˸��� ����*/  
int trump[N_CARD];
/*ī�� �� ��*/ 
int cardtray[N_CARDSET*N_CARD];
/*N_CARDSET����  ī�带 ���� ī�� �ѹ�ġ*/  
int acestatus[N_maxplayer+1];
/*�� ��° �÷��̾ ���̽��� �޾Ҵ��� ���� �����ϴ� ��. �ϴ� ���������� ������.*/ 
int currentcard;
/*���� ī�带 �� �� ����ߴ��� ��Ƶδ� ����*/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	int tmpplr;
	int tmpplr2;
	/*for ���� ������ ���� �ӽú���*/ 
	int round=0;
	/*������ n��° �������� �����ϴ� ����*/ 
	int playerstatus[N_player];
	/*�÷��̾� �Ǵ� NPC�� ���¸� ��Ÿ����.  0�� �� �ƹ��͵� �ƴ�, 1�� �� 21 �ʰ��� ���� ����, 2�� �� ī�� �ޱ� ���� , 21�� �� ����*/ 
	playerconfig();
		/*player ���� �����Ѵ�. ���� �̸� �ش�.*/ 
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
		for (tmpplr=0; tmpplr<N_maxplayer; tmpplr++);
		{
			playerstatus[tmpplr]=0;
		}
		/*�̹� ������ �÷��̾� ���� �ʱ�ȭ*/ 
		for (tmpplr=0; tmpplr<N_maxplayer+1; tmpplr++);
		{
			for (tmpplr=0; tmpplr2<N_maxhand; tmpplr2++);
			{
				mycard[tmpplr][N_maxhand]=0;
			}
		}
		/*�̹� ������ �÷��̾� �ڵ� �ʱ�ȭ*/ 
		betmoney(); 
			/*������ �׼� ����*/
			//�Ϸ� 
		offercards(); 
		/*�ϴ� ����������  1�徿 2��  �������´�(������ ���� ����д�)*/
			for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			playerstatus[tmpplr] = checksum21(tmpplr);
		}
		/*ī�带 ������ �� ��� �÷��̾��� ���� ���θ� Ȯ��*/ 
		printinitialcard();
		/*offercards���� �� ���� ������ �����ִ� �Լ�.*/ 

		for (tmpplr=1; tmpplr<N_player; tmpplr++);
		{
			/*�� �÷��̾��� ���� ��Ÿ���� for ���̴�.*/
			while (playerstatus[tmpplr]!=0)
			/*playerstatus[tmpplr] �� 0�� �ƴ� ���=������ �̸� ������ �� ��� �� �� �κ��� ��ŵ�ϵ��� while ���*/ 
			/*�� while �� �� �� ���ư� ������ ī�带 ������ ���� �ѹ� �����Ѵ�.*/ 
			{
			}
			/*���� �� ������ �÷��̾��� ���и� ����, ���� �����ϰ� �Ļ� ���θ� Ȯ���Ѵ�. �Ļ��ϰų� ī�� ���Ǵپ��� ���ӿ����� 1�� �ٲ�.*/ 
		}
			/*������ ���� ��ġ�� ���� ����, ���þ׼� �����ְ� �� ���� �� �ݺ��� 1 ��
			������ ����- ī�� (����)�� ���ų� �÷��̾� �Ѹ� �Ļ��. �ں������� �¸��� ����*/ 
	}
	while (gameover==0);
		 
		
	/*2- ������ �������- ���Ǽ��� ��õ� ��*/

	/*3-������ �������- ����� �ʿ����� ��*/ 
	
	return 0;
}
