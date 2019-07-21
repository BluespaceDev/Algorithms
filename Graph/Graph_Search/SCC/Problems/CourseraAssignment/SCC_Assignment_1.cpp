// SCC
// SCC size 중에 가장 큰거 5개 찾기

#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_V   875714

char inputFile[] = "SCC_input.txt";

vector<int> adj[MAX_V+1], adj_rev[MAX_V+1];
stack<int> scc_stack;
bool visited[MAX_V+1];
int scc_group[MAX_V+1];
int scc_group_size[MAX_V+1];

void dfs1(int u){
    visited[u] = true;
    for(int v : adj_rev[u])
        if(!visited[v])
            dfs1(v);
    scc_stack.push(u);
}

void dfs2(int u, int group){
    scc_group[u] = group;
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs2(v, group);
        }
    }
}

bool desc(int a, int b){
    return a > b;
}

void scc_size(){
    for(int u = 1; u <= MAX_V; ++u){
        scc_group_size[scc_group[u]]++;
    }
    sort(scc_group_size, scc_group_size+MAX_V, desc);
}

int main(){
    FILE* pfile = fopen(inputFile, "r");
    while(!feof(pfile)){
        int u, v;
        fscanf(pfile, "%d %d", &u, &v);
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    fclose(pfile);
    
    for(int u = 1; u <= MAX_V; ++u)
        if(!visited[u])
            dfs1(u);
    
    memset(visited, false, sizeof(visited));
    
    int group_num = 0;
    while(!scc_stack.empty()){
        int u = scc_stack.top();    scc_stack.pop();
        if(!visited[u])
            dfs2(u, ++group_num);
    }
    
    scc_size();
    
    for(int i = 0; i < 5; ++i)
        printf("%d: %d\n", i, scc_group_size[i]);
    
    return 0;
}
