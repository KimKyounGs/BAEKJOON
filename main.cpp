/*
아이디어 :


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#define INF 1e9
#define endl '\n'

using namespace std;

int R,C,T;
int graph[51][51];
int upIdx;
int downIdx;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int upAirdx[] = {0, -1, 0, 1};
int upAirdy[] = {1, 0, -1, 0};
int downAirdx[] = {0, 1, 0, -1};
int downAirdy[] = {1, 0, -1, 0};


void SpreadDust() {
    int temp[51][51] = {0,};
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            if (graph[i][j] != 0) {
                int cnt = 0;
                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1) continue;

                    if (graph[nx][ny] != -1) {
                        temp[nx][ny] += graph[i][j]/5;
                        cnt ++;
                    }
                }
                if (cnt) {
                    temp[i][j] += graph[i][j] - graph[i][j]/5*cnt;
                }
            }
        }
    }
    copy(&temp[0][0], &temp[0][0] + 51*51, &graph[0][0]);

    /*
    cout << endl;
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    */
}

void AirCleaner() {
    // 위쪽
    int temp = 0;
    int x = upIdx;
    int y = 0;
    for (int i = 0; i < 4; i ++) {
        while(1) {
            int nx = x + upAirdx[i];
            int ny = y + upAirdy[i];

            if ((nx == upIdx && ny == C) || (nx == -1 && ny == C-1) || (nx == 0 && ny == -1) || (nx == upIdx && ny == 0)) break;

            int temp2 = temp;
            temp = graph[nx][ny];
            graph[nx][ny] = temp2;

            x = nx;
            y = ny;
        }
    }
    // 아래쪽
    temp = 0;
    x = downIdx;
    y = 0;
    for (int i = 0; i < 4; i ++) {
        while(1) {
            int nx = x + downAirdx[i];
            int ny = y + downAirdy[i];

            if ((nx == downIdx && ny == C) || (nx == R && ny == C-1) || (nx == R-1 && ny == -1) || (nx == downIdx && ny == 0)) break;

            int temp2 = temp;
            temp = graph[nx][ny];
            graph[nx][ny] = temp2;

            x = nx;
            y = ny;
        }
    }
    
    /*
    cout << endl;
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    */
}

int main()
{
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j ++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                if (upIdx == 0) {
                    upIdx = i;
                }
                else {
                    downIdx = i;
                }
            }
        }
    }

    while(T--) {
        SpreadDust();
        AirCleaner();
    }
    
    int result = 0;
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            if (graph[i][j] > 0) result += graph[i][j];
        }
    }

    cout << result << endl;
}