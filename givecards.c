void carddraw()
/*카드를 한 장 뽑는 함수*/ 
{
 } 

void offercards()
/*처음에 두 장 주는 데 쓰는 함수*/ 
{
}

int checksum21(int a)
/*합이 21인지 체크해야 하는 부분에 일일이 체크하는 대신 checksum 함수를 쓸 것이다.*/
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
	/*if  mycardsum[n]이 21일 경우 그 플레이어는 블랙잭이다. 블랙잭 여부를 구현하려면?*/
 } 
