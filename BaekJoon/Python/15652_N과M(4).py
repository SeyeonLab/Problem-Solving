def dfs(start):
    if len(answer) == m:
        print(' '.join(map(str, answer)))
        return

    for i in range(start, n+1):
        answer.append(i)
        dfs(i)
        answer.pop()


n, m = map(int, input().split())
answer = []
dfs(1)
