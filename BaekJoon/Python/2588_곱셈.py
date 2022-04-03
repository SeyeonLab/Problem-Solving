num1 = int(input())
num2 = int(input())
sum = 0

for i in range(3):
    temp = num1 * (num2 % 10)
    num2 //= 10
    sum += temp * pow(10, i)
    print(temp)

print(sum)
