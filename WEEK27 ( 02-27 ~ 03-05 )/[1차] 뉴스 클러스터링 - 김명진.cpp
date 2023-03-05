#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(string str1, string str2)
{
	vector<pair<char, char>> temp1;
	vector<pair<char, char>> temp2;
	vector<pair<int, pair<char, char>>> count1;
	vector<pair<int, pair<char, char>>> count2;

	int interSection = 0;
	int unionSection = 0;

	int answer = 0;

	for (int i = 0; i < str1.size()-1; ++i)
	{
		short check = 0;
		for (int j = 0; j < 2; ++j)
		{
			if ('A' <= str1[i + j] && str1[i + j] <= 'Z')
			{
				if (j == 0)
				{
					check += 1;
				}
				else
				{
					check += 2;
				}
				continue;
			}
			else if ('a' <= str1[i + j] && str1[i + j] <= 'z')
			{
				continue;
			}
			else
			{
				check = -1;
				break;
			}
		}
		if (check == 0)
		{
			temp1.push_back(make_pair(str1[i], str1[i + 1]));
		}
		else if (check == 1)
		{
			temp1.push_back(make_pair(str1[i]+32, str1[i + 1]));
		}
		else if (check == 2)
		{
			temp1.push_back(make_pair(str1[i], str1[i + 1]+32));
		}
		else if (check == 3)
		{
			temp1.push_back(make_pair(str1[i]+32, str1[i + 1]+32));
		}
	}

	for (int i = 0; i < str2.size() - 1; ++i)
	{
		short check = 0;
		for (int j = 0; j < 2; ++j)
		{
			if ('A' <= str2[i + j] && str2[i + j] <= 'Z')
			{
				if (j == 0)
				{
					check += 1;
				}
				else
				{
					check += 2;
				}
				continue;
			}
			else if ('a' <= str2[i + j] && str2[i + j] <= 'z')
			{
				continue;
			}
			else
			{
				check = -1;
				break;
			}
		}
		if (check == 0)
		{
			temp2.push_back(make_pair(str2[i], str2[i + 1]));
		}
		else if (check == 1)
		{
			temp2.push_back(make_pair(str2[i] + 32, str2[i + 1]));
		}
		else if (check == 2)
		{
			temp2.push_back(make_pair(str2[i], str2[i + 1] + 32));
		}
		else if (check == 3)
		{
			temp2.push_back(make_pair(str2[i] + 32, str2[i + 1] + 32));
		}
	}

	for (int i = 0; i < temp1.size(); ++i)
	{
		int isExsist = -1;
		for (int j = 0; j < count1.size(); ++j)
		{
			if (temp1[i].first == count1[j].second.first && temp1[i].second == count1[j].second.second)
			{
				isExsist = j;
			}
		}
		if (isExsist != -1)
		{
			++count1[isExsist].first;
		}
		else
		{
			count1.push_back(make_pair(1, temp1[i]));
		}
	}
	
	for (int i = 0; i < temp2.size(); ++i)
	{
		int isExsist = -1;
		for (int j = 0; j < count2.size(); ++j)
		{
			if (temp2[i].first == count2[j].second.first && temp2[i].second == count2[j].second.second)
			{
				isExsist = j;
			}
		}
		if (isExsist != -1)
		{
			++count2[isExsist].first;
		}
		else
		{
			count2.push_back(make_pair(1, temp2[i]));
		}
	}

	for (int i = 0; i < count1.size(); ++i)
	{
		for (int j = 0; j < count2.size(); ++j)
		{
			if (count1[i].second.first == count2[j].second.first && count1[i].second.second == count2[j].second.second)
			{
				interSection += min(count1[i].first, count2[j].first);
			}
		}
	}

	unionSection = temp1.size() + temp2.size() - interSection;

	if (unionSection == 0) answer = 65536;
	else answer = (int)((float)interSection / unionSection * 65536);

	return answer;
}