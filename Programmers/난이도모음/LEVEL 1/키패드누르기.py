def solution(numbers, hand):
    answer = ''
    keypad = {
        '1': (0, 0),
        '2': (0, 1),
        '3': (0, 2),
        '4': (1, 0),
        '5': (1, 1),
        '6': (1, 2),
        '7': (2, 0),
        '8': (2, 1),
        '9': (2, 2),
        '*': (3, 0),
        '0': (3, 1),
        '#': (3, 2)
    }
    cur = {'left': '*', 'right': '#'}
    left_key = [1, 4, 7]
    right_key = [3, 6, 9]

    for number in numbers:
        if number in left_key:
            answer += 'L'
            cur['left'] = str(number)
        elif number in right_key:
            answer += 'R'
            cur['right'] = str(number)
        else:
            column = abs(keypad[str(number)][0] - keypad[cur['left']][0])
            row = abs(keypad[str(number)][1] - keypad[cur['left']][1])
            left = column + row

            column = abs(keypad[str(number)][0] - keypad[cur['right']][0])
            row = abs(keypad[str(number)][1] - keypad[cur['right']][1])
            right = column + row

            if left == right:
                if hand == 'left':
                    answer += 'L'
                    cur['left'] = str(number)
                elif hand == 'right':
                    answer += 'R'
                    cur['right'] = str(number)
            elif left < right:
                answer += 'L'
                cur['left'] = str(number)
            elif left > right:
                answer += 'R'
                cur['right'] = str(number)

    return answer