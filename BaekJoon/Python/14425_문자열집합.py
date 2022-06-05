import sys
n, m = map(int, sys.stdin.readline().split())
s = set()
answer = 0

for i in range(n):
    s.add(sys.stdin.readline())
for i in range(m):
    if sys.stdin.readline() in s:
        answer += 1

print(answer)