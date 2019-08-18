# Heap

완전 이진 트리 (왼쪽부터 채움)  

## index
parent : [i/2]  
left : [2i]  
right : [2i+1]  

## 특징
1. 임의의 노드 값은 그 부모의 값보다 클 수 없다. (이진 트리로 구성한 배열)  
2. 절반은 리프노드이다.  
완전 이진 트리이기 때문에 [n/2]+1, ..., n 까지는 리프노드  

## 연산
### insert
배열 마지막에 원소를 추가하고 heap구조를 만족하면서 bubble-up하여 heapify함.  
![pictures/BFS_Layer_tree.png](pictures/insert_1.png)

### extract
배열 첫번째 원소를 빼고 마지막 원소로 채워넣고 bubble-down하여 heapify함.  
![pictures/BFS_Layer_tree.png](pictures/extract_1.png)

## 시간
최악의 경우는 리프노드가 절반이 채워질 경우.  
3n크기의 트리에서 2n크기의 서브트리를 선택.  
T(n) <= T(2n/3)+O(1)
![pictures/BFS_Layer_tree.png](pictures/tree_size.png)