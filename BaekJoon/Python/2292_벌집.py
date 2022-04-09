N = int(input())
level = 1
num = 1

while True:
    i = 6 * (level - 1)
    if N == 1:
        print(1)
        break
    if num < N <= num + i:
        print(level)
        break
    num += i
    level += 1
