#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const int& a, const int& b) { return a > b; };

int main(int argc, char* argv[]) {
  int N = stoi(argv[1]);
  int M = stoi(argv[2]);
  int K = stoi(argv[3]);

  vector<int> nums(N, 0);
  for (int i = 0; i < N; i++) {
    nums[i] = stoi(argv[4+i]);
  }

  std::sort(nums.begin(), nums.end(), compare);

  int answer = 0;
  int serial = 0;
  for (int i = 0; i < M; i++) {
    if (serial == K) {
      answer += nums[1];
      serial = 0;
    } else {
      answer += nums[0];
      serial++;
    }
  }

  cout << answer << std::endl;

  return answer;
}