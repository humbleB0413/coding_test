#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dp[30001];

int main(int argc, char* argv[]){

    int N = stoi(argv[1]);

    memset(dp, 30001, sizeof(dp));
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 1;

    if(N < 6){
        cout << dp[N] << std::endl;
        return 0;
    }

    for(int i = 6; i <=N; i++){
        dp[i] = min(dp[i], dp[i-1] + 1);
        if(i%5 == 0){
            dp[i] = min(dp[i], dp[i/5] + 1);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        if(i%2 == 0){
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }

    cout << dp[N] << std::endl;

    return 0;
}