import sys

n = int(input())
data = [0] * 10001
for i in range(n):
    data[int(sys.stdin.readline())] += 1

for i in range(10001):
    while data[i]:
        sys.stdout.write(str(i) + '\n')
        data[i] -= 1
