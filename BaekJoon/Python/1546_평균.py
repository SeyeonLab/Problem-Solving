n = int(input())
array = list(map(int, input().split()))
max_value = 0

for data in array:
    max_value = max(max_value, data)

sum = 0.0
for i in range(n):
    array[i] /= max_value
    array[i] *= 100
    sum += array[i]

print(sum / n)
