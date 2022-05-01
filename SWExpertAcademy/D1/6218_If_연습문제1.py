# 다음의 결과와 같이 임의의 양의 정수를 입력받아 그 정수의 모든 약수를 구하십시오.

n = int(input())

for i in range(1, n+1):
    if n % i == 0:
        print("{0}(은)는 {1}의 약수입니다.".format(i, n))
