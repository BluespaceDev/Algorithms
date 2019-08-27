# Jonhson's Algorithms

## 동작
1. 시작점 s를 추가하고 모든 vertex에 연결하여 새로운 그래프를 만든다.  
2. s에서 각 vertex까지 최단 거리p 를 구한다. (bellman-ford : negative edge때문)  
3. 최단거리 p를 이용하여 각 edge에 대해 nonnegative위해 reweight한다.  
4. 다익스트라 알고리즘을 각 정점마다 구한다.  
5. 각 정점마다 최단거리를 재 계산한다 d(u,v) = d'(u,v) - pu + pv  

## 증명
- reweight한 edge는 nonnegative이다.  
c' = c + pu - pv  
c : w(u,v)  
pu : 최단거리 s-u  
pv : 최단거리 s-v  
2가지 case생각  
1. s-v까지 최단거리 pv가 정점 u를 포함할때. s~>u->v가 최단거리일 경우  
pv = pu + w(u,v) 가 된다.
2. s-v까지 최단거리 pv가 정점 u를 포함하지 않을 때. s~>v가 최단거리일 경우  
pv < pu + w(u,v)  
pv가 u를 포함하지 않는 최단거리이기 때문에 u를 거치는 경로 (pu+w(u,v)) 는 최단거리pv보다 작아야된다.  