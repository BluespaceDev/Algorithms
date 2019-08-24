// DP
// case 1 : n번째 weight가 포함안되면, n-1번째의 솔루션이 최적
// case 2 : n-1번째 weight가 포함안되면, n-2번째 솔루션 + n번째 weight가 최적
// 솔루션 :  max (case 1, case 2)

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;

char inputFile[] = "/Users/hongseobshin/Desktop/Hugo/content/Algorithms/Dynamic_Programming/Weighted_Independent_Set/Coursera_Assignment/input.txt";

int number_of_vertices;
vector<int> weights;

int main(){
    FILE* pfile = fopen(inputFile, "r");
    fscanf(pfile, "%d\n", &number_of_vertices);
    weights = vector<int>(number_of_vertices+1);
    
    int i = 1;
    while(!feof(pfile)) {
        int value = 0;
        fscanf(pfile, "%d\n", &value);
        weights[i++] = value;
    }
    fclose(pfile);
    
    vector<int> dp = vector<int>(weights.size());
    dp[0] = 0;
    dp[1] = weights[1];
    for(int i = 2; i < weights.size(); ++i){
        dp[i] = max(dp[i-1], dp[i-2]+weights[i]);
    }
    
    vector<bool> useVertex = vector<bool>(weights.size(), false);
    for(int i = weights.size()-1; i >= 1; ) {
        if (dp[i-1] >= dp[i-2]+weights[i]) {
            i -= 1;
        } else {
            useVertex[i] = true;
            i -= 2;
        }
    }
    
    vector<int> answer = {1, 2, 3, 4, 17, 117, 517, 997};
    for(int i : answer) {
        printf("%d", useVertex[i] ? 1 : 0);
    }
    printf("\n");
    
    return 0;
}
