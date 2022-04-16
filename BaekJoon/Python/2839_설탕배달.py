n = int(input())
count = 0

while n > 0:
    if n % 5 == 0:
        n -= 5
    elif n % 3 == 0:
        n -= 3
    elif n > 5:
        n -= 5
    else:
        count = -1
        break

    count += 1

print(count)
