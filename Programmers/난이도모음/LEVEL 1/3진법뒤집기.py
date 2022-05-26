import math

def solution(n):
    val = ""
    answer = 0
    x = 0
    while n > 0:
        num = n % 3
        val += str(num)
        n //= 3
    for i in range(len(val)-1, -1, -1):
        answer += int(val[i]) * math.pow(3, x)
        x += 1
    return answer