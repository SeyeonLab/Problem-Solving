# 이동할 네 방향 정의(동: 1, 서: 2, 북: 3, 남: 4)
dx = [1e9, 0, 0, -1, 1]
dy = [1e9, 1, -1, 0, 0]

# 현재 주사위에 적힌 숫자
dice = {'up': 0, 'down': 0, 'front': 0, 'back': 0, 'left': 0, 'right': 0}

n, m, x, y, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
moves = list(map(int, input().split()))

# 윗 면이 1인 상태로 시작
num = dice['up']


def rolling(move):
    temp = dice['down']

    # 동
    if move == 1:
        dice['down'] = dice['right']
        dice['right'] = dice['up']
        dice['up'] = dice['left']
        dice['left'] = temp
    # 서
    elif move == 2:
        dice['down'] = dice['left']
        dice['left'] = dice['up']
        dice['up'] = dice['right']
        dice['right'] = temp
    # 북
    elif move == 3:
        dice['down'] = dice['back']
        dice['back'] = dice['up']
        dice['up'] = dice['front']
        dice['front'] = temp
    # 남
    elif move == 4:
        dice['down'] = dice['front']
        dice['front'] = dice['up']
        dice['up'] = dice['back']
        dice['back'] = temp


for move in moves:
    nx = x + dx[move]
    ny = y + dy[move]

    # 지도 바깥으로 이동시키려고 하는 경우 해당 명령을 무시
    if nx < 0 or nx >= n or ny < 0 or ny >= m:
        continue

    rolling(move)

    if board[nx][ny] == 0:
        board[nx][ny] = dice['down']
    else:
        dice['down'] = board[nx][ny]
        board[nx][ny] = 0

    x = nx
    y = ny
    print(dice['up'])
