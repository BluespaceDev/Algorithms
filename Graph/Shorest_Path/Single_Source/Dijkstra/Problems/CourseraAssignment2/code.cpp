// 과제2 다익스트라

#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_V   200
#define INF     (1000000+1)

char inputFile[] = "problem9.8.txt";

vector<tuple<int,int>> adj[MAX_V+1];
int dist[MAX_V+1];
int answer[] = { 7,37,59,82,99,115,133,165,188,197 };

void dijkstra(int s){
    std::fill(dist, dist+MAX_V+1, INF);
    
    priority_queue<tuple<int,int>> pq;
    pq.push(make_tuple(0, s));
    dist[s] = 0;
    while(!pq.empty()){
        auto [cost, u] = pq.top(); pq.pop();
        if(dist[u] < -cost) continue;
        for(auto [w, v] : adj[u]){
            int new_dist = -cost + w;
            if(dist[v] > new_dist){
                dist[v] = new_dist;
                pq.push(make_tuple(-new_dist, v));
            }
        }
    }
}

int main(){
    FILE* pfile = fopen(inputFile, "r");
    while(!feof(pfile)){
        int u,v,w;
        int c = fscanf(pfile, "%d,%d", &v, &w);
        if (c == 1) {
            u = v;
        } else if (c == 2) {
            adj[u].push_back(make_tuple(w,v));
        }
    }
    fclose(pfile);
    
    dijkstra(1);
    
    for(int u : answer){
        printf("%d: %d\n", u, dist[u]);
    }
    
    return 0;
}
