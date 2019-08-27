#include <cstdio>
#include <algorithm>
#include <cmath>

#define INF 999999999

using namespace std;

char inputFile[] = "";

int get_min_path(char graph[]) {
    int number_of_vertices, number_of_edges;
    
    FILE* pfile = fopen(graph, "r");
    fscanf(pfile, "%d %d\n", &number_of_vertices, &number_of_edges);
    
    int adj[number_of_vertices+1][number_of_vertices+1];
    for (int i = 1; i <= number_of_vertices; i++)
        for (int j = 1; j <= number_of_vertices; j++)
            adj[i][j] = INF;

    while(!feof(pfile)) {
        int u, v, w;
        fscanf(pfile, "%d %d %d\n", &u, &v, &w);
        adj[u][v] = w;
    }
    fclose(pfile);
    
    int dist[number_of_vertices+1][number_of_vertices+1];
    memset(dist, 0, sizeof(dist));
    for (int i = 1; i <= number_of_vertices; i++)
        for (int j = 1; j <= number_of_vertices; j++)
            dist[i][j] = adj[i][j];
    
    for(int k = 1; k <= number_of_vertices; ++k) {
        for(int i = 1; i <= number_of_vertices; ++i) {
            for(int j = 1; j <= number_of_vertices; ++j) {
                if(dist[j][k] > dist[j][i] + dist[i][k]){
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    
    // cycle
    for (int i = 1; i <= number_of_vertices; ++i)
        if (dist[i][i] < 0)
            return INF;
    
    int min_path = INF;
    for(int i = 1; i <= number_of_vertices; ++i) {
        for(int j = 1; j <= number_of_vertices; ++j) {
            min_path = min(min_path, dist[i][j]);
        }
    }
    
    return min_path;
}

int main(){
    char buffer[1024];
    for(int i = 1; i <= 3; ++i){
        sprintf(buffer,"%sgraph%d.txt",inputFile,i);
        int min_path = get_min_path(buffer);
        printf("graph%d : %d\n", i, min_path);
    }
    
    return 0;
}
