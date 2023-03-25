#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MyPage
{
    string url;
    int nativePoint;
    double outsidePoint;
};

vector<MyPage> myPages;

void findUrl(vector<string> pages)
{
    for (int i = 0; i < pages.size(); ++i)
    {
        MyPage pageTemp;

        int index = 0;
        index = pages[i].find("<meta property=\"og:url\" content=");

        string url;
        while (pages[i][index+33] != '\"')
        {
            url.push_back(pages[i][index+33]);
            index++;
        }
        pageTemp.url = url;
        pageTemp.nativePoint = 0;
        pageTemp.outsidePoint = 0;
        myPages.push_back(pageTemp);
    }
}

void countNativePoint(string word, vector<string> pages)
{
    for (int i = 0; i < pages.size(); ++i)
    {
        int startIdx = 0;

        int endIdx = pages[i].size();

        string bodyTemp;
        while (startIdx != endIdx)
        {
            if ('A' <= pages[i][startIdx] && pages[i][startIdx] <= 'Z')
            {
                bodyTemp.push_back(pages[i][startIdx] + 32);
            }
            else
            {
                bodyTemp.push_back(pages[i][startIdx]);
            }
            startIdx++;
        }

        string smallWord;
        for (int j = 0; j < word.size(); ++j)
        {
            if (word[j] >= 'A' && word[j] <= 'Z')
            {
                smallWord.push_back(word[j] + 32);
            }
            else
            {
                smallWord.push_back(word[j]);
            }
        }

        int nativePoint = 0;
        int loopIdx = 0;
        while (loopIdx < bodyTemp.size())
        {
            if ((bodyTemp[loopIdx] < 'a' || bodyTemp[loopIdx] > 'z') && loopIdx + 1 <= bodyTemp.size()-1)
            {
                int j = loopIdx + 1;
                for (int k = 0; k < smallWord.size(); ++k)
                {
                    if (k == smallWord.size() - 1 && j+k == bodyTemp.size() - 1 && bodyTemp[j + k] == smallWord[k])
                    {
                        ++nativePoint;
                        break;
                    }
                    else if (k == smallWord.size() - 1 && (bodyTemp[j + k + 1] < 'a' || bodyTemp[j + k + 1] > 'z') && bodyTemp[j + k] == smallWord[k])
                    {
                        ++nativePoint;
                        break;
                    }
                    if (bodyTemp[j + k] == smallWord[k])
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            ++loopIdx;
        }
        myPages[i].nativePoint = nativePoint;
    }
}

void countOutsidePoint(string page, int idx)
{
	vector<string> linkUrls;
	int tempIdx = page.find("<a href=\"");

	while (tempIdx != -1)
	{
		tempIdx += 9;
		string urlTemp = "";
		while (page[tempIdx] != '\"')
		{
			urlTemp += page[tempIdx++];
		}
		linkUrls.push_back(urlTemp);
		page = page.substr(tempIdx);
		tempIdx = page.find("<a href=\"");
	}
    for (int i = 0; i < linkUrls.size(); ++i)
    {
        for (int j = 0; j < myPages.size(); ++j)
        {
            if (linkUrls[i].compare(myPages[j].url) == 0)
            {
                myPages[j].outsidePoint += ((double)myPages[idx].nativePoint / linkUrls.size());
            }
        }
    }
}

int solution(string word, vector<string> pages)
{
    int answer = 0;

    findUrl(pages);
    countNativePoint(word, pages);
    for (int i = 0; i < pages.size(); ++i)
    {
        countOutsidePoint(pages[i], i);
    }

    double finalPoint = 0;
    for (int i = 0; i < myPages.size(); ++i)
    {
        if ((myPages[i].nativePoint + myPages[i].outsidePoint) > finalPoint)
        {
            finalPoint = (myPages[i].nativePoint + myPages[i].outsidePoint);
            answer = i;
        }
        cout << (myPages[i].nativePoint + myPages[i].outsidePoint) << endl;
    }
    return answer;
}

int main()
{
    string word;
    vector<string> pages;

    int pageNum;

    cin >> word >> pageNum;

    string temp;
    for (int i = 0; i < pageNum; ++i)
    {
        cin >> temp;
        pages.push_back(temp);
    }

    solution(word, pages);

    //OutsidePoint를 float이 아닌 double로 다 연산해야함. float을 쓰면 틀렸다고 나옴.
    //메서드내에서 while 문을 돌릴때 매개변수로 vector<string>을 넘기면 coredumped가 뜸.
    //그냥 for문으로 vector<string> 내부 인자인 string만 반복해서 보내면 오류안뜸.
    //위에 애들 찾아내는데 시간 엄청 걸림.
}