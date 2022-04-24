def dfs(start):
    if len(answer) == m:
        print(' '.join(map(str, answer)))
        return

    for i in range(start, n):
        if not data[i] in answer:
            answer.append(data[i])
            dfs(i+1)
            answer.pop()


n, m = map(int, input().split())
data = sorted(list(map(int, input().split())))
answer = []
dfs(0)
