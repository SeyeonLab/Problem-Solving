n = int(input())
user = []
for i in range(n):
    temp = list(map(str, input().split()))
    temp.append(i)
    user.append(temp)

# 정렬 시에 나이를 int 타입으로 변경 후 정렬
user.sort(key=lambda x: (int(x[0]), x[2]))
for i in range(n):
    print(user[i][0], user[i][1])
