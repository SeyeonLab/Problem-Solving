def solution(nums):
    nums_set = set(nums)
    count = len(nums) // 2
    if len(nums_set) < count:
        return len(nums_set)
    else:
        return count