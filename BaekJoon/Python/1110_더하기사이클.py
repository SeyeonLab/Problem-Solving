n = int(input())
temp = n
count = 0

while True:
    temp = (temp % 10) * 10 + (temp // 10 + temp % 10) % 10
    count += 1
    if temp == n:
        print(count)
        break
