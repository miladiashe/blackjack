#include <stdio.h>
#include <stdlib.h>


/*���� �����*/ 

#define N_maxplayer 5
/*�ִ� �÷��̾��*/ 
const int N_initmoney = 50;
/*�ʱ� �ں�*/
#define N_maxhand 11

#define N_CARD 52
#define N_CARDSET 1
/*ī�� ��Ʈ ����*/ 

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

char *trump[N_CARD];
/*ī�� �� ���� ������ �׳� ���� ����� �������� �ʰڽ��ϴ�*/ 
char *cardtray[N_CARDSET*52];
/*N_CARDSET����  ī�带 ���� ī�� �ѹ�ġ*/  


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) { 
	
	int round=0;
	/*������ n��° �������� �����ϴ� ����*/ 
	playerconfig();
		/*player ���� �����Ѵ�. ���� �̸� �ش�.*/ 
	makecards();
		/*ī�� ���� N_CARDSET ��ŭ  ���� �Լ�*/
	mixcards();
		/*ī�带 ���´�-������ �迭�� ī�� ���� ���� ���ϱ�?*/
	do{
		
		/*���⼭ �ѹ� �ݺ��� ����*/
		round++; 
		betmoney(); 
			/*������ �׼� ����*/
		offercards();
		/*�ϴ� ����������  1�徿 2��  �������´�(������ ���� ����д�)
		�ϴ� �� ��Ȳ�� 21���� üũ���� 21�� ��� �ڵ� �¸�
		�ݺ��� 1-	�� ������ �ƴ��� ����-�÷��̾���� �������
				�ݺ��� 2-	(������ �ǰų� �����ϰų� 21�� ���������� �ݺ�������)�ݺ�2 �� 
				������ ���� ��ġ�� ���� ����, ���þ׼� �����ְ� �� ���� �� �ݺ��� 1 ��
				������ ����- ī�� �پ��ų� �÷��̾� �Ѹ� �Ļ��. �ں������� �¸��� ����*/ 
	}
	while (gameover==0);
		 
		
	/*2- ������ �������- ���Ǽ��� ��õ� ��*/

	/*3-������ �������- ����� �ʿ����� ��*/ 
	
	return 0;
}
