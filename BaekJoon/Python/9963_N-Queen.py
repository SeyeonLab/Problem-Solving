def check(x):
    for i in range(x):
        if col[x] == col[i] or abs(col[x] - col[i]) == abs(x - i):
            return False
    return True


def backtracking(x):
    global answer
    if x == n:
        answer += 1
        return
    for i in range(n):
        col[x] = i
        if check(x):
            backtracking(x+1)


n = int(input())
col = [0] * n
answer = 0

backtracking(0)
print(answer)
