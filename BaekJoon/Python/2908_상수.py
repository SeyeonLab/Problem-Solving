a, b = map(str, input().split())
a_list = list(a)
b_list = list(b)
a_list.reverse()
b_list.reverse()
a = ''.join(a_list)
b = ''.join(b_list)

print(max(int(a), int(b)))
