n = int(input())
answer = 0

for _ in range(n):
    word = input()
    is_group_word = True
    dic = {}
    dic.setdefault(word[0], 1)
    for idx in range(len(word) - 1):
        if word[idx] != word[idx + 1]:
            new_word = word[idx+1:]
            if new_word.count(word[idx]) > 0:
                is_group_word = False
                break

    if is_group_word:
        answer += 1

print(answer)
