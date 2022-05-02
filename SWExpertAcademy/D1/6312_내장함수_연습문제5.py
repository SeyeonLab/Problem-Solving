def function(*T):
    a = 1
    T = int()
    for i in T:
        a *= i
        return a


try:
    print(function(1, 2, '4', 3))
except:
    print("에러발생")
