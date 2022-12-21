#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int Memory[32] = { 0 };
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int bit;
				//EOF
				if (scanf("%1d", &bit) < 0)
					return 0;
				Memory[i] = Memory[i] * 2 + bit;
			}
		}

		int programCnt = 0;
		// adder = 가산기
		int adder = 0;
		while (true)
		{
			// 상위 3자리 bit를 계산해 줍니다.
			int command = Memory[programCnt] / 32;
			// 하위 5자리 비트를 계산해줍니다.(나머지 연산)
			int operand = Memory[programCnt] % 32;

			if (command == 7) { break; }  // HLT 프로그램을 종료한다.

			programCnt = (programCnt + 1) % 32;
			//2^8 = 256
			switch (command)
			{
			case 0: // STA x   메모리 주소 x에 가산기의 값을 저장한다.
				Memory[operand] = adder;
				break;

			case 1: // LDA x   메모리 주소 x의 값을 가산기로 불러온다.
				adder = Memory[operand];
				break;

			case 2: // BEQ x   가산기의 값이 0이면 PC 값을 x로 바꾼다.
				if (adder == 0) { programCnt = operand; }
				break;

			case 3: // NOP     아무 연산도 하지 않는다.
				break;

			case 4: // DEC     가산기 값을 1 감소시킨다.
				adder = (adder + 255) % 256;
				break;

			case 5: // INC     가산기 값을 1 증가시킨다.
				adder = (adder + 1) % 256;
				break;

			case 6: // JMP x   PC 값을 x로 바꾼다.
				programCnt = operand;
				break;
			}
		}

		for (int i = 7; i >= 0; i--)
			printf("%1d", (adder >> i) & 1);
		printf("\n");
	}
	return 0;
}