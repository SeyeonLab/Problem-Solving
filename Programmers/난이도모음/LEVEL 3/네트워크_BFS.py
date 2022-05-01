def solution(n, computers):
    answer = 0
    visited = [False for _ in range(n)]
    
    def bfs(i):
        from collections import deque
        queue = deque([i])
        visited[i] = True

        while queue:
            i = queue.popleft()
            visited[i] = True
            for j in range(n):
                if i != j and computers[i][j] == 1:
                    if not visited[j]:
                        queue.append(j)

    for i in range(n):
        if not visited[i]:
            bfs(i)
            answer += 1

    return answer   
