maxVal = -1e9
idx = 0

for i in range(1, 10):
    num = int(input())
    if num > maxVal:
        maxVal = num
        idx = i

print(maxVal)
print(idx)
