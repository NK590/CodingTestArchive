#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	bool isReverse, isError;

	cin >> t;

	while (t--)
	{
		isError = false;
		isReverse = false;

		deque<int> dq;
		string command, numStr;
		int numCount;
		cin >> command >> numCount >> numStr;

		int numStrLength = numStr.length();
		string num ="";

		// ��ũ�� ���ڿ������� ������ �ٲ� �����͸� �Է��ϴ� for��
		for (int numStrIndex = 1; numStrIndex < numStrLength; numStrIndex++)
		{
			// �ƹ� ���ڵ� ���� ��� �ٷ� ���� ex [] �Է½�
			if (numStr[1] == ']')
			{
				break;
			}

			if (numStr[numStrIndex] >= '0' && numStr[numStrIndex] <= '9')
			{
				num = num + numStr[numStrIndex];
			}
			else if (numStr[numStrIndex] == ',' || numStr[numStrIndex] == ']')
			{
				dq.push_back(stoi(num));
				num.clear();
			}

		}
		// ��ũ�� ����� �����͸� �䱸�ϴ� ���ǿ� ���� R�ϰ�� ����, D�ϰ�� �����ϴ� for��
		int commandLength = command.length();
		for (int commandIndex = 0; commandIndex < commandLength; commandIndex++)
		{
			// R�� ��� isReverse ������ ���� ���������ν� ���߿� �����͸� �о�ö� �տ������� �������� �ڿ������� ���������� ������
			if (command[commandIndex] == 'R')
			{
				isReverse = !isReverse;
			}
			// D�ϰ�� �����͸� �����������
			else if (command[commandIndex] == 'D')
			{
				if (!dq.empty())
				{
					// ���� �������̳� �ƴϳĿ� ���� ��ũ�� �տ��ִ� �����͸� ������ ������ �ڿ��ִ� �����͸� �����Ұ����� �Ǵ�
					if (isReverse)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
				// �����Ͱ� ���µ� ������ �䱸�Ѵٸ� Error
				else
				{
					isError = true;
					cout << "error\n";
					break;
				}
			}
		}
		if (!isError)
		{
			cout << "[";
			while (!dq.empty())
			{
				if (isReverse)
				{
					cout << dq.back();
					dq.pop_back();
				}
				else
				{
					cout << dq.front();
					dq.pop_front();
				}
				if (!dq.empty())
				{
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}


/*
AC �ٱ���
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	256 MB	71764	15948	11146	19.984%
����
�����̴� �ָ��� �� ���� ��� ���ο� ��� AC�� �������. AC�� ���� �迭�� ������ �ϱ� ���� ���� ����̴�. �� ���� �� ���� �Լ� R(������)�� D(������)�� �ִ�.

�Լ� R�� �迭�� �ִ� ���� ������ ������ �Լ��̰�, D�� ù ��° ���� ������ �Լ��̴�. �迭�� ����ִµ� D�� ����� ��쿡�� ������ �߻��Ѵ�.

�Լ��� �����ؼ� �� ���� ����� �� �ִ�. ���� ���, "AB"�� A�� ������ ������ �ٷ� �̾ B�� �����ϴ� �Լ��̴�. ���� ���, "RDD"�� �迭�� ������ ���� ó�� �� ���� ������ �Լ��̴�.

�迭�� �ʱⰪ�� ������ �Լ��� �־����� ��, ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. T�� �ִ� 100�̴�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �Լ� p�� �־�����. p�� ���̴� 1���� ũ�ų� ����, 100,000���� �۰ų� ����.

���� �ٿ��� �迭�� ����ִ� ���� ���� n�� �־�����. (0 �� n �� 100,000)

���� �ٿ��� [x1,...,xn]�� ���� ���·� �迭�� ����ִ� ������ �־�����. (1 �� xi �� 100)

��ü �׽�Ʈ ���̽��� �־����� p�� ������ �հ� n�� ���� 70���� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �Է����� �־��� ���� �迭�� �Լ��� ������ ����� ����Ѵ�. ����, ������ �߻��� ��쿡�� error�� ����Ѵ�.

���� �Է� 1
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
���� ��� 1
[2,1]
error
[1,2,3,5,8]
error
*/