# DFS 문제
https://www.acmicpc.net/problem/9466

## 문제 설명
cycle이 되면 team이 됨.  
team이 아닌 멤버 수 구하기  

## 문제 조건
100,000 명  
나가는 간선은 1개.  

## 문제 풀이
cycle를 구성하는 back edge를 찾아서 멤버 수 카운트함.  
cross edge 경우에는 이미 방문한 간선은 가지 않게 해서 방지함.  
그래서 그래프에는 tree, back만 존재함.  
back edge (u->v) 에서 v를 기준으로 cycle이 되기 때문에 back edge를 발견하면 v때까지 멤버수 카운트함.  