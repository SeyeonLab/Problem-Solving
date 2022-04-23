def dfs():
    if len(answer) == m:
        print(' '.join(map(str, answer)))
        return

    for i in range(n):
        if not data[i] in answer:
            answer.append(data[i])
            dfs()
            answer.pop()


n, m = map(int, input().split())
data = sorted(list(map(int, input().split())))
answer = []
dfs()
