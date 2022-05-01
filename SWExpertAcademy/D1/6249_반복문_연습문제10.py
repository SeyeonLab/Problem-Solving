num = input()
cnt = [0] * 10
print("0 1 2 3 4 5 6 7 8 9")

for n in num:
    cnt[int(n) - int('0')] += 1

for i in range(9):
    print(cnt[i], end=" ")
print(cnt[9])
