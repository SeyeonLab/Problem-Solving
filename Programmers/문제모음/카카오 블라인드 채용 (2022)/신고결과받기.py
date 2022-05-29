def solution(id_list, report, k):
    answer = []
    reporter_list = {}  # 유저가 신고한 ID LIST
    respondent_list = {}
    stop_list = []

    for user in id_list:
        reporter_list[user] = []
        respondent_list[user] = []

    for r in report:
        reporter, respondent = r.split()
        if respondent not in reporter_list[reporter]:
            reporter_list[reporter].append(respondent)
        if reporter not in respondent_list[respondent]:
            respondent_list[respondent].append(reporter)

    # k번 이상 신고 당한 ID만 추출
    for respondent_id in respondent_list:
        if len(respondent_list[respondent_id]) >= k:
            stop_list.append(respondent_id)

    for reporter_id in reporter_list:
        count = 0
        for respondent_id in reporter_list[reporter_id]:
            if respondent_id in stop_list:
                count += 1
        answer.append(count)

    return answer