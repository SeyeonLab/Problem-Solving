import sys
input = sys.stdin.readline

# 수의 개수 입력 받기
n = int(input())
# 수열 입력 받기
num = list(map(int, input().split()))
# 각 연산자 개수 입력 받기
op = list(map(int, input().split()))

# 최댓값, 최솟값 초기화
max_value = -1e9
min_value = 1e9


# dfs 메서드 정의
def dfs(idx, res):
    global max_value, min_value, op

    if idx == n:
        max_value = max(max_value, res)
        min_value = min(min_value, res)
    else:
        # 덧셈
        if op[0] > 0:
            op[0] -= 1
            dfs(idx + 1, res + num[idx])
            op[0] += 1
        # 뺄셈
        if op[1] > 0:
            op[1] -= 1
            dfs(idx + 1, res - num[idx])
            op[1] += 1
        # 곱셈
        if op[2] > 0:
            op[2] -= 1
            dfs(idx + 1, res * num[idx])
            op[2] += 1
        # 나눗셈
        if op[3] > 0:
            op[3] -= 1
            dfs(idx + 1, int(res / num[idx]))
            op[3] += 1


dfs(1, num[0])
print(max_value)
print(min_value)
