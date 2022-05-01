def func(s1, s2):
    if len(s1) > len(s2):
        print(s1)
    else:
        print(s2)


str1, str2 = map(str, input().split(', '))
func(str1, str2)
