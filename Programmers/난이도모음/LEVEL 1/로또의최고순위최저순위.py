def solution(lottos, win_nums):
    best = 0
    worst = 0
    score_dict = {0: 6, 1: 6, 2: 5, 3: 4, 4: 3, 5: 2, 6: 1}
    for lotto in lottos:
        if lotto in win_nums:
            best += 1
            worst += 1
        elif lotto == 0:
            best += 1
    return [score_dict[best], score_dict[worst]]