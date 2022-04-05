data = [False for _ in range(42)]
count = 0

for _ in range(10):
    data[int(input()) % 42] = True

for d in data:
    if d:
        count += 1

print(count)
