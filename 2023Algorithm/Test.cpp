#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, a, b;
vector<vector<int>> arr;
int visited[1001];
queue<int> q;

void DFS(int v) {
    visited[v] = 1;
    cout << v << " "; 

    for (int i = 0; i < arr[v].size(); ++i) {
        int neighbor = arr[v][i];
        if (visited[neighbor] == 0) {
            DFS(neighbor);
        }
    }
}

void BFS(int v) {
    visited[v] = 1;
    q.push(v);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        cout << now << " "; // 방문한 정점 출력

        for (int i = 0; i < arr[now].size(); ++i) {
            int neighbor = arr[now][i];
            if (visited[neighbor] == 0) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    arr.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a); // 무방향 그래프라면 양쪽으로 간선 추가
    }

    fill_n(visited, 1001, 0);

    cout << k << " ";
    DFS(k);

    cout << endl;

    fill_n(visited, 1001, 0);

    cout << k << " ";
    BFS(k);

    return 0;
}
