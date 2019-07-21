// SCC
// SCC를 찾고 DAG에서 S->T 까지 최대 많은 node의 수

/*
 // scc[] 번호를 알고 있을 때 scc dag 그래프 만드는 방법
 // group 이 다르면 scc가 다르기 때문에 그때 edge를 연결함
 for (int here = 1;here <= N;here++) {
     for (int next : adj[here]) {
         if (scc[here] != scc[next]) {
            adj_scc[scc[here]].push_back(scc[next]);        //scc -> other scc
         }
     }
 }
*/

#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N   10000

int N, M, S, T;

vector<int> adj[MAX_N+1];
vector<int> adj_rev[MAX_N+1];
bool visited[MAX_N+1];
stack<int> dfs_f_stack;
int scc_group[MAX_N+1];
int scc_group_size[MAX_N+1];
vector<int> scc_dag[MAX_N+1];
int dist[MAX_N+1];  // s부터 n까지 최대 노드 거리
int max_city;

void dfs1(int u){
    visited[u] = true;
    for(int i = 0; i < adj_rev[u].size(); ++i){
        int v = adj_rev[u][i];
        if(!visited[v]) {
            dfs1(v);
        }
    }
    
    dfs_f_stack.push(u);
}

void dfs2(int u, int group){
    scc_group[u] = group;
    scc_group_size[group]++;
    for(int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        if(!scc_group[v]){
            dfs2(v, group);
        }
    }
}

void make_dag(){
    for(int u = 1; u <= N; ++u){
        int leader_u = scc_group[u];
        for(int v : adj[u]){
            int leader_v = scc_group[v];
            scc_dag[leader_u].push_back(leader_v);
        }
    }
}

void dfs_path(int leader_u, int city_size){
    if(leader_u == scc_group[T]){
        max_city = max(max_city, city_size);
        return;
    }

    // 가지치기 - 정점에 도달했을 때 거리가 작은거면 어차피 탐색할 필요 없음
    if(dist[leader_u] < city_size){
        dist[leader_u] = city_size;
    }else{
        return;
    }

    visited[leader_u] = true;
    for(int leader_v : scc_dag[leader_u]){
        if(!visited[leader_v]){
            dfs_path(leader_v, city_size+scc_group_size[leader_v]);
        }
    }
    visited[leader_u] = false;
}

int main(){
    scanf("%d %d %d %d", &N, &M, &S, &T);
    for(int i = 0; i < M; ++i){
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    
    for(int u = 1; u <= N; ++u)
        if(!visited[u])
            dfs1(u);
    
    while(!dfs_f_stack.empty()){
        int u = dfs_f_stack.top();  dfs_f_stack.pop();
        if(!scc_group[u])
            dfs2(u, u);
    }
    
    make_dag();
    
    memset(visited, false, sizeof(visited));
    dfs_path(scc_group[S], scc_group_size[scc_group[S]]);
    
    printf("%d", max_city);
    
    return 0;
}
