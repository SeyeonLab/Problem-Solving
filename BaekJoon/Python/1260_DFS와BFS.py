from collections import deque
import sys


def dfs(graph, visited, v):
    # 현재 노드 방문 처리
    visited[v] = True
    print(v, end=' ')

    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, visited, i)


def bfs(graph, visited, start):
    queue = deque([start])

    visited[start] = True

    while queue:
        x = queue.popleft()
        print(x, end=' ')

        for i in graph[x]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


n, m, v = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n + 1):
    graph[i].sort()

visited = [False] * (n + 1)
dfs(graph, visited, v)
print()
visited = [False] * (n + 1)
bfs(graph, visited, v)
