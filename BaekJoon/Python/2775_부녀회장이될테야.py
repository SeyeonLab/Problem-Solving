t = int(input())

for _ in range(t):
    k = int(input())
    n = int(input())
    data = [x for x in range(1, n + 1)]
    for _ in range(k):
        for i in range(1, n):
            data[i] += data[i - 1]

    print(data[-1])
