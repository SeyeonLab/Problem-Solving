def solution(numbers, target):
    answer = 0
    
    def dfs(num, idx):
        if idx == len(numbers):
            if num == target:
                nonlocal answer
                answer += 1
            return
        else:
            dfs(num - numbers[idx], idx+1)
            dfs(num + numbers[idx], idx+1)
        
    dfs(0, 0)
    return answer