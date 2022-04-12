t = int(input())

for _ in range(t):
    h, w, n = map(int, input().split())
    count = 1
    for i in range(1, w + 1):
        for j in range(1, h + 1):
            if count == n:
                print(j, end="")
                if i < 10:
                    print(0, end="")
                print(i, end="")
                print()
            count += 1
