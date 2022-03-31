N, M = map(int, input().split())
board = []

for i in range(N):
    board.append(input())

answer = 10000

for i in range(N-7):
    for j in range(M-7):
        cntB = cntW = 0

        for k in range(i, i+8):
            for l in range(j, j+8):
                if ((k + l) % 2 == 0):
                    if (board[k][l] == 'B'):
                        cntW += 1
                    else:
                        cntB += 1
                else:
                    if (board[k][l] == 'B'):
                        cntB += 1
                    else:
                        cntW += 1

        answer = min(answer, cntB)
        answer = min(answer, cntW)

print(answer)
