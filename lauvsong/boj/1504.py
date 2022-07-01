# 1504. 특정한 최단경로
import heapq as hq
import sys
input = sys.stdin.readline

def get_answer():
    a = dijkstra(1)
    b = dijkstra(v1)
    c = dijkstra(v2)

    return min(a[v1] + b[v2] + c[N], a[v2] + c[v1] + b[N])


def dijkstra(start):
    dist = [INF for _ in range(MAX_NODE)]
    heap = [(0, start)]
    dist[start] = 0

    while heap:
        d, node = hq.heappop(heap)
        if dist[node] < d: continue
        
        for n, w in graph[node]:
            cost = dist[node] + w
            if dist[n] <= cost: continue

            dist[n] = cost
            hq.heappush(heap, (cost, n))

    return dist

INF = float('inf')
MAX_NODE = 801
graph = [[] for _ in range(MAX_NODE)]

N, E = map(int, input().split())
for _ in range(E):
    a,b,c = map(int, input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

v1, v2 = map(int, input().split())
res = get_answer()
print(res if res < INF else -1)