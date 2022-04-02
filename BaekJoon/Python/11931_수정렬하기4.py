n = int(input())
array = []
for _ in range(n):
    array.append(int(input()))

for num in sorted(array, reverse=True):
    print(num)
