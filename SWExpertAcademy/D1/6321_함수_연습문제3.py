def checking(num):
    for i in range(2, num):
        if num % i == 0:
            return
    print("소수입니다.")


num = int(input())
checking(num)
