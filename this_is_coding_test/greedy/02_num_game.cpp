#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b){
    return a < b;
}

int main(int argc, char* argv[]){
    
    int N = stoi(argv[1]);
    int M = stoi(argv[2]);
    
    std::vector<int> matrix(N*M, 0);

    for(int i = 0; i < N*M; i++){
        matrix[i] = stoi(argv[3+i]);
    }

    int answer = 0;

    for(int i = 0; i < N; i++){
        auto begin = matrix.begin() + i*M;
        auto end = begin + M;
        std::sort(begin, end, compare);

        if(answer < *begin){
            answer = *begin;
        }
    }

    cout << answer << std::endl;

    return answer;
}