i = 7
j = 0
while i > 0 and j < 4:
    print(' ' * j, end="")
    print('*' * i, end="")
    print(' ' * j, end="")
    print()
    i -= 2
    j += 1
