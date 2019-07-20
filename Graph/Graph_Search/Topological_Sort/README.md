# 위상정렬

## 정의
유향 그래프에서 방향을 거스르지 않고 나열하는 것.  

## 특징
1. 사이클이 없는 그래프 DAG (Directed Acyclic Graph)로 구성됨.  
- cycle이 있는 경우에는 위상 정렬이 성립되지 않기 때문.  

## 코드
구현 방법  
1. DFS 특징인 깊은 것부터 탐색하는 것을 이용하여 구현.  
- 최고 깊은 정점에 도달했을 때, 빠져나오면서 카운트 (위상정렬 거꾸로 됨).  

```c++
bool dfs(int u){
    dfs_num[u] = ++dfs_time;
    for(int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        if(dfs_num[v] == 0){
            if(!dfs(v)) return false;
        } else if(!finished[v] && dfs_num[u] >= dfs_num[v]){ // back edge => cycle
            return false;
        }
    }
    
    topologicalSort.push_back(u);
    finished[u] = true;
    return true;
}
```

2. 그래프 들어오는 차수(degree)를 이용하여 구현.  
- 그래프 들어오는 차수가 0이면 시작점.  
- 나가는 간선을 하나씩 없애면서 구현.  
