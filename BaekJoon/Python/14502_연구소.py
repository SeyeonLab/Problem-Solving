from collections import deque
import sys
import copy


def bfs():
    global answer
    queue = deque()
    graph_copy = copy.deepcopy(graph)
    for i in range(n):
        for j in range(m):
            if graph_copy[i][j] == 2:
                queue.append((i, j))

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if graph_copy[nx][ny] == 0:
                graph_copy[nx][ny] = 2
                queue.append((nx, ny))

    zero = 0
    for i in range(n):
        zero += graph_copy[i].count(0)
    answer = max(answer, zero)


def select_wall(cnt):
    if cnt == 3:
        bfs()
        return
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                graph[i][j] = 1
                select_wall(cnt+1)
                graph[i][j] = 0


n, m = map(int, sys.stdin.readline().split())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
answer = 0

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

select_wall(0)
print(answer)
