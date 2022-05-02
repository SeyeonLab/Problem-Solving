data = "ADCBBBBCABBCBDACBDCAACDDDCAABABDBCBCBDBDBDDABBAAAAAAADADBDBCBDABADCADC"
data = list(data)
answer = list(map(lambda x: ord('E') - ord(x), data))
print(sum(answer))
