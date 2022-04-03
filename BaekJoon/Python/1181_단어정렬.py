import sys
n = int(input())
array = []
for i in range(n):
    array.append(sys.stdin.readline().strip())

# Set 자료형을 통해 중복을 제거 -> 다시 리스트로 만들어서 정렬
new_array = sorted(set(array), key=lambda x: (len(x), x))
for data in new_array:
    sys.stdout.write(data + '\n')

