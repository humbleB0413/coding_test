#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int x;
    int y;
} pos_t;


pos_t dir[4] = {
    {-1, 0}, // L
    {1, 0}, // R
    {0, -1}, // U
    {0, 1} // D
};

int main(int argc, char* argv[]){

    int N = stoi(argv[1]);
    int size = stoi(argv[2]);

    pos_t here = {1, 1};
    for(int i = 0; i < size; i++){
        pos_t to = here;
        
        switch(argv[3+i][0]){
            case 'L':
                to.x = to.x + dir[0].x;
                to.y = to.y + dir[0].y;
                cout << 'L';
                break;
            case 'R':
                to.x = to.x + dir[1].x;
                to.y = to.y + dir[1].y;
                cout << 'R';
                break;
            case 'U':
                to.x = to.x + dir[2].x;
                to.y = to.y + dir[2].y;
                cout << 'U';
                break;
            case 'D':
                to.x = to.x + dir[3].x;
                to.y = to.y + dir[3].y;
                cout << 'D';
                break;
        }

        if(to.x < 1 || to.y < 1 || to.x > N || to.y > N){
            continue;
        }

        here = to;
    }

    cout << std::endl;
    cout << here.y << ' ' << here.x << std::endl;

    return 0;
}