array = [False for _ in range(10500)]


def d(n):
    sum = n
    while n != 0:
        sum += n % 10
        n //= 10
    return sum


for i in range(10001):
    num = d(i)
    array[num] = True

for i in range(10001):
    if not array[i]:
        print(i)
