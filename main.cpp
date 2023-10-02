/*
아이디어 :

2 3 5 7 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<int> v;

bool isPrime2(int n) {
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}

void DFS(int n) {
    queue<int> q;
    for (int i = 2; i <= 9; i ++) {
        if (isPrime2(i)) {
            q.push(i);
        }
    }

    for (int i = 1; i < n; i ++) {
        int len = q.size();
        //cout << "len : " << len << '\n';
        while(len--) {
            //cout << "i = " << i << '\n';
            int num = q.front() * 10;
            //cout << num << '\n';
            q.pop();
            for (int j = 0; j <= 9; j ++) {
                int nNum = num + j;
                if (isPrime2(nNum)) {
                    q.push(nNum);
                }
            }
        }
    }

    while(!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }

}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    
    DFS(N);

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i ++) {
        cout << v[i] << '\n';
    }
    
}
