#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int N;
constexpr int MAX_N = 101;
constexpr int SINK = -1;

int grid[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };
int min_level;
int max_level;

inline void init()
{
    memset(grid, 0, sizeof(grid));

    min_level = 100;
    max_level = 1;

    cin >> N;

    for (register int x = 0; x < N; x++)
    {
        for (register int y = 0; y < N; y++)
        {
            cin >> grid[x][y];
            min_level = min(min_level, grid[x][y]);
            max_level = max(max_level, grid[x][y]);
        }
    }
}

inline void mark_sink(int level)
{
    for (register int x = 0; x < N; x++)
    {
        for (register int y = 0; y < N; y++)
        {
            if (grid[x][y] != level) continue;
            grid[x][y] = SINK;
        }
    }
}

inline bool is_outbound(int x, int y)
{
    if (!(0 <= x && x < N)) return true;
    if (!(0 <= y && y < N)) return true;

    return false;
}

inline void bfs(int start_x, int start_y)
{
    queue<pair<int, int>> q;

    q.push({ start_x, start_y });
    cache[start_x][start_y] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (register int i = 0; i < 4; i++)
        {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];

            if (is_outbound(nx, ny)) continue;
            if (grid[nx][ny] == SINK) continue;
            if (cache[nx][ny]) continue;

            cache[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

inline int get_areas()
{
    int result = 0;
    memset(cache, false, sizeof(cache));

    for (register int x = 0; x < N; x++)
    {
        for (register int y = 0; y < N; y++)
        {
            if (grid[x][y] == SINK) continue;
            if (cache[x][y]) continue;

            ++result;
            bfs(x, y);
        }
    }

    return result;
}

inline int solve()
{
    int result = 1;
    for (register int level = min_level; level <= max_level; level++)
    {
        mark_sink(level);
        result = max(result, get_areas());
    }

    return result;
}

inline void output(int tc_num, int result)
{
    cout << '#' << tc_num << ' ' << result << '\n';
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        init();
        int result = solve();
        output(test_case, result);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}