#include <stdio.h>
#include <stdlib.h>

int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    //���� �����Լ� = getIntegerInput(); 
    
    return input;
}

int reading(){
	int ok = 0
;	do
	{
		printf("\nȮ���ϼ̴ٸ� �ƹ� Ű�� �Է����ּ���.(0 ����)");
		ok = getIntegerInput();
	}
	while(ok == 0);
	/*�ʹ� ���� ���� ������ ��������, ���丮�� ���پ� �ѱ� �� �ִ� ����ó�� �߰��߰��� ��� �Է��� �޴� ����� ���� �õ��غ���.*/ 
}
