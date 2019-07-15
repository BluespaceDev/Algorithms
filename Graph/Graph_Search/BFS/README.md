# BFS (Breadth-First Serch)
  
## 너비 우선 탐색 기본 개념

그래프 정점을 방문 할 때, Layer 단위로 방문하여 Search.  

![pictures/BFS_Layer_tree.png](pictures/BFS_Layer_tree.png)

## 정점 구분

정점을 coloring 하여 구분한다.  
  
White | Gray | Black |
------|------|-------|
방문전 | 경계선 | 방문후
  
## 사용
최단 경로 찾기에 주로 BFS 사용한다.  
최단 경로는 다양하게 응용이 될 수 있다.  
단순히 최단 거리가 아니라 그래프를 만들어서 최소라든지... 등  
  
## 특징
1. BFS에서 Queue안에 있는 정점(Gray)는 최대 Layer가 1개 차이 난다.
<details>
<summary>증명</summary>
<div markdown="1">
<img src="pictures/BFS_Q_Layer.png">
</div>
</details>  
  
2. 스패닝 트리를 이용하여 최단 경로를 구할 수 있다.  

## BFS 코드
```c++
// 각 정점 초기화

// BFS 시작

```

## BFS 스패닝 트리

새로운 정점을 발견할 때 사용한 간선들을 이용하여 트리를 구성한 것.  
스패닝 트리 안에서 최단 경로를 찾을 수 있다. (시작점에서 다른 모든 정점까지)  

![pictures/BFS_spanning_tree.png](pictures/BFS_spanning_tree.png)

선행 부분 그래프(부모 저장한 배열)로 구성할 수 있다.  
경로 : a->b->c->d 이면,  역으로 d부터 시작하여 부모를 따라가면 경로를 구할 수 있다.  

### BFS 스패닝 트리 코드
```c++
vector<int> shortestPath(int v, const vector<int>& parent) {
    vector<int> path(1,v);  // (컨테이너크기, 시작값)
    while(parent[v] != v) { // 시작점이 아니면
        v = parent[v];      // 역으로 따라 가서
        path.push_back(v);  // 경로에 넣음
    }
    reverse(path.begin(), path.end());  // 역순이기 때문에 뒤집어야함
    return path;
}
```

## 응용문제
- 트리의 지름