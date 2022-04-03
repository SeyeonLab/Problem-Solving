import sys

n = int(input())
array = []

for i in range(n):
    array.append(list(map(int, sys.stdin.readline().split())))

array.sort(key = lambda f: (f[1], f[0]))
for data in array:
    print(data[0], data[1])

