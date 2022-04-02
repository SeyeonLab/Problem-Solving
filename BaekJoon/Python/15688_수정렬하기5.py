import sys

n = int(input())
array = []
for _ in range(n):
    array.append(int(sys.stdin.readline()))

for num in sorted(array):
    sys.stdout.write(str(num) + '\n')
