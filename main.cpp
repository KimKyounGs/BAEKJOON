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
#include <climits>
#define INF 1e9
#define endl '\n'

using namespace std;

int N, K;
deque<pair<int, bool>> graph;
int cnt = 0;
int result = 0;

void BeltRotate() {
    pair<int, bool> n = graph.back();
    graph.pop_back();
    graph.push_front(n);

    if (graph[N-1].second == true) {
        graph[N-1].second = false;
    }
}


void RobotMove() {
    for (int i = N-2; i >= 0; i --) {
        if (graph[i].second == true) {
            if (graph[i+1].second == false && graph[i+1].first >= 1) {
                graph[i].second = false;
                graph[i+1].second = true;
                graph[i+1].first--;
            }
        } 
    }

    if (graph[N-1].second == true) {
        graph[N-1].second = false;
    }
}

void RobotUp() {
    if (graph[0].first >= 1 && graph[0].second == false) {
        graph[0].first--;
        graph[0].second = true;
    }
}

void BeltCheck() {
    for (int i = 0; i < 2*N; i ++) {
        if (graph[i].first <= 0) {
            cnt ++;
        }
    }
}

int main(){
    cin >> N >> K;
    for (int i = 0; i < 2*N; i ++) {
        int n;
        cin >> n;
        graph.push_back({n,false});
    }
    
    while(1) {
        result ++;
        cnt = 0;
        // 1. 벨트 회전
        BeltRotate();

        // 2. 로봇 움직이기
        RobotMove();

        // 3. 올리는 위치에 로봇 올리기
        RobotUp();

        // 4. 내구도 조사
        BeltCheck();

        if (cnt >= K) break;
    }

    cout << result << endl;
    
}

