n = int(input())
data_set = list(map(int, input().split()))
minVal = 1e9
maxVal = -1e9

for data in data_set:
    minVal = min(minVal, data)
    maxVal = max(maxVal, data)

print(minVal, maxVal)
