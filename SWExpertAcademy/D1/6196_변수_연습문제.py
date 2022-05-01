# 1~9 사이의 정수 a를 입력받아 a + aa + aaa + aaaa 의 값을 계산하는 프로그램을 작성하십시오.

a = input()
print(int(a) + int(a+a) + int(a+a+a) + int(a+a+a+a))
