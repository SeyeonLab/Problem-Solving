def hanoi(n, start, end):
    if n == 1:
        print(start, end)
        return

    temp = 6 - (start + end)
    hanoi(n - 1, start, temp)
    print(start, end)
    hanoi(n - 1, temp, end)


n = int(input())
print((1 << n) - 1)
hanoi(n, 1, 3)
