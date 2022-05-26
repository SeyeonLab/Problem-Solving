# 1 2 3 4 5 ...
# 2 1 2 3 2 4 2 5 ...
# 3 3 1 1 2 2 4 4 5 5 ...
def solution(answers):
    answer = []
    problem = {1: 0, 2: 0, 3: 0}
    user1 = [1, 2, 3, 4, 5]
    user2 = [2, 1, 2, 3, 2, 4, 2, 5]
    user3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    for i in range(len(answers)):
        if answers[i] == user1[i % 5]:
            problem[1] += 1
        if answers[i] == user2[i % 8]:
            problem[2] += 1
        if answers[i] == user3[i % 10]:
            problem[3] += 1
    temp = sorted(problem.items(), key=lambda x: x[1], reverse=True)
    for user in temp:
        if user[1] == max(problem.values()) and user[1] > 0:
            answer.append(user[0])

    return sorted(answer)