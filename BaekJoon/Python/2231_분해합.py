n = int(input())
answer = 1e9

for num in range(n, n - len(str(n)) * 9, -1):
    sum = num
    temp = num
    while temp > 0:
        sum += (temp % 10)
        temp//= 10
    if sum == n:
        answer = min(answer, num)

if answer == 1e9:
    print(0)
else:
    print(answer)
