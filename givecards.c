#include "define.h"

int carddraw()
/*ī�带 �� �� �̴� �Լ�*/ 
{
 } 

void offercards()
/*ó���� �� �� �ִ� �� ���� �Լ�*/ 
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
