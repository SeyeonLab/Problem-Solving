import functools


def comparator(x, y):
    str1 = x + y
    str2 = y + x

    if str1 < str2:
        return -1
    else:
        return 1


def solution(numbers):
    data = list(map(str, numbers))
    data.sort(key=functools.cmp_to_key(comparator), reverse=True)
    answer = str(int(''.join(data)))
    return answer
