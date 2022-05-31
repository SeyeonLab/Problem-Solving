def solution(citations):
    citations.sort()
    l = len(citations)

    for i in range(l):
        h = l - i               # 1. h편 이상 인용했는가? 
        if citations[i] >= h:   # 2. h번 이상 인용된 논문인가?
            return h

    return 0
