def solution(string, n):
    answer = ''
    for s in string:
        if s.isupper():
            s = chr((ord(s) - ord('A') + n) % 26 + ord('A'))
        elif s.islower():
            s = chr((ord(s) - ord('a') + n) % 26 + ord('a'))
        answer += s

    return answer