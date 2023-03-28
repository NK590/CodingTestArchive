#include <string>
#include <vector>

using namespace std;

struct WebPageS
{
	string _MyURL = "";
	int index = 0;
	int _BasicScore = 0;
	vector<string> _External_links;
	double _LinkScore = 0;
	double _MatchingScore = 0;

	WebPageS(string p_Str, string p_Word)
	{
		FindURL(p_Str);
		BasicScore(p_Str, p_Word);
	}

	void FindURL(string p_Str)
	{
		string StartText = "<meta property=\"og:url\" content=\"https://";
		string EndText = "\"/>";
		int _StartIndex = p_Str.find(StartText);
		int _EndIndex = p_Str.find(EndText, _StartIndex + StartText.length());
		for (auto& it : p_Str) it = toupper(it);
		_MyURL = p_Str.substr(_StartIndex + StartText.length(), _EndIndex - (_StartIndex + StartText.length()));
	}
	
	void BasicScore(string p_Str, string p_Word)
	{
		string StartText = "<body>";
		string EndText = "</body>";
		int _StartIndex = p_Str.find(StartText);
		int _EndIndex = p_Str.find(EndText, _StartIndex + StartText.length());
		string _BodyString = p_Str.substr(_StartIndex + StartText.length(), _EndIndex - (_StartIndex + StartText.length()));
		for (auto& it : _BodyString) it = toupper(it);
		for (auto& it : p_Word) it = toupper(it);

		vector<string> tempV;
		string temp;
		for (auto it : _BodyString) {
			if (it < 65 || it > 90) {
				tempV.push_back(temp);
				temp = "";
			}
			else temp.push_back(it);
		}

		for (auto& it : tempV) 
			if (it == p_Word) _BasicScore++;
		

		FindExternallink(_BodyString);
	}

	void FindExternallink(string p_BodyString)
	{
		string StartText = "<A HREF=\"HTTPS://";

		int _Index = p_BodyString.find(StartText);

		while (_Index != string::npos) {
			_Index += StartText.length();
			string _Externallink = "";
			while (p_BodyString[_Index] != '\"') {
				_Externallink += p_BodyString[_Index++];
			}
			_External_links.push_back(_Externallink);
			p_BodyString = p_BodyString.substr(_Index); // 문자열 자르기
			_Index = p_BodyString.find(StartText);
		}
	}
};

int solution(string word, vector<string> pages) {
    int answer = 0;
	int index = 0;
	vector<WebPageS> WebPagesV;
	for (auto& it : pages) {
		WebPageS webPageS(it, word);
		webPageS.index = index++;
		WebPagesV.push_back(webPageS);
	}

	for (auto& WebPage : WebPagesV) {
		for (auto& External_link : WebPage._External_links) {
			for (auto& Target : WebPagesV) {
				if (Target._MyURL == External_link) {
					Target._LinkScore += (double)WebPage._BasicScore / (double)WebPage._External_links.size();
				}
			}
		}
	}

	double MaxScore = 0;
	for (auto& WebPage : WebPagesV) {
		WebPage._MatchingScore = WebPage._LinkScore + WebPage._BasicScore;
		if (MaxScore < WebPage._MatchingScore) {
			answer = WebPage.index;
			MaxScore = WebPage._MatchingScore;
		}
	}
	return answer;
}
