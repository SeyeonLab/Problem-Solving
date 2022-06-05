import sys

n = int(input())
nlist = set(map(int, sys.stdin.readline().rstrip().split()))
m = int(input())
mlist = list(map(int, sys.stdin.readline().rstrip().split())) 

for data in mlist:
    if data in nlist:
        print(1, end=' ')
    else:
        print(0, end=' ')