// Greedy

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

char inputFile[] = "input.txt";

vector<tuple<int,int>> adj[501];
bool visited[501];

int main(){
    FILE* pfile = fopen(inputFile, "r");
    int node_size, edge_size;
    fscanf(pfile, "%d %d\n", &node_size, &edge_size);
    while(edge_size--) {
        int cost, u, v;
        fscanf(pfile, "%d %d %d\n", &u, &v, &cost);
        adj[u].push_back(make_tuple(cost, v));
        adj[v].push_back(make_tuple(cost, u));
    }
    fclose(pfile);
    
    int total_cost = 0;
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> q;
    q.push(make_tuple(0, 1));
    while(!q.empty()){
        auto a = q.top(); q.pop();
        int weight = get<0>(a);
        int u = get<1>(a);
        if (visited[u]) continue;

        total_cost += weight;
        visited[u] = true;
        
        for(auto b : adj[u]){
            int cost = get<0>(b);
            int v = get<1>(b);
            if (!visited[v]){
                q.push(make_tuple(cost, v));
            }
        }
    }
    
    printf("%d\n", total_cost);
    
    return 0;
}
