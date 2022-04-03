n = int(input())
count = 0


def calc(num):
    global count
    if num < 100:
        count += 1
    elif num < 1000:
        s = str(num)
        if ord(s[0]) - ord(s[1]) == ord(s[1]) - ord(s[2]):
            count += 1


for i in range(1, n + 1):
    calc(i)

print(count)


