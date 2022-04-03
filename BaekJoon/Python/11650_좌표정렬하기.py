import sys

n = int(input())
list = []

for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    list.append((x, y))

list.sort()
for data in list:
    print(data[0], data[1])
