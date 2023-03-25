#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<string, string> userRegistMap;
multimap<int , pair<string, int>> dialogue;
string suffix[] = { "님이 들어왔습니다.", "님이 나갔습니다." };

vector<string> solution(vector<string> record) {
    vector<string> answer;
	int diaCnt = 0;
	for (auto &it : record) {
		string command, uid, nickname;
		int pivot = 0;
		for (int i = 0; i < it.length(); i++) {
			if (it[i] != ' ') command.push_back(it[i]);		
			else {
				pivot = i + 1;
				break;
			}
		}

		for (int i = pivot; i < it.length(); i++) {
			if (it[i] != ' ') uid.push_back(it[i]);			
			else {
				pivot = i + 1;
				break;
			}
		}

		if (command == "Enter" || command == "Change") {
			for (int i = pivot; i < it.length(); i++) nickname.push_back(it[i]);
			auto it2 = userRegistMap.find(uid);
			if (command == "Enter") {
				if (it2 == userRegistMap.end()) userRegistMap.insert(make_pair(uid, nickname));			
				else it2->second = nickname;
				dialogue.insert(make_pair(diaCnt, make_pair(uid, 0)));
			}
			else it2->second = nickname;
		}
		else dialogue.insert(make_pair(diaCnt, make_pair(uid, 1)));
		diaCnt++;
	}

	for (auto &it : dialogue) {
		string str;
		str.insert(0, userRegistMap.find(it.second.first)->second);
		str.insert(str.length(), suffix[it.second.second]);
		answer.push_back(str);
	}

    return answer;
}