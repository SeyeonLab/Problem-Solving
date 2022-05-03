dr = [0, -1, 0, 1]
dc = [-1, 0, 1, 0]

def solution(places):
    answer = []
    for place in places:
        def search(r, c, x, y):
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                if nr < 0 or nc < 0 or nr >= 5 or nc >= 5:
                    continue
                if nr == x and nc == y:
                    continue
                if place[nr][nc] == 'P':
                    return True
            return False

        check = False
        examinee_list = []
        for i in range(5):
            for j in range(5):
                if place[i][j] == 'P':
                    examinee_list.append((i, j))

        for r, c in examinee_list:
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                if nr < 0 or nc < 0 or nr >= 5 or nc >= 5:
                    continue
                if place[nr][nc] == 'X':
                    continue
                if place[nr][nc] == 'P':
                    check = True
                    answer.append(0)
                    break
                if place[nr][nc] == 'O' and search(nr, nc, r, c):
                    check = True
                    answer.append(0)
                    break

            if check:
                break

        if not check:
            answer.append(1)

    return answer