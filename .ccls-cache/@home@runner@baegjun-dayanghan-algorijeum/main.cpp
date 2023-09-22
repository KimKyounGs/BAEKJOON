/*
아이디어 : 

시간 초과로 골치 아팠던 문제이다.

다 왔는데 마지막에 index(매개변수)를 생각못했다. 
index를 고려해야지 경우의 수의 중복이 안 일어난다.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
int result = 1e9;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> v;
bool visited[51];

void DFS(int cnt, int index) {
    if (cnt == M) {
        int sum = 0;
        int len = house.size();
        for (int i = 0; i < len; i ++) {
            int mins = 1e9;
            for (int j = 0; j < M; j ++) {
                mins = min(mins, abs(house[i].first - v[j].first) + abs(house[i].second - v[j].second));
            }
            sum += mins;
        }
        result = min(result, sum);
        return ;
    }

    else {
        for (int i = index; i < chicken.size(); i ++) {
            if (visited[i] == false) {
                visited[i] = true;
                v.push_back({chicken[i].first, chicken[i].second});
                DFS(cnt + 1, i);
                visited[i] = false;
                v.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            int n;
            cin >> n;
            if (n == 1) {
                house.push_back({i,j});
            }
            if (n == 2) {
                chicken.push_back({i,j});
            }
        }
    }

    DFS(0, 0);

    cout << result << '\n';
    
}    
