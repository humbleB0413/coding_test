#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef struct {
    int y;
    int x;
} dir_t;

dir_t mov[4] = {
    {0, -1}, //U
    {0, 1}, //B
    {-1, 0}, //L
    {1, 0} //R
};

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visited;

void bfs(dir_t pos){
    deque<dir_t> dq;
    dq.push_back(pos);
    visited[pos.y][pos.x] = true;

    while(!dq.empty()){
        dir_t cp = dq.front();
        dq.pop_front();

        for(int dir = 0; dir < 4; dir++){
            dir_t np = {cp.y + mov[dir].y, cp.x + mov[dir].x};
            if(np.y > -1 && np.y < N && np.x > -1 && np.x < M){
                if(map[np.y][np.x] == 0 && !visited[np.y][np.x]){
                    dq.push_back(np);
                    visited[np.y][np.x] = true;
                }
            }
        }
    }
}

int main(int argc, char* argv[]){

    int answer = 0;
    N = stoi(argv[1]); // 행
    M = stoi(argv[2]); // 열

    map = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = argv[3+i][j] - '0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0 && !visited[i][j]){
                bfs({i, j});
                answer++;
            }
        }
    }

    cout << answer << std::endl;

    return 0;
}