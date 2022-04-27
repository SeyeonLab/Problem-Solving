def func(idx, cnt):
    global answer

    if cnt == N // 2:
        start_score, link_score = 0, 0
        for i in range(N):
            for j in range(N):
                # 선택된 번호는 스타트팀, 선택되지 않은 번호는 링크팀
                if selected[i] and selected[j]:
                    start_score += S[i][j]
                elif not selected[i] and not selected[j]:
                    link_score += S[i][j]
        answer = min(answer, abs(start_score - link_score))
        return

    for i in range(idx, N):
        if not selected[i]:
            selected[i] = True
            func(i+1, cnt+1)
            selected[i] = False


N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]
selected = [False for _ in range(N)]
answer = 1e9

func(0, 0)
print(answer)
