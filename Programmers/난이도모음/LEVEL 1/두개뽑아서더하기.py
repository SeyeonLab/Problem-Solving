from itertools import combinations

def solution(numbers):
    answer = []
    selected = list(combinations(numbers, 2))  # numbers배열을 2개씩 조합 후 list로 변경

    for s in selected:
        val = s[0] + s[1]
        if val not in answer:
            answer.append(val)

    return sorted(answer)