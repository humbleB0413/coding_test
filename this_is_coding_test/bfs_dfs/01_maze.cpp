#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> visited;

typedef struct{
    int y;
    int x;
    int count;
} pos_t;

int mov[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int main(int argc, char* argv[]){

    N = stoi(argv[1]);
    M = stoi(argv[2]);

    map = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = argv[3+i][j] - '0';
        }
    }

    queue<pos_t> q;
    q.push({0, 0, 1});
    visited[0][0] = true;

    while(!q.empty()){
        pos_t cp = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            pos_t np = {cp.y + mov[dir][0], cp.x + mov[dir][1], cp.count + 1};
            if(np.y > -1 && np.y < N && np.x > -1 && np.x < M){
                if(map[np.y][np.x] == 1 && visited[np.y][np.x] == 0){
                   q.push(np);
                   visited[np.y][np.x] = np.count; 
                }
            }
        }
    }

    cout << visited[N-1][M-1] << std::endl; 

    return 0;
}