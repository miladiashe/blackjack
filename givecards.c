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
	if (mycardsum[a]=21)
	{
		return 21;
	}
	else
	{
		return 0;
	}
	/*if  mycardsum[n]�� 21�� ��� �� �÷��̾�� �����̴�. ���� ���θ� �����Ϸ���?*/
 } 
