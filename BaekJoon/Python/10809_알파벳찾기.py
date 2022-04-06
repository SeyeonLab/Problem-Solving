S = input()
loc = [-1 for _ in range(26)]

for i in range(len(S)):
    idx = ord(S[i]) - ord('a')
    if loc[idx] < 0:
        loc[idx] = i

for i in range(26):
    print(loc[i], end=" ")
