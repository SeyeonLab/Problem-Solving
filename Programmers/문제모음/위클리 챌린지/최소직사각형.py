def solution(sizes):
    side1 = 0
    side2 = 0
    for i in range(len(sizes)):
        side1 = max(side1, max(sizes[i][0], sizes[i][1]))
    for i in range(len(sizes)):
        side2 = max(side2, min(sizes[i][0], sizes[i][1]))

    return side1 * side2