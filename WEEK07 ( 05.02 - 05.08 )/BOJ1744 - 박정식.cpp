#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int numCount, result = 0, index;
	vector<int> positiveNumList;
	vector<int> negativeNumList;
	int zeroCount = 0;

	cin >> numCount;

	for (int index = 0; index < numCount; index++)
	{
		int num;
		cin >> num;		
		if (num == 0)
		{
			zeroCount++;
		}
		else if (num > 0)
		{
			if (num > 1)
			{
				positiveNumList.push_back(num);
			}
			else
			{
				result = result + 1;
			}
		}
		else if (num < 0)
		{
			negativeNumList.push_back(num);
		}
	}
	sort(positiveNumList.begin(), positiveNumList.end());
	sort(negativeNumList.begin(), negativeNumList.end());

	// ��� ó��
	int positiveSize = positiveNumList.size();
	index = 0;
	if (positiveSize % 2 != 0) {
		result = result + positiveNumList[0];
		index++;
	}
	for (; index < positiveSize; index = index + 2)
	{
		result = result + positiveNumList[index] * positiveNumList[index + 1];
	}

	// ���� ó��
	int negativeSize = negativeNumList.size();
	index = 0;
	if (negativeSize % 2 != 0) {
		if (zeroCount == 0)
		{			
			result = result + negativeNumList[negativeSize - 1];			
		}		
		negativeSize--;
	}
	for (; index < negativeSize; index = index + 2)
	{
		result = result + negativeNumList[index] * negativeNumList[index + 1];
	}

	cout << result << endl;

	return 0;
}

/*
�� ����
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��	128 MB	22988	6674	5322	28.263%
����
���̰� N�� ������ �־����� ��, �� ������ ���� ���Ϸ��� �Ѵ�. ������, �׳� �� ������ ���� ��� ���ؼ� ���ϴ� ���� �ƴ϶�, ������ �� ���� �������� �Ѵ�. � ���� �������� �� ��, ��ġ�� ������� ���� �� �ִ�. ������, ���� ��ġ�� �ִ� ��(�ڱ� �ڽ�)�� ���� ���� �Ұ����ϴ�. �׸��� � ���� ���� �Ǹ�, ������ ���� ���� �� ���� ���� ���� ���� �Ŀ� ���Ѵ�.

���� ���, � ������ {0, 1, 2, 4, 3, 5}�� ��, �׳� �� ������ ���� ���ϸ� 0+1+2+4+3+5 = 15�̴�. ������, 2�� 3�� ����, 4�� 5�� ���� �Ǹ�, 0+1+(2*3)+(4*5) = 27�� �Ǿ� �ִ밡 �ȴ�.

������ ��� ���� �� �ѹ��� ���ų�, �ƴϸ� ���� �ʾƾ��Ѵ�.

������ �־����� ��, ������ �� ���� ������ ������ ��, �� ���� �ִ밡 �ǰ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. N�� 50���� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� ������ �� ���� �־�����. ������ ���� -1,000���� ũ�ų� ����, 1,000���� �۰ų� ���� �����̴�.

���
���� ���� �ִ밡 ������ ������ �� ���� ����Ѵ�. ������ �׻� 231���� �۴�.

���� �Է� 1
4
-1
2
1
3
���� ��� 1
6
���� �Է� 2
6
0
1
2
4
3
5
���� ��� 2
27
���� �Է� 3
1
-1
���� ��� 3
-1
���� �Է� 4
3
-1
0
1
���� ��� 4
1
���� �Է� 5
2
1
1
���� ��� 5
2
*/