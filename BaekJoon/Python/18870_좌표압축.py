n = int(input())
coordinate = list(map(int, input().split()))
array = []

for i in range(n):
    array.append([coordinate[i], i])

array.sort()
temp = array[0][0]
array[0][0] = 0

for i in range(1, n):
    if array[i][0] == temp:
        temp = array[i][0]
        array[i][0] = array[i - 1][0]
    else:
        temp = array[i][0]
        array[i][0] = array[i - 1][0] + 1

array.sort(key=lambda x: x[1])
for i in range(n):
    print(array[i][0], end=" ")
