import sys
input = sys.stdin.readline

def find(node):
    if node != pi[node]:
        pi[node] = find(pi[node])
    return pi[node]

def union(a,b):
    a_root = find(a)
    b_root = find(b)

    if a_root < b_root:
        pi[b_root] = a_root
    else:
        pi[a_root] = b_root

pi = dict()
nodes = []
N,M = map(int, input().split())
for _ in range(M):
    a,b,c = map(int, input().split())
    nodes.append((c,a,b))
    pi[a] = a
    pi[b] = b

cnt = 0
mst = 0
nodes.sort()
for w,a,b in nodes:
    if cnt == N-2:
        break

    if find(a) != find(b):
        union(a,b)
        mst += w
        cnt += 1

print(mst)