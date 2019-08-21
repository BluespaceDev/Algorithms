// 4-clustring max-sapcing

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

char inputFile[] = "input1.txt";

const int k = 4;

vector<tuple<int,int,int>> edges;

vector<int> clusters;

int _find(int u) {
    return clusters[u] == u ? u : (clusters[u] = _find(clusters[u]));
}
bool _union(int u, int v){
    u = _find(u);
    v = _find(v);
    if (u != v) {
        clusters[v] = u;
        return true;
    }
    return false;
}

int main(){
    FILE* pfile = fopen(inputFile, "r");
    int number_of_nodes;
    fscanf(pfile, "%d\n", &number_of_nodes);
    while(!feof(pfile)) {
        int u, v, cost;
        fscanf(pfile, "%d %d %d\n", &u, &v, &cost);
        edges.push_back(make_tuple(cost, u, v));
    }
    fclose(pfile);
    
    sort(edges.begin(), edges.end());
    
    clusters = vector<int>(number_of_nodes+1);
    for(int i = 1; i <= number_of_nodes; ++i)
        clusters[i] = i;
    
    for(auto edge : edges){
        if(_union(get<1>(edge), get<2>(edge))){
            --number_of_nodes;
            if(number_of_nodes == k-1) {
                printf("%d\n", get<0>(edge));
                break;
            }
        }
    }
    
    return 0;
}
