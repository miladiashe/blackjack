void carddraw()
/*ī�带 �� �� �̴� �Լ�*/ 
{
 } 

void offercards()
/*ó���� �� �� �ִ� �� ���� �Լ�*/ 
{
}

int checksum21(int a)
/*���� 21���� üũ�ؾ� �ϴ� �κп� ������ üũ�ϴ� ��� checksum �Լ��� �� ���̴�.*/
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
