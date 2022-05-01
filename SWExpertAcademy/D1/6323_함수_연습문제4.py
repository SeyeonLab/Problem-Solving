def fibo(n):
    result = [0 for _ in range(n)]
    result[0], result[1] = 1, 1
    for i in range(2, n):
        result[i] = result[i-2] + result[i-1]
    print(result)


n = int(input())
fibo(n)