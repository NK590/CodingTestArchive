#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    map<string, int> m =
    {
    {"####.##.##.####",0},
    {"###..#####..###", 2},
    {"###..####..####", 3},
    {"#.##.####..#..#", 4},
    {"####..###..####", 5},
    {"####..####.####", 6},
    {"###..#..#..#..#", 7},
    {"####.#####.####", 8},
    {"####.####..####", 9} };


    int n;
    cin >> n;
    string sig;
    cin >> sig;


    vector<string> num_sig;

    int N = n / 5;

    for (int i = 0; i < n; i += N) 
    {
        num_sig.push_back(sig.substr(i, N));
    }

    for (int i = 0; i < N; i++) 
    {   
        cout << " i : " << i << endl;
        if (num_sig[0][i] == '#') 
        {
            if ((i == N - 1 || (num_sig[0][i + 1] == '.' && num_sig[3][i] == '#')))
            {
                cout << 1 << ""; 
                continue;
            }

            string num = "";
            for (int j = 0; j < 5; j++)
            {
                num += num_sig[j].substr(i, 3);
            }

            if (m.find(num) != m.end()) 
            { 
                cout << m[num] << "";
                i += 3;
            }
        }        
    }
    return 0;
}