def playing_game(man1, man2):
    if man1 == "바위" and man2 == "가위" or man1 == "가위" and man2 == "바위":
        print("바위가 이겼습니다!")
    elif man1 == "가위" and man2 == "보" or man1 == "보" and man2 == "가위":
        print("가위가 이겼습니다!")
    elif man1 == "보" and man2 == "바위" or man1 == "바위" and man2 == "보":
        print("보가 이겼습니다!")


user1 = input()
user2 = input()
play1 = input()
play2 = input()
playing_game(play1, play2)



