student = [88, 30, 61, 55, 95]
for i in range(5):
    if student[i] >= 60:
        print("{}번 학생은 {}점으로 합격입니다.".format(i+1, student[i]))
    else:
        print("{}번 학생은 {}점으로 불합격입니다.".format(i+1, student[i]))
