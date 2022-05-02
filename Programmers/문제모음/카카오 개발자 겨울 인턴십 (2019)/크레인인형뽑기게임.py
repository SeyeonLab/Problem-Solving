def solution(board, moves):
    answer = 0
    bucket = []
    temp = list(zip(*board))
    board = [list(t) for t in temp]

    for move in moves:
        for i in range(len(board)):
            # 인형 없는 칸은 스킵
            if board[move - 1][i] == 0:
                continue
            # 바구니가 비어있지 않음 && 크레인이 현재 집은 인형과 바구니 맨 위의 인형이 같은 경우 터짐
            if bucket and bucket[-1] == board[move - 1][i]:
                bucket.pop()
                answer += 2
            # 아닐 경우, 바구니에 인형을 넣음
            else:
                bucket.append(board[move - 1][i])
            # 집은 인형을 빈 칸으로 만듦
            board[move - 1][i] = 0
            break

    return answer