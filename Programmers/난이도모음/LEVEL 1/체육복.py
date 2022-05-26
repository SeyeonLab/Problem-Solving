def solution(n, lost, reserve):
    answer = n
    for i in range(1, 31):
        if i in lost and i in reserve:
            lost.remove(i)
            reserve.remove(i)

    lost.sort()
    reserve.sort()
    for num in lost:
        if (num - 1) in reserve:
            reserve.remove(num - 1)
        elif (num + 1) in reserve:
            reserve.remove(num + 1)
        else:
            answer -= 1

    return answer