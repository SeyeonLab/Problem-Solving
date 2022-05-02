def solution(n, arr1, arr2):
    answer = []

    for i in range(n):
        temp = bin(arr1[i] | arr2[i])[2:]  # arr1과 arr2에서 하나라도 #이면 1, 아닌 경우 0
        temp = temp.rjust(n, '0')  # 길이에 맞춰 0 추가
        temp = temp.replace('1', '#')
        temp = temp.replace('0', ' ')
        answer.append(temp)

    return answer