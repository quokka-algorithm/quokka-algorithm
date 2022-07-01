# 4386. 별자리 만들기
import sys
input = sys.stdin.readline

def mark_weight(nodes):
    res = []
    for i, (x, y) in enumerate(nodes):
        pi[i] = i
        for j, (xx, yy) in enumerate(nodes):
            if i == j: continue
            dist = ((x-xx)**2 + (y-yy)**2) ** 0.5
            res.append((dist, i, j))

    return res

def union(x,y):
    xroot = find(x)
    yroot = find(y)

    if xroot == yroot: return
    pi[xroot] = yroot


def find(node):
    if node == pi[node]: return node
    pi[node] = find(pi[node])
    return pi[node]

n = int(input())
pi = dict()

nodes = [tuple(map(float, input().split())) for _ in range(n)]
graph = mark_weight(nodes)
graph.sort()

cnt = 0
mst = 0

END = n-1
for w,a,b in graph:
    if cnt == END: break
    if find(a) == find(b): continue

    union(a,b)
    cnt += 1
    mst += w

print(mst)