def square(n):
    print("square({}) => {}".format(n, n**2))


num_list = list(map(int, input().split(', ')))
for num in num_list:
    square(num)
