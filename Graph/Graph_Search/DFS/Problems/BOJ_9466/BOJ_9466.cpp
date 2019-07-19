// DFS
// cycle 체크 문제 ( back edge 찾기 )
// 나가는 간선은 1개이기 때문에 forward edge는 없음
// cross edge는 finished(이미 탐색이 끝남) 으로 처리 가능

#include <cstdio>
#include <cstring>

#define MAX_N   100000

using namespace std;

int n;
int adj[MAX_N+1];
int dfs_low[MAX_N+1];
bool finished[MAX_N+1];
int dfs_time;
int team_member;
int cycle_number;

void dfs(int u){
    dfs_low[u] = ++dfs_time;
   
    int v = adj[u];
    if (dfs_low[v] == 0)    // tree edge
        dfs(v);
    else if (dfs_low[u] >= dfs_low[v] && !finished[v]){  // back,cross edge
        cycle_number = v;
    }
    
    if (cycle_number != 0)  ++team_member;
    
    if(cycle_number == u){
        cycle_number = 0;
    }
    finished[u] = true;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int u = 1; u <= n; ++u){
            int v;
            scanf("%d", &v);
            adj[u] = v;
        }
        
        memset(finished, false, sizeof(finished));
        memset(dfs_low, 0, sizeof(dfs_low));
        dfs_time = team_member = cycle_number = 0;
        
        for(int u = 1; u <= n; ++u)
            if(!finished[u])
                dfs(u);
        
        printf("%d\n", n-team_member);
    }
    return 0;
}
