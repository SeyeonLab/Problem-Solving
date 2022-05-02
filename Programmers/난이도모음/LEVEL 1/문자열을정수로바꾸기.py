def solution(s):
    return int(-int(s[1:])) if s[0] == '-' else int(s[0:])