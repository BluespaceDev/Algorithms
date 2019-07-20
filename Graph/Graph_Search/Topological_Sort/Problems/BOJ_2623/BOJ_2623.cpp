// 위상 정렬
// 여러 개 서브 그래프들의 순서를 만족되게 정렬
// back edge로 사이클을 예외처리하고, dfs로 위상정렬 구현
// 실수1. back edge구할때 방문 순서뿐만 아니라 방문 중(back edge)인지 방문 끝(정렬 된걸 방문한 상태)인지 체크해야 한다.

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N   1000
#define MAX_M   100

int N, M;
vector<int> adj[MAX_N+1];
vector<int> topologicalSort;
int dfs_num[MAX_N+1];
bool finished[MAX_N+1];
int dfs_time;

bool dfs(int u){
    dfs_num[u] = ++dfs_time;
    for(int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        if(dfs_num[v] == 0){
            if(!dfs(v)) return false;
        } else if(!finished[v] && dfs_num[u] >= dfs_num[v]){ // back edge => cycle
            return false;
        }
    }
    
    topologicalSort.push_back(u);
    finished[u] = true;
    return true;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int k;
        scanf("%d", &k);
        
        int u;
        scanf("%d", &u);
        
        for(int j = 1; j < k; ++j){
            int v;
            scanf("%d", &v);
            adj[u].push_back(v);
            u = v;
        }
    }
    
    for(int i = 1; i <= N; ++i){
        if(dfs_num[i] == 0){
            if(!dfs(i)){
                printf("0");
                return 0;
            }
        }
    }
    
    reverse(topologicalSort.begin(), topologicalSort.end());
    for(int i : topologicalSort){
        printf("%d\n", i);
    }
    return 0;
}