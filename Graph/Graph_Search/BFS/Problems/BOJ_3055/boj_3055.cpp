// BFS
// https://www.acmicpc.net/problem/3055
// map 배열 크기 +1 안해서 1번 틀렸음

#include <cstdio>
#include <tuple>
#include <queue>

using namespace std;

#define MAX_SIZE 50

int R, C;
char map[MAX_SIZE+1][MAX_SIZE+1];

tuple<int,int> D, S;    // <y, x>

queue<tuple<int,int>> bfs_s, bfs_w;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool check_boundary(int y, int x){
    if (y < 0 || y >= R || x < 0 || x >= C)   return false;
    if (map[y][x] == 'X')   return false;
    if (map[y][x] == '*')   return false;
    if (map[y][x] == 'D')   return false;
    return true;
}

void bfs_w_turn(){
    int layer_size = bfs_w.size();
    while(layer_size--){
        auto [y, x] = bfs_w.front();    bfs_w.pop();
        for(int i = 0; i < 4; ++i){
            int dy = y+dir[i][0];
            int dx = x+dir[i][1];
            if (!check_boundary(dy, dx)) continue;
            map[dy][dx] = '*';
            bfs_w.push(make_tuple(dy, dx));
        }
    }
}
bool bfs_s_turn(){
    int layer_size = bfs_s.size();
    while(layer_size--){
        auto [y, x] = bfs_s.front();    bfs_s.pop();
        
        for(int i = 0; i < 4; ++i){
            int dy = y+dir[i][0];
            int dx = x+dir[i][1];
            if (get<0>(D) == dy && get<1>(D) == dx) return true;
            if (!check_boundary(dy, dx)) continue;
            if (map[dy][dx] == 'o') continue;
            map[dy][dx] = 'o';
            bfs_s.push(make_tuple(dy, dx));
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i) {
        scanf("%s", map[i]);
    }
    
    for(int y = 0; y < R; ++y){
        for(int x = 0; x < C; ++x){
            if (map[y][x] == 'D') {
                D = make_tuple(y, x);
            } else if (map[y][x] == 'S'){
                S = make_tuple(y, x);
                bfs_s.push(make_tuple(y,x));
            } else if (map[y][x] == '*'){
                bfs_w.push(make_tuple(y,x));
            }
        }
    }
    
    int turn = 0;
    while(!bfs_s.empty()){
        turn++;
        bfs_w_turn();
        if(bfs_s_turn()) {
            printf("%d\n", turn);
            return 0;
        }
    }
    
    printf("KAKTUS\n");
    return 0;
}
