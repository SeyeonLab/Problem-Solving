import sys
n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))
b, c = map(int, sys.stdin.readline().split())
result = 0

for num in data:
    if num > 0:
        num -= b
        result += 1

    if num > 0:
        result += num // c
        if num % c != 0:
            result += 1

print(result)
