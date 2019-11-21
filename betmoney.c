#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void betmoney()
/*돈 거는 데 쓰는 함수*/ 
{
	extern N_player;
	extern int mymoney[];
	extern int bet[];
	printf("\n얼마를 거시겠습니까?\n현재 %i 달러를 가지고 계십니다.\n", mymoney[0]);
	do
	{
		bet[0] = getIntegerInput();
	}
	while(bet[0] > mymoney[0]);
	/*시간이 남으면 다시 입력할 떄 입력이 어떻게 틀렸는지 말해주는 조건문 구성*/ 
	mymoney[0] = mymoney[0] - bet[0];
	if (mymoney[0]>0)
	{
		printf("남은 돈은 %i 달러입니니다.\n", mymoney[0]);
	}
	else
	{
	printf("남은 돈을 모두 거셨습니다. 과연 승리할 수 있을까요?\n");
	}

	
	/* 내 돈을 거는 부분*/
	srand((unsigned)time(NULL));
	int tmpplr;
	for	(tmpplr=1; tmpplr<N_player; tmpplr++)
	{
		do
		{
		bet[tmpplr] = (rand()%N_MAXBET)+1;
		}
		while(bet[tmpplr] > mymoney[tmpplr]);
		/*0달러 이하로 돈이 계속 내려가도 계속 거는 걸 방지하기 위한 조건*/ 
		printf("\nNPC %i 님은 %i 달러를 거셨습니다.\n", tmpplr, bet[tmpplr]);
		mymoney[tmpplr] = mymoney[tmpplr]-bet[tmpplr];
		if (mymoney[tmpplr]>0)
		{
		printf("NPC %i 님께 남은 돈은 %i 달러입니다.\n", tmpplr, mymoney[tmpplr]);
		}
		else
		{
			printf("남은 돈을 모두 거셨습니다. 과연 승리할 수 있을까요?\n");
		}
		/*그냥 플레이의 재미를 위해 남은 돈이 없을 경우 다른 대사가 출력되도록 하였다.*/ 
	}
	/*NPC의 돈을 거는 부분*/ 
	/*랜덤함수 이용, 1과 N_MAXBET ㄴ사이에 랜덤하게 돈을 건다.*/ 
}

int findwinner()
{
	int maxmoney = 0;
	int i;
	int tmpwinner; 
	extern int mymoney[N_maxplayer];
	
	for(i = 0; i<N_maxplayer; i++)
    {
        if(mymoney[i] > maxmoney) 
            maxmoney = mymoney[i]; 
            /*mymoney[i]의 값 중 제일 큰 게  maxmoney에  들어 감*/ 
    }
    for(i = 0; i<N_maxplayer; i++)
    {
        if(mymoney[i] == maxmoney) 
            tmpwinner = i; 
            /*maxmoney에 들어간 i값을 tmpwinner에 넣는다.*/ 
    }
	return tmpwinner;
	
	/*남은 mymoney 액수로 우승자를 찾아 우승자의 플레이어 번호를 반환하는 함수.*/ 
} 

int roundwinner()
{
	extern int playerstatus[N_maxplayer+1];
	extern int N_player;
	extern int iamwinner[N_maxplayer+1];
	extern int mycardsum[N_maxplayer+1];
	int s;
	if (playerstatus[N_player] == 21)
	{
		printf("제가 이겼습니다.\n");
		iamwinner[N_player] = 1;
		for(s=0; s<N_player; s++)
		{
			iamwinner[N_player] = 0;
		}
		/*딜러 블랙잭으로 승리*/
		/*iamwinner[N_maxplayer+1]에 딜러 칸 말고 전부 0*/
	}
	else if (playerstatus[N_player] == 1)
	{
		iamwinner[N_player] = 0;
		for(s=0; s<N_player; s++)
		{
			printf("딜러인 제가 죽었으니, 살아남은 모든 분이 승리하셨습니다.\n");
			if(playerstatus[s] != 1)
			{
				iamwinner[s] = 1;
			}
			/*21 초과헤서 playerstatus가 1이 되지 않은 사람은 모두 승리*/ 
			else
			{
			}
			/*딜러사망*/ 

		}
	}
	else
	/*그 외의  경우*/ 
	{
		iamwinner[N_player] = 0;
		/*딜러는 돈을 걸지 않으므로 그냥 0으로 해도 된다.*/ 
		for(s=0; s<N_player; s++)
		{
			if (playerstatus[s] == 21)
			{
				iamwinner[s] = 1;
				/*블랙잭인 경우 승리.*/ 
			}
			else if(playerstatus[s] == 1) 
			{
				/*21이 넘은 사람은 패배.*/
				iamwinner[s] = 0;
			}
			else
			{
				if (mycardsum[N_player] < mycardsum[s])
				{
					iamwinner[s] = 1;
					/*21 안넘고 블랙잭도 아닌데 딜러보다 높은 사람은 승리*/
				}
				else
				{
					iamwinner[s] = 0;
					/*21 안넘고 블랙잭도 아닌데 딜러보다 낮은 사람은 패배*/
				}
			} 

			
		}
	}

	
	/*각 라운드마다 이 함수로 우승자를 찾자*/ 
	takemymoney();
	
}
int takemymoney()
{
	extern int mymoney[N_maxplayer];
	extern int bet[N_maxplayer]; 
	extern int N_player;
	extern int iamwinner[N_maxplayer+1];
	int h;
	
	for (h=0; h<N_player; h++)
	{
		if (iamwinner[h]=0)
		{
			bet[h] = 0;
			/*베팅 액수는 초기화를 여기서 한다*/ 
			/*졌을 경우 베팅액수가 날아간다.*/ 
		}
		else
		{
			mymoney[h] = mymoney[h]+(2*bet[h]);
			/*베팅한 금액의 두 배를 돌려준다.*/ 
			bet[h] = 0;
		}
	}
	if (iamwinner[0]=1)
	{
		printf ("\n승리 축하드립니다.");
	}
	printf (" %i달러 남으셨습니다. \n", mymoney[0]);
	for (h=1; h<N_player; h++)
	{
		printf ("\nNPC %i님, ", h);
		if (iamwinner[h]=1)
		{
			printf ("승리 축하드립니다. ");
		}
		printf ("%i달러 남으셨습니다. \n", mymoney[h]);
	}
	/*베팅한 돈을 돌려주는 함수*/ 
}
