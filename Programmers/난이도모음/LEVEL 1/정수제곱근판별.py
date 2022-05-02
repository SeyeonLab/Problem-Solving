import math
def solution(n):
    x = math.sqrt(n)
    return -1 if x - int(x) > 0 else (x+1)**2