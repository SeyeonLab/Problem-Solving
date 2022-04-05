t = int(input())

for i in range(t):
    res = input()
    score = 0
    temp = 0
    for ox in res:
        if ox == 'O':
            temp += 1
        else:
            temp = 0
        score += temp
    print(score)
