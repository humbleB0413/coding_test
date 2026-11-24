/**
 * 거스름돈이 N원일 때, 500원, 100원, 50원, 10원을 거슬러 줘야 한다.
 * N은 항상 10의 배수이다.
 * 동전 개수를 최소로 하여 거슬려 주려고 한다.
 */

#include <iostream>
#include <algorithm>

using namespace std;

 int main(int argc, char* argv[]){

   int N = stoi(argv[1]);
   
   int answer = 0;
   
   answer += N / 500;
   answer += (N % 500) / 100;
   answer += ((N % 500) % 100) / 50;
   answer += (((N % 500) % 100) % 50) / 10;

   std::cout << answer << std::endl;

   return answer;
 }