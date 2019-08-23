// Greedy

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;

char inputFile[] = "/Users/hongseobshin/Desktop/Hugo/content/Algorithms/Greedy/HuffmanCode/Problems/Coursera_Assignment/input1.txt";

struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    int weight = 0;
};

vector<int> symbols;
int number_of_symbols;

int getMaxLength(Node* node, int depth) {
    if (node == nullptr) return depth;
    
    return max(getMaxLength(node->left, depth+1), getMaxLength(node->right, depth+1));
}
int getMinLength(Node* node, int depth) {
    if (node == nullptr) return depth;
    
    return min(getMinLength(node->left, depth+1), getMinLength(node->right, depth+1));
}

void huffmanCode() {
    priority_queue<tuple<int,Node*>> heap;
    for(int i = 1; i <= number_of_symbols; ++i){
        auto node = new Node();
        node->weight = symbols[i];
        heap.push(make_tuple(-node->weight, node));
    }
    
    while(heap.size() > 1) {
        auto left = heap.top(); heap.pop();
        auto right = heap.top(); heap.pop();
        
        auto node = new Node();
        node->left = get<1>(left);
        node->right = get<1>(right);
        node->weight = (-get<0>(left)) + (-get<0>(right));
        heap.push(make_tuple(-node->weight, node));
    }
    
    auto root = heap.top();
    int min_length = getMinLength(get<1>(root), 0) - 1;
    int max_length = getMaxLength(get<1>(root), 0) - 1;
    
    printf("%d, %d\n", min_length, max_length);
}

int main(){
    FILE* pfile = fopen(inputFile, "r");
    fscanf(pfile, "%d\n", &number_of_symbols);
    symbols = vector<int>(number_of_symbols+1);
    
    int count_symbol = 1;
    while(!feof(pfile)) {
        int value = 0;
        fscanf(pfile, "%d ", &value);
        symbols[count_symbol++] = value;
    }
    fclose(pfile);
    
    huffmanCode();
    
    return 0;
}
