#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MIN = -2000000000;

struct material_state {
    int quality;
    char color;
};

int n, res = MIN;
int visited[10];

material_state material[10][4][4][4];
vector<vector<material_state> > map(5, vector<material_state>(5));

// 재료를 다 넣은 후 폭탄의 품질 계산 함수
int cal(vector<vector<material_state>> tmap) {
    int r = 0, b = 0, g = 0, y = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char t = tmap[i][j].color;

            if (t == 'R') {
                r += tmap[i][j].quality;
            }
            else if (t == 'B') {
                b += tmap[i][j].quality;
            }
            else if (t == 'G') {
                g += tmap[i][j].quality;
            }
            else if (t == 'Y') {
                y += tmap[i][j].quality;
            }
        }
    }

    return 7 * r + 5 * b + 3 * g + 2 * y;
}

// 재료 넣기 함수
vector<vector<material_state>> take_material(vector<vector<material_state>> tmap, int seq, int pos, int dir) {
    int px, py;

    switch (pos) {
    case 0:
        px = 0; py = 0;
        break;
    case 1:
        px = 1; py = 0;
        break;
    case 2:
        px = 0; py = 1;
        break;
    case 3:
        px = 1; py = 1;
        break;
    default:
        break;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int y = i + py, x = j + px;
            tmap[y][x].quality += material[seq][dir][i][j].quality;

            if (tmap[y][x].quality > 9) {
                tmap[y][x].quality = 9;
            }
            else if (tmap[y][x].quality < 0) {
                tmap[y][x].quality = 0;
            }

            if (material[seq][dir][i][j].color != 'W') {
                tmap[y][x].color = material[seq][dir][i][j].color;
            }
        }
    }

    return tmap;
}

// 재료 선택 과정을 dfs로 처리
void dfs(int dep, vector<vector<material_state>> v) {
    if (dep == 3) {
        res = max(cal(v), res);
        return;
    }

    //순서
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        //위치
        for (int j = 0; j < 4; j++) {
            //방향
            for (int k = 0; k < 4; k++) {
                vector<vector<material_state>> tmp = take_material(v, i, j, k);

                dfs(dep + 1, tmp);
            }
        }

        visited[i] = 0;
    }
}

// 재료 회전 처리
void rotate() {
    for (int z = 0; z < n; z++) {
        for (int r = 1; r < 4; r++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    material[z][r][i][j].quality = material[z][r - 1][3 - j][i].quality;
                    material[z][r][i][j].color = material[z][r - 1][3 - j][i].color;
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                int t;
                cin >> material[i][0][j][k].quality;
            }
        }

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> material[i][0][j][k].color;
            }
        }
    }

    // 가마 초기화
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j].quality = 0;
            map[i][j].color = 'W';
        }
    }

    rotate();

    dfs(0, map);

    cout << res << '\n';

    return 0;
}