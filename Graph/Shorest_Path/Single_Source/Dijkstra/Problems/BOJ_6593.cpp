// 다익스트라, BFS
// 가중치가 1이기 때문에 BFS로도 가능
// 그래프 만들어서 최단 거리 찾으면 끝

#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_L   30
#define MAX_V   (MAX_L*MAX_L*MAX_L)
#define INF     99999999

int L,R,C;
int S, E;   // <y,x>
char map[MAX_L][MAX_L][MAX_L];
tuple<int,int,int> dir[6] = {
    {0,-1,0}, {0,0,1}, {0,1,0}, {0,0,-1}, {1,0,0}, {-1,0,0}
};

int vertax_size;
vector<int> adj[MAX_V];
int dist[MAX_V];

bool check_edge(int z, int y, int x){
    if(z < 0 || z >= MAX_L || y < 0 || y >= MAX_L || x < 0 || x >= MAX_L)   return false;
    if(map[z][y][x] == '#') return false;
    return true;
}

void make_graph(){
    vertax_size = L*R*C;
    for(int i = 0; i < vertax_size; ++i)
        adj[i].clear();
    
    for(int z = 0; z < L; ++z){
        for(int y = 0; y < R; ++y){
            for(int x = 0; x < C; ++x){
                if(map[z][y][x] == '#') continue;
                
                if(map[z][y][x] == 'S'){
                    S = z*R*C + y*C + x;
                } else if(map[z][y][x] == 'E'){
                    E = z*R*C + y*C + x;
                }
                
                for(int i = 0; i < 6; ++i){
                    auto [dz, dy, dx] = dir[i];
                    dz+=z; dy+=y; dx+=x;
                    if(check_edge(dz,dy,dx)){
                        int u = z*R*C + y*C + x;
                        int v = dz*R*C + dy*C + dx;
                        adj[u].push_back(v);
                    }
                }
            }
        }
    }
}

bool dijkstra_BFS(){
    fill(dist, dist+vertax_size, INF);
    
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    while(!q.empty()){
        auto u = q.front();  q.pop();
        if(u == E){
            return true;
        }
        for(int v : adj[u]){
            if(dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return false;
}

int main(){
    while(1){
        scanf("%d %d %d", &L,&R,&C);
        if(L == 0 && R == 0 && C == 0)  break;

        for(int i = 0; i < L; ++i){
            for(int j = 0; j < R; ++j){
                scanf("%s", map[i][j]);
            }
        }
        
        make_graph();
        if(dijkstra_BFS())
            printf("Escaped in %d minute(s).\n", dist[E]);
        else
            printf("Trapped!\n");
    }
    return 0;
}