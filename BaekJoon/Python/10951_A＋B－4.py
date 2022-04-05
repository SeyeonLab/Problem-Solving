# 입력이 끝날 때 까지(EOF 활용)
while True:
    try:
        a, b = map(int, input().split())
        print(a + b)
    except EOFError:
        break
