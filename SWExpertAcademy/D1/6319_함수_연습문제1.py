def palindrome(word):
    reverse_word = ''
    for i in range(len(word)-1, -1, -1):
        reverse_word += word[i]
    print(reverse_word)
    if word == reverse_word:
        print("입력하신 단어는 회문(Palindrome)입니다.")


palindrome(input())
