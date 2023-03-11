#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct File
{
	string fullName;
	string head;
	int number;
	int inputNumber;
};

vector<string> v = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
vector<string> v2 = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };

bool Compare(File file1, File file2)
{
	// ��� ���� ��
	if (file1.head > file2.head)
		return false;
	else if (file1.head < file2.head)
		return true;

	// ��尡 ���ٸ� number ��
	if (file1.number > file2.number)
		return false;
	else if (file1.number < file2.number)
		return true;

	// number ���� ���ٸ� ���� ���� ����
	return file1.inputNumber < file2.inputNumber;
}

// ���ڰ� �������� üũ�ϴ� �Լ�
bool IsNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

vector<string> solution(vector<string> files)
{
	vector<File> sortFiles;
	vector<string> answer;

	int cnt = 0;
	for (auto file : files)
	{
		File tempFile;
		tempFile.fullName = file;

		int idx = 0;
		for (; idx < file.size(); idx++)
		{
			// ���ڿ� üũ
			if (IsNumber(file[idx]) == false)
			{
				if (file[idx] >= 'A' && file[idx] <= 'Z')
				{
					tempFile.head += (file[idx] + 32);
				}
				else
				{
					tempFile.head += file[idx];
				}
			}
			else
			{
				break;
			}
		}

		string strNumber;
		for (; idx < file.size(); idx++)
		{
			if (file[idx] >= '0' && file[idx] <= '9')
				strNumber += file[idx];
			else
				break;
		}
		tempFile.number = stoi(strNumber);
		tempFile.inputNumber = cnt;


		cnt++;
		sortFiles.push_back(tempFile);
	}
	

	sort(sortFiles.begin(), sortFiles.end(), Compare);

	for (auto sortFile : sortFiles)
	{
		answer.push_back(sortFile.fullName);
	}

	return answer;
}

int main()
{
	solution(v2);
	return 0;
}