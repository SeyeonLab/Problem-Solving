T = int(input())

for _ in range(T):
    R, S = map(str, input().split())
    for item in S:
        for _ in range(int(R)):
            print(item, end="")
    print()
