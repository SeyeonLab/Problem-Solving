def draw_star(n):
    if n == 1:
        return ['*']

    stars = draw_star(n // 3)
    temp = []

    for star in stars:
        temp.append(star * 3)
    for star in stars:
        temp.append(star + ' ' * (n // 3) + star)
    for star in stars:
        temp.append(star * 3)

    return temp


n = int(input())
print('\n'.join(draw_star(n)))
