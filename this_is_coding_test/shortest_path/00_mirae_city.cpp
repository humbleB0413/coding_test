#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M, X, K;
vector<vector<int>> shortest;

int main(int argc, char* argv[]) {
    N = stoi(argv[1]);
    M = stoi(argv[2]);
    X = stoi(argv[3+2*M]);
    K = stoi(argv[4+2*M]);

    shortest = vector<vector<int>>(N, vector<int>(N, INF));

    for(int i = 0; i < M; i++){
        int a = stoi(argv[3+2*i]) - 1;
        int b = stoi(argv[4+2*i]) - 1;
        shortest[a][b] = 1;
        shortest[b][a] = 1;
    }

    for(int i = 0; i < N; i++){
      shortest[i][i] = 0;
    }

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        for(int k = 0; k < N; k++){
          if(shortest[j][i] == INF || shortest[i][k] == INF) continue;
          shortest[j][k] = min(shortest[j][k], shortest[j][i] + shortest[i][k]);
        }
      }
    }

    int toK = shortest[0][K-1];
    int toX = shortest[K-1][X-1];
    int answer = (toK == INF || toX == INF) ? -1 : toK + toX;

    cout << answer << std::endl;

  return 0;
}