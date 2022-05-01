# 100~300 사이의 숫자에서 각각의 자리 숫자가 짝수인 숫자를 찾아 콤마(,)로 구분해 출력하는 프로그램을 작성하십시오.

for num in range(100, 301):
    num = str(num)
    if num == "288":
        print(num)
        break
    if int(num[0]) % 2 == 0 and int(num[1]) % 2 == 0 and int(num[2]) % 2 == 0:
        print(num, end=",")
