#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, movex[] = {0, 0, 1, -1}, movey[] {1, -1, 0, 0};
    cin>>n>>m;
    int maze[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>maze[i][j];
    cin>>a>>b;
    queue<ppiii> bfs;
    bfs.push(make_pair(make_pair(a - 1, b - 1), 1));
    bool visited[n][m];
    for(int i=0; i<n; i++)
        memset(visited[i], 0, sizeof(bool) * m);
    while(!bfs.empty()) {
        ppiii curr = bfs.front();
        bfs.pop();
        visited[curr.first.first][curr.first.second] = true;
        if(curr.first.first == 0 || curr.first.first == (n - 1)
        || curr.first.second == 0 || curr.first.second == (m - 1)) {
            cout<<curr.second<<'\n';
            exit(0);
        }
        for(int i=0; i<4; i++) {
            int desty = curr.first.first + movey[i];
            int destx = curr.first.second + movex[i];
            if(maze[desty][destx] != -1 && !visited[desty][destx])
                bfs.push(make_pair(make_pair(desty, destx), curr.second + 1));
        }
    }
    return 0;
}