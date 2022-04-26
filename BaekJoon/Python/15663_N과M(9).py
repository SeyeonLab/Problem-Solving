def dfs():
    if len(answer) == m:
        temp = ' '.join(map(str, answer))
        if temp not in result:
            result[temp] = 1
            print(temp)
        return

    for i in range(n):
        if check[i]:
            continue
        answer.append(data[i])
        check[i] = True
        dfs()
        answer.pop()
        check[i] = False


n, m = map(int, input().split())
data = sorted(map(int, input().split()))
answer = []
result = {}
check = [False] * n
dfs()
# 딕셔너리가 리스트보다 탐색 속도가 빠름
