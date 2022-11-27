#include <iostream>
#include <string>
#include <list>
#include <cmath>

using namespace std;

//알파벳의 대문자의 범위는 90까지
#define MAX 91

int N = 0;
int result = 0;
int alphabet[MAX];
list<int> myAlphabetList;

int main()
{
	// 초기화
	for (int i = 0; i < MAX; i++)
	{
		alphabet[i] = 0;
	}

	// 단어의 수를 입력 받음
	cin >> N;

	while (N > 0)
	{
		// string 값으로 입력을 받음
		string tempStr = "";
		cin >> tempStr;

		// string 값의 인덱스에 따른 가치를 더해준다.
		// EX] 3 ABC BBB A = 100, B = 121, C = 1
		for (int i = tempStr.length() - 1; i >= 0; i--)
		{
			alphabet[(int)tempStr[i]] += pow(10, tempStr.length() - i - 1);
		}

		// 단어를 받은 만큼 N을 감소
		N--;
	}

	for (int i = 0; i < MAX; i++)
	{
		// 가치가 입력된 값들을 리스트에 넣음(정렬을 위함)
		if (alphabet[i] != 0)
		{
			myAlphabetList.push_back(alphabet[i]);
		}
	}

	// 내림차순으로 정렬 
	myAlphabetList.sort(greater<int>());

	int value = 9;
	int result = 0;
	// 가치가 높은 알파벳 부터 높은 가치를 곱해줌
	for (int i : myAlphabetList)
	{
		result += value * i;
		value--;
	}

	// 결과값 출력
	cout << result;
	return 0;
}