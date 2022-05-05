def promising(x, y):
    numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    # 행과 열 탐색
    for i in range(9):
        if board[x][i] in numbers:
            numbers.remove(board[x][i])
        if board[i][y] in numbers:
            numbers.remove(board[i][y])

    # 3 x 3 영역 탐색
    nx = (x // 3) * 3
    ny = (y // 3) * 3
    for i in range(nx, nx+3):
        for j in range(ny, ny+3):
            if board[i][j] in numbers:
                numbers.remove(board[i][j])

    return numbers

def dfs(idx):
    global flag

    if flag:
        return
    if idx == len(blank):
        for row in board:
            print(*row)
        flag = True
        return

    x = blank[idx][0]
    y = blank[idx][1]
    numbers = promising(x, y)
    for num in numbers:
        board[x][y] = num
        dfs(idx + 1)
        board[x][y] = 0


board = [list(map(int, input().rstrip().split())) for _ in range(9)]
blank = [(i, j) for i in range(9) for j in range(9) if board[i][j] == 0]
flag = False
dfs(0)