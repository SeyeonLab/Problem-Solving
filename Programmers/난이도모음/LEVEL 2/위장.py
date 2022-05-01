# Hash를 사용한 방법
def solution(clothes):
    # 1. 옷을 종류별로 구분하기
    hash_map = {}
    for _, type in clothes:
        hash_map[type] = hash_map.get(type, 0) + 1

    # 2. 입지 않는 경우를 추가하여 모든 조합 계산하기
    answer = 1
    for type in hash_map:
        answer *= hash_map[type] + 1

    # 3. 아무 종류의 옷도 입지 않는 경우 제외하기
    return answer - 1


'''
# Counter를 사용한 방법

from collections import Counter
from functools import reduce

def solution(clothes):
    # 1. 의상 종류별 Counter를 만든다.
    cnt = Counter([kind for name, kind in clothes])

    # 2. 모든 종류의 count + 1을 누적하여 곱해준다
    answer = reduce(lambda x, y: x*(y+1), cnt.values(), 1) - 1
    return answer
'''
