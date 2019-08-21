// Greedy

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

char inputFile[] = "input2.txt";

vector<int> nodes;
vector<int> groups;
int number_of_nodes, number_of_bits;

int bit_count(int i, int j){
    int value = nodes[i] ^ nodes[j];
    
    int count;
    for(count = 0; value != 0; ++count) {
        value &= (value - 1);
    }
    
    return count;
}

int _find(int u) {
    return groups[u] == u ? u : (groups[u] = _find(groups[u]));
}
bool _union(int u, int v){
    u = _find(u);
    v = _find(v);
    if (u != v) {
        groups[v] = u;
        return true;
    }
    return false;
}

int main(){
    FILE* pfile = fopen(inputFile, "r");
    fscanf(pfile, "%d %d\n", &number_of_nodes, &number_of_bits);
    nodes = vector<int>(number_of_nodes+1);
    int node_number = 1;
    while(!feof(pfile)) {
        int bit, value = 0;
        for(int i = 0; i < number_of_bits; ++i){
            fscanf(pfile, "%d ", &bit);
            value <<= 1;
            value |= bit;
        }
        nodes[node_number++] = value;
    }
    fclose(pfile);
    
    groups = vector<int>(number_of_nodes+1);
    for(int i = 1; i <= number_of_nodes; ++i)
        groups[i] = i;
    
    int number_of_clusters = number_of_nodes;
    
    for(int i = 1; i <= number_of_nodes; ++i){
        for(int j = i+1; j <= number_of_nodes; ++j){
            if(bit_count(i, j) > 2)
                continue;
            
            if(_union(i, j)) {
                number_of_clusters--;
            }
        }
    }
    
    printf("answer : %d\n", number_of_clusters);
    
    return 0;
}
