# 1197. 최소 스패닝 트리
import sys
input = sys.stdin.readline

def find(node):
    if node == pi[node]:
        return node
    
    pi[node] = find(pi[node])
    return pi[node]

def union(a,b):
    a_pi = find(a)
    b_pi = find(b)

    if a_pi < b_pi:
        pi[b_pi] = a_pi
    else:
        pi[a_pi] = b_pi
    

V, E = map(int, input().split())
nodes = []
pi = dict()

for _ in range(E):
    A, B, C = map(int, input().split())
    nodes.append((C, A, B))
    pi[A] = A
    pi[B] = B

nodes.sort()

cnt = 0
mst = 0
for w, a, b, in nodes:
    if cnt == V-1:
        break

    if find(a) != find(b):
        union(a,b)
        mst += w
        cnt += 1

print(mst)