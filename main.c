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

char *trump[N_CARD];
/*ī�� �� ��*/ 
char *cardtray[N_CARDSET*N_CARD];
/*N_CARDSET����  ī�带 ���� ī�� �ѹ�ġ*/  


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	
	int round=0;
	/*������ n��° �������� �����ϴ� ����*/ 
	int playerstatus[N_player];
	/*�÷��̾� �Ǵ� NPC�� ���¸� ��Ÿ����.  0�� �� �ƹ��͵� �ƴ�, 1�� �� 21 �ʰ��� ���� ����, 2�� �� ī�� �ޱ� ���� , 21�� �� ����*/ 
	playerconfig();
		/*player ���� �����Ѵ�. ���� �̸� �ش�.*/ 
	makecards();
		/*ī�� ���� N_CARDSET ��ŭ  ���� �Լ�*/
	mixcards();
		/*ī�带 ���´�-������ �迭�� ī�� ���� ���� ���ϱ�?*/
	do{
		
		/*���⼭ �ѹ� �ݺ��� ����- �� ���带 ��Ÿ����.*/
		int tmpplr;
		/*for ���� ������ ���� �ӽú���*/ 
		++round;
		printf ("\n - ROUND %i - \n", round); 
		for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			playerstatus[tmpplr]=0;
		}
		/*�̹� ������ �÷��̾� ���� �ʱ�ȭ*/ 
		betmoney(); 
			/*������ �׼� ����*/
		offercards(); 
		/*�ϴ� ����������  1�徿 2��  �������´�(������ ���� ����д�)*/
			for (tmpplr=0; tmpplr<N_player; tmpplr++);
		{
			playerstatus[tmpplr] = checksum21(tmpplr);
		}
		/*ī�带 ������ �� ��� �÷��̾��� ���� ���θ� Ȯ��*/ 

		for (tmpplr=1; tmpplr<N_player; tmpplr++);
		{
			/*�� �÷��̾��� ���� ��Ÿ���� for ���̴�.*/
			while (playerstatus[tmpplr]!=0)
			/*playerstatus[tmpplr] �� 0�� �ƴ� ���=������ �̸� ������ �� ��� �� �� �κ��� ��ŵ�ϵ��� while ���*/ 
			/*�� while �� �� �� ���ư� ������ ī�带 ������ ���� �ѹ� �����Ѵ�.*/ 
			{
			}
		}

			/*������ ���� ��ġ�� ���� ����, ���þ׼� �����ְ� �� ���� �� �ݺ��� 1 ��
			������ ����- ī�� �پ��ų� �÷��̾� �Ѹ� �Ļ��. �ں������� �¸��� ����*/ 
	}
	while (gameover==0);
		 
		
	/*2- ������ �������- ���Ǽ��� ��õ� ��*/

	/*3-������ �������- ����� �ʿ����� ��*/ 
	
	return 0;
}
