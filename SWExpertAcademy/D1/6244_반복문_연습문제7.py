score = [85, 65, 77, 83, 75, 22, 98, 88, 38, 100]
sum = 0
while score:
    num = score.pop()
    if num >= 80:
        sum += num
print(sum)
