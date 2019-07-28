#include <cstdio>

#define MAX_N   100000

int edge_count[MAX_N+1];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i < N; ++i) {
        int a,b;
        scanf("%d %d", &a,&b);
        edge_count[a]++;
        edge_count[b]++;
    }
    
//    if(N == 2) { // 절단점 없음
//        edge_count[0]++;
//        edge_count[1]++;
//    }
    
    scanf("%d", &N);
    while(N--) {
        int a,b;
        scanf("%d %d", &a,&b);
        if (a == 1) {
            if(edge_count[b] == 1)
                printf("no\n");
            else
                printf("yes\n");
        } else {
            printf("yes\n");
        }
    }
    
    return 0;
}