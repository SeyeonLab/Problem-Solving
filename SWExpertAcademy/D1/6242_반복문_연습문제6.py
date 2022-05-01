dictionary = {}
for i in ['A', 'A', 'A', 'O', 'B', 'B', 'O', 'AB', 'AB', 'O']:
    dictionary[i] = dictionary.get(i, 0) + 1
print(dictionary)
