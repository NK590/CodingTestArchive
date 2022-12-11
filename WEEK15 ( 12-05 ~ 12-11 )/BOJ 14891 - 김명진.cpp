#include <iostream>
#include <cmath>

using namespace std;

string gears[4];
int inputGear[100];
int inputDir[100];

void RotateGear(int gearNum, int dir)
{
	//cout << "rotateGear =>" << gearNum + 1 << "\t" << "dir =>" << dir << "\n";
	string temp = "00000000";

	if (dir < 0)
	{
		for (int i = 0; i < 8; ++i)
		{
			temp[i] = gears[gearNum][(i + 1) % 8];
		}
	}
	else
	{
		for (int i = 0; i < 8; ++i)
		{
			temp[i] = gears[gearNum][(i + 7) % 8];
		}
	}

	gears[gearNum] = temp;
}

void ControlGear(int gearNum, int dir)
{
	//cout << "controlGear =>" << gearNum + 1 << "\t" <<"dir =>" << dir << "\n";

	bool between[3];
	for (int i = 0; i < 3; ++i)
	{
		if (gears[i][2] != gears[i + 1][6])
		{
			between[i] = true;
		}
		else
		{
			between[i] = false;
		}
	}

	int curDir = dir;

	switch (gearNum)
	{
	case 0:
			if (between[0])
			{
				curDir *= -1;
				RotateGear(1, curDir);
				if (between[1])
				{
					curDir *= -1;
					RotateGear(2, curDir);
					if (between[2])
					{
						curDir *= -1;
						RotateGear(3, curDir);
					}
				}
			}
		break;
	case 1:
		curDir *= -1;
		if (between[0])
		{
			RotateGear(0, curDir);
		}
		if (between[1])
		{
			RotateGear(2, curDir);
			if (between[2])
			{
				curDir *= -1;
				RotateGear(3, curDir);
			}
		}
		break;
	case 2:
		curDir *= -1;
		if (between[2])
		{
			RotateGear(3, curDir);
		}
		if (between[1])
		{
			RotateGear(1, curDir);
			if (between[0])
			{
				curDir *= -1;
				RotateGear(0, curDir);
			}
		}
		break;
	case 3:
			if (between[2])
			{
				curDir *= -1;
				RotateGear(2, curDir);
				if (between[1])
				{
					curDir *= -1;
					RotateGear(1, curDir);
					if (between[0])
					{
						curDir *= -1;
						RotateGear(0, curDir);
					}
				}
			}
		break;
	}

	RotateGear(gearNum, dir);
}

float CalculateScore()
{
	float score = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (gears[i][0] == '1')
		{
			score += pow(2, i);
		}
	}
	return score;
}

void DebugGear()
{
	cout << "==================================" << "\n";
	for (int i = 0; i < 4; ++i)
	{
		cout << gears[i] << "\n";
	}
	cout << "==================================" << "\n";

	for (int i = 0; i < 3; ++i)
	{
		if (gears[i][2] != gears[i + 1][6])
		{
			cout << "between" << i << "===========O============" << "\n";
		}
		else
		{
			cout << "between" << i << "===========X============" << "\n";
		}
	}

}


int main()
{
	for (int i = 0; i < 4; ++i)
	{
		cin >> gears[i];
	}

	int rotateNum;

	cin >> rotateNum;

	for (int i = 0; i < rotateNum; ++i)
	{
		cin >> inputGear[i];
		cin >> inputDir[i];
	}

	for (int i = 0; i < rotateNum; ++i)
	{
		//DebugGear();
		ControlGear(inputGear[i]-1, inputDir[i]);
	}

	//DebugGear();

	cout << round(CalculateScore());
}