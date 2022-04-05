a = int(input())
b = int(input())
c = int(input())

res = str(a * b * c)
array = [0 for _ in range(10)]

for char in res:
    array[ord(char) - ord('0')] += 1

for n in array:
    print(n)
