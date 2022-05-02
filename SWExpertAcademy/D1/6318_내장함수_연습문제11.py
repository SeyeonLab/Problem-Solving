data1 = list('abcdef')
data2 = range(6)
obj = dict(zip(data1, data2))

for key, val in obj.items():
    print("%s: %d" % (key, val))