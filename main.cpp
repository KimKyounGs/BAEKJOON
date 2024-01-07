/*
아이디어 :

"특정숫자까지 합으로 구할 수 있으면 특정숫자보다 낮은 숫자도 합으로 구할 수 있음"
ex) 3 4 5 6 
-> 3 + 4 + 5 + 6 = 18 >> 18까지는 3,4,5,6 조합으로 구할 수 있음. 하지만 19는 안됨.

시간복잡도 : O(NlogN)
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

int N;
int result = 0;
int sum = 0;
vector<int> v;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    // 가장 작은 수가 1보다 크면 종료.
    if (v[0] > 1) {
        cout << 1 << endl;
        return 0;
    } 

    bool check;
    for (int i = 0; i < N; i ++) {
            sum += v[i];
            if (sum + 1 < v[i+1]) {
                    cout << sum + 1 << '\n';
                    return 0;
            }
            if (i == N - 1) check = true;
    }

    // 전부 돌았을 때까지도 종료 안됐을 경우
    if (check) {
        cout << sum + 1 << '\n';
    }
    
    return 0;
}