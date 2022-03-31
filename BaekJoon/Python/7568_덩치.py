N = int(input())
weight = []
height = []

for i in range(N):
    x, y = map(int, input().split())
    weight.append(x)
    height.append(y)

for i in range(N):
    count = 1
    for j in range(N):
        if weight[i] < weight[j] and height[i] < height[j]:
            count += 1

    print(count, end=" ")