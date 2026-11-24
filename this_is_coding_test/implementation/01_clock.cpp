#include <iostream>
#include <algorithm>

using namespace std;

//h : 3, 13, 23
//m : 3 13 23 30 ~ 39 43 53
//s : 3 13 23 30 ~ 39 43 53

int main(int argc, char* argv[]){

    int N = stoi(argv[1]);
    int answer = 0;

    if(N < 3){
        answer = (N+1) * (3600 - 45 * 45);
    }
    else if(N < 13){
        answer = (N+1 -1) * (3600 - 45 * 45) + 3600;
    }
    else if(N < 23){
        answer = (N+1 -2) * (3600 - 45 * 45) + 2 * 3600;
    }
    else{
        answer = (N+1 -3) * (3600 - 45 * 45) + 3 * 3600;
    }

    cout << answer << std::endl;

    return 0;
}