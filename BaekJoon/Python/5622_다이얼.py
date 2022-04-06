word = input()
time = 0

for letter in word:
    if 'A' <= letter <= 'C':
        time += 3
    elif 'D' <= letter <= 'F':
        time += 4
    elif 'G' <= letter <= 'I':
        time += 5
    elif 'J' <= letter <= 'L':
        time += 6
    elif 'M' <= letter <= 'O':
        time += 7
    elif 'P' <= letter <= 'S':
        time += 8
    elif 'T' <= letter <= 'V':
        time += 9
    elif 'W' <= letter <= 'Z':
        time += 10

print(time)
