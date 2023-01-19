#pragma warning(disable:4996)

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int mem[32] = { 0, };
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int bit;
				//EOF
				if (scanf("%1d", &bit) < 0)
					return 0;
				mem[i] = mem[i] * 2 + bit;
			}
		}



		int PC = 0;
		int acc = 0;
		while (true)
		{
			int instruction = mem[PC];
			//상위 3 bit
			int op = instruction / 32;
			//하위 5 bit
			int val = instruction % 32;

			if (op == 7)
				break;

			PC = (PC + 1) % 32;
			//2^8 = 256
			switch (op)
			{
			case 0:
				mem[val] = acc;
				break;
			case 1:
				acc = mem[val];
				break;
			case 2:
				if (acc == 0)
					PC = val;
				break;
			case 4:
				acc = (acc + 255) % 256;
				break;
			case 5:
				acc = (acc + 1) % 256;
				break;
			case 6:
				PC = val;
				break;
			}
		}

		//8bit
		for (int i = 7; i >= 0; i--)
			printf("%1d", (acc >> i) & 1);
		printf("\n");
	}
	return 0;
}