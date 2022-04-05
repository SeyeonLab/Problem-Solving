c = int(input())

for _ in range(c):
    data = list(map(int, input().split()))
    avg = sum(data[1:]) / data[0]
    count = 0
    for score in data[1:]:
        if score > avg:
            count += 1
    rate = count / data[0] * 100
    # f-string 문자열 포맷팅 사용
    print(f'{rate:.3f}%')
