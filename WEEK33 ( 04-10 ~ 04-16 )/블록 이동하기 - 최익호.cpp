#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 탐색하는 방향 설정 =>  상, 하 ,좌 ,우
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool _MapArr[101][101][2];

// 로봇의 위치 및 현재 시간
tuple<int, int, int, int, int> _RobotPos;
// bfs 탐색을 위한 q
queue<tuple<int, int, int, int, int>> _RobotPosQ;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int _MapMax = board.size();
    pair<int, int> _goal = make_pair(_MapMax - 1, _MapMax - 1); // 목표를 설정

    _RobotPos = make_tuple(0, 0, 0, 1, 0); // 로봇의 위치 초기값
    _RobotPosQ.push(_RobotPos); // 로봇의 시작를 큐에 넣기
    _MapArr[0][0][0] = true; // 방문 마킹
    _MapArr[0][1][0] = true;
    // board 는 0,0 에서 시작
    // 마킹은 1,1에서 시작


    // bfs 탐색 시작
    while (_RobotPosQ.size() > 0) {
        _RobotPos = _RobotPosQ.front();
        _RobotPosQ.pop();
        pair<int, int> _CntPosOne = make_pair(get<0>(_RobotPos), get<1>(_RobotPos)); // 로봇의 현재 x, y 위치 1
        pair<int, int> _CntPosTwo = make_pair(get<2>(_RobotPos), get<3>(_RobotPos)); // 로봇의 현재 x, y 위치 2
        int _cnttime = get<4>(_RobotPos);
        if (_CntPosOne == _goal || _CntPosTwo == _goal) {
            answer = _cnttime;
            break;
        }
        bool _robotstatus; // true 세로, false 가로
        // 상 하 좌 우를 탐색
        for (int i = 0; i < 4; i++) {

            pair<int, int> _TempPosOne, _TempPosTwo;
            _TempPosOne.first = _CntPosOne.first + dxdy[i][0];
            _TempPosOne.second = _CntPosOne.second + dxdy[i][1];
            _TempPosTwo.first = _CntPosTwo.first + dxdy[i][0];
            _TempPosTwo.second = _CntPosTwo.second + dxdy[i][1];

            // 가로 세로 비교
            if (_CntPosOne.first + 1 == _CntPosTwo.first || _CntPosOne.first - 1 == _CntPosTwo.first) _robotstatus = true; // 세로
            else _robotstatus = false;

            // 벽이라면 넘어간다.
            if (_TempPosOne.first < 0 || _TempPosOne.first >= _MapMax || _TempPosOne.second < 0 || _TempPosOne.second >= _MapMax) continue;
            if (_TempPosTwo.first < 0 || _TempPosTwo.first >= _MapMax || _TempPosTwo.second < 0 || _TempPosTwo.second >= _MapMax) continue;
            if (board[_TempPosOne.first][_TempPosOne.second] == 1 || board[_TempPosTwo.first][_TempPosTwo.second] == 1) continue;

            // 두 부분이 방문한 적이 있다면 넘어간다.
            if (_MapArr[_TempPosOne.first][_TempPosOne.second][_robotstatus] == true && _MapArr[_TempPosTwo.first][_TempPosTwo.second][_robotstatus] == true) continue;

            _RobotPos = make_tuple(_TempPosOne.first, _TempPosOne.second, _TempPosTwo.first, _TempPosTwo.second, _cnttime + 1);
            _RobotPosQ.push(_RobotPos); // 로봇의 시작를 큐에 넣기
            _MapArr[_TempPosOne.first][_TempPosOne.second][_robotstatus] = true; // 방문 마킹
            _MapArr[_TempPosTwo.first][_TempPosTwo.second][_robotstatus] = true;

        }

        // 방향 전환
        if (!_robotstatus) { // 가로
            if (_CntPosOne.first + 1 < _MapMax && board[_CntPosOne.first + 1][_CntPosOne.second] != 1 && board[_CntPosTwo.first + 1][_CntPosTwo.second] != 1) {
                if (_MapArr[_CntPosTwo.first + 1][_CntPosTwo.second][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosTwo.first + 1, _CntPosTwo.second, _CntPosTwo.first, _CntPosTwo.second, _cnttime + 1);
                    _MapArr[_CntPosTwo.first + 1][_CntPosTwo.second][!_robotstatus] = true;
                    _MapArr[_CntPosTwo.first][_CntPosTwo.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }
            if (_CntPosOne.first - 1 >= 0 && board[_CntPosOne.first - 1][_CntPosOne.second] != 1 && board[_CntPosTwo.first - 1][_CntPosTwo.second] != 1) {
                if (_MapArr[_CntPosTwo.first - 1][_CntPosTwo.second][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosTwo.first - 1, _CntPosTwo.second, _CntPosTwo.first, _CntPosTwo.second, _cnttime + 1);
                    _MapArr[_CntPosTwo.first - 1][_CntPosTwo.second][!_robotstatus] = true;
                    _MapArr[_CntPosTwo.first][_CntPosTwo.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }
            if (_CntPosTwo.first + 1 < _MapMax && board[_CntPosTwo.first + 1][_CntPosTwo.second] != 1 && board[_CntPosOne.first + 1][_CntPosOne.second] != 1) {
                if (_MapArr[_CntPosOne.first + 1][_CntPosOne.second][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosOne.first + 1, _CntPosOne.second, _CntPosOne.first, _CntPosOne.second, _cnttime + 1);
                    _MapArr[_CntPosOne.first + 1][_CntPosOne.second][!_robotstatus] = true;
                    _MapArr[_CntPosOne.first][_CntPosOne.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }
            if (_CntPosTwo.first - 1 >= 0 && board[_CntPosTwo.first - 1][_CntPosTwo.second] != 1 && board[_CntPosOne.first - 1][_CntPosOne.second] != 1) {
                if (_MapArr[_CntPosOne.first - 1][_CntPosOne.second][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosOne.first - 1, _CntPosOne.second, _CntPosOne.first, _CntPosOne.second, _cnttime + 1);
                    _MapArr[_CntPosOne.first - 1][_CntPosOne.second][!_robotstatus] = true;
                    _MapArr[_CntPosOne.first][_CntPosOne.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }
        }
        else {
            if (_CntPosOne.second + 1 < _MapMax && board[_CntPosOne.first][_CntPosOne.second + 1] != 1 && board[_CntPosTwo.first][_CntPosTwo.second + 1] != 1) {
                if (_MapArr[_CntPosTwo.first][_CntPosTwo.second + 1][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosTwo.first, _CntPosTwo.second + 1, _CntPosTwo.first, _CntPosTwo.second, _cnttime + 1);
                    _MapArr[_CntPosTwo.first][_CntPosTwo.second + 1][!_robotstatus] = true;
                    _MapArr[_CntPosTwo.first][_CntPosTwo.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }
            if (_CntPosOne.second - 1 >= 0 && board[_CntPosOne.first][_CntPosOne.second - 1] != 1 && board[_CntPosTwo.first][_CntPosTwo.second - 1] != 1) {
                if (_MapArr[_CntPosTwo.first][_CntPosTwo.second - 1][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosTwo.first, _CntPosTwo.second - 1, _CntPosTwo.first, _CntPosTwo.second, _cnttime + 1);
                    _MapArr[_CntPosTwo.first][_CntPosTwo.second - 1][!_robotstatus] = true;
                    _MapArr[_CntPosTwo.first][_CntPosTwo.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }
            if (_CntPosTwo.second + 1 < _MapMax && board[_CntPosTwo.first][_CntPosTwo.second + 1] != 1 && board[_CntPosOne.first][_CntPosOne.second + 1] != 1) {
                if (_MapArr[_CntPosOne.first][_CntPosOne.second + 1][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosOne.first, _CntPosOne.second + 1, _CntPosOne.first, _CntPosOne.second, _cnttime + 1);
                    _MapArr[_CntPosOne.first][_CntPosOne.second + 1][!_robotstatus] = true;
                    _MapArr[_CntPosOne.first][_CntPosOne.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }
            if (_CntPosTwo.second - 1 >= 0 && board[_CntPosTwo.first][_CntPosTwo.second - 1] != 1 && board[_CntPosOne.first][_CntPosOne.second - 1] != 1) {
                if (_MapArr[_CntPosOne.first][_CntPosOne.second - 1][!_robotstatus] == false) {
                    _RobotPos = make_tuple(_CntPosOne.first, _CntPosOne.second - 1, _CntPosOne.first, _CntPosOne.second, _cnttime + 1);
                    _MapArr[_CntPosOne.first][_CntPosOne.second - 1][!_robotstatus] = true;
                    _MapArr[_CntPosOne.first][_CntPosOne.second][!_robotstatus] = true;
                    _RobotPosQ.push(_RobotPos);
                }
            }

        }

    }

    return answer;
}