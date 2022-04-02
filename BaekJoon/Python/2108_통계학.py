import sys

n = int(input())
data = []
count = [0] * 8001
sum = 0
freq = 0
max_fq = 0

for i in range(n):
    data.append(int(sys.stdin.readline()))
    sum += data[i]
    count[data[i] + 4000] += 1

data.sort()

temp = 0
for i in range(8001):
    if max_fq < count[i]:
        max_fq = count[i]
        temp = i
        freq = i - 4000

for i in range(temp+1, 8001):
    if max_fq <= count[i]:
        freq = i - 4000
        break

avg = sum / n
if avg < 0:
    avg -= 0.5
else:
    avg += 0.5


print(int(avg))               # 산술평균
print(data[n // 2])           # 중앙값
print(freq)                   # 최빈값
print(data[n - 1] - data[0])  # 범위

