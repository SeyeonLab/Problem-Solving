def solution(d, budget):
    answer = 0
    sum = 0
    d.sort()
    for data in d:
        sum += data
        if sum > budget:
            continue
        answer += 1
    return answer