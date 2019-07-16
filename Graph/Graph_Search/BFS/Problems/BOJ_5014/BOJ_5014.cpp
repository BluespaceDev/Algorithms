// BFS 탐색 문제
// 계단 으로는 방식이기 때문에 목표 층에 다 다른 다음에 down,up 하면 됨 -> for문 반복으로 가능

#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_N   1000000

int f,s,g,up,down;

int main(){
    scanf("%d %d %d %d %d", &f, &s,&g,&up,&down);
    
    queue<tuple<int,int>> q;
    q.push(make_tuple(s, 0));
    for(int i = 0; i < MAX_N; ++i){
        auto [u, d] = q.front(); q.pop();

        if(u == g) {
            printf("%d", d);
            return 0;
        }
        
        if (g-u > 0){
            q.push(make_tuple(u+up, d+1));
        }else{
            q.push(make_tuple(u-down, d+1));
        }
    }
    
    printf("use the stairs");
    return 0;
}
