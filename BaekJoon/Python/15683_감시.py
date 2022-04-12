import copy

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
cctv = []
mode = [
    [],
    [[0], [1], [2], [3]],
    [[0, 2], [1, 3]],
    [[0, 1], [1, 2], [2, 3], [3, 0]],
    [[0, 1, 2], [1, 2, 3], [2, 3, 0], [3, 0, 1]],
    [[0, 1, 2, 3]]
]

# 북 동 남 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# cctv가 존재하는 좌표를 리스트에 저장
for i in range(n):
    for j in range(m):
        if 1 <= board[i][j] < 6:
            cctv.append((board[i][j], i, j))


def fill(board, direction, x, y):
    for i in direction:
        nx = x
        ny = y
        while True:
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                break
            if board[nx][ny] == 6:
                break
            # 0인 경우 '#'을 7로 표현
            elif board[nx][ny] == 0:
                board[nx][ny] = 7


def dfs(depth, board):
    global answer

    if depth == len(cctv):
        count = 0
        for i in range(n):
            count += board[i].count(0)
        answer = min(answer, count)
        return

    temp = copy.deepcopy(board)
    cctv_num, x, y = cctv[depth]

    for direction in mode[cctv_num]:
        fill(temp, direction, x, y)
        dfs(depth + 1, temp)
        temp = copy.deepcopy(board)


answer = 1e9
dfs(0, board)
print(answer)

