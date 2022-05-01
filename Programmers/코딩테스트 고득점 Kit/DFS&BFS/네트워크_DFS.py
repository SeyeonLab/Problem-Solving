def solution(n, computers):
    answer = 0
    visited = [False for _ in range(n)]
    
    def dfs(i):
        visited[i] = True      
        for j in range(n):
            if i != j and computers[i][j] == 1:
                if not visited[j]:
                    dfs(j)

    for i in range(n):
        if not visited[i]:
            dfs(i)
            answer += 1
            
    return answer