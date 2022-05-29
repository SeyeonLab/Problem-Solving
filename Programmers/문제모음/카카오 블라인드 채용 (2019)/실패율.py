def solution(N, stages):
    answer = {}
    clear = len(stages)

    for i in range(1, N+1):
        if clear == 0:
            answer[i] = 0.0
        else:
            unclear = stages.count(i)
            answer[i] = unclear / clear
            clear -= unclear

    return sorted(answer, key=lambda x: answer[x], reverse=True)