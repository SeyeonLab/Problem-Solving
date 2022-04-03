a, b = map(int, input().split())
t = int(input())
a += t // 60
b += t % 60
a += b // 60
b %= 60

if a >= 24:
    a %= 24

print(a, b)

