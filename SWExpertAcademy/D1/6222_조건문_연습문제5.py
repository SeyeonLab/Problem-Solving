char = input()

if char.isupper():
    print("{0}(ASCII: {1}) => {2}(ASCII: {3})".format(
        char, ord(char), char.lower(), ord(char.lower())))
elif char.islower():
    print("{0}(ASCII: {1}) => {2}(ASCII: {3})".format(
        char, ord(char), char.upper(), ord(char.upper())))
        