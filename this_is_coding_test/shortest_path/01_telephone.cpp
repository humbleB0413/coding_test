#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;
int N, M, C;
vector<vector<pair<int, int>>> map;
vector<int> shortest;

int main(int argc, char* argv[]){

    N = stoi(argv[1]);
    M = stoi(argv[2]);
    C = stoi(argv[3]);

    map = vector<vector<pair<int, int>>>(N);
    shortest = vector<int>(N, INT_MAX);

    for(int i = 0; i < M; i++){
        int x = stoi(argv[4+3*i]) - 1;
        int y = stoi(argv[5+3*i]) - 1;
        int z = stoi(argv[6+3*i]);
        map[x].push_back({y, z});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    shortest[C-1] = 0;
    pq.push({0, C-1});

    while(!pq.empty()){
        pair<int, int> next = pq.top();
        pq.pop();

        int dist = next.first;
        int now = next.second;
        if(shortest[now] < dist) continue;

        for(auto edge : map[now]){
            int cost = dist + edge.second;
            if(cost < shortest[edge.first]){
                shortest[edge.first] = cost;
                pq.push({cost, edge.first});
            }
        }
    }

    int count = 0;
    int max_dist = 0;
    for(int i = 0; i < N; i++){
        if(i == C-1 || shortest[i] == INT_MAX) continue;
        count++;
        max_dist = max(max_dist, shortest[i]);
    }

    cout << count << " " << max_dist << endl;

    return 0;
}
