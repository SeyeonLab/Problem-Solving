n, m = map(int, input().split())
nums = list(map(int, input().split()))
answer = 0

for i in range(n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            sum = nums[i] + nums[j] + nums[k]
            if sum <= m:
                answer = max(answer, sum)

print(answer)
