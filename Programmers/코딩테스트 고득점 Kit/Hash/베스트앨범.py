def solution(genres, plays):
    answer = []
    tree_map = {}
    hash_map = {}

    for idx in range(len(genres)):
        if genres[idx] not in hash_map:
            hash_map[genres[idx]] = 0
        if genres[idx] not in tree_map:
            tree_map[genres[idx]] = []
        hash_map[genres[idx]] += plays[idx]
        tree_map[genres[idx]].append((plays[idx], idx))

    prior = dict(sorted(hash_map.items(), key=lambda x: x[1], reverse=True))

    for p in prior:
        if len(tree_map[p]) == 1:
            answer.append(tree_map[p][0][1])
        else:
            tree_map[p].sort(key=lambda x: x[0], reverse=True)
            answer.append(tree_map[p][0][1])
            answer.append(tree_map[p][1][1])

    return answer
