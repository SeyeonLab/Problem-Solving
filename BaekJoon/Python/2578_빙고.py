board = [list(map(int, input().split())) for _ in range(5)]
checked = [[False]*5 for _ in range(5)]
nums = []
for _ in range(5):
    nums += map(int, input().split())

def bingo(num):
    for i in range(5):
        for j in range(5):
            if board[i][j] == num:
                checked[i][j] = True

def bingo_check():
    answer = 0
    # 행과 열 탐색
    for i in range(5):
        if checked[i][0] and checked[i][1] and checked[i][2] and checked[i][3] and checked[i][4]:
            answer += 1
        if checked[0][i] and checked[1][i] and checked[2][i] and checked[3][i] and checked[4][i]:
            answer += 1
    # 좌우 대각선 탐색
    if checked[0][0] and checked[1][1] and checked[2][2] and checked[3][3] and checked[4][4]:
        answer += 1
    # 우좌 대각선 탐색
    if checked[0][4] and checked[1][3] and checked[2][2] and checked[3][1] and checked[4][0]:
        answer += 1

    return answer


for num in nums:
    bingo(num)
    if bingo_check() >= 3:
        print(nums.index(num)+1)
        break

