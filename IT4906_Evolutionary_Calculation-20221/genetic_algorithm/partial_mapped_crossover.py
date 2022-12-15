import random

# Phép lai ánh xạ từng phần (PMX - Partial Mappel Crossover)


def PMX_crossover(parent1, parent2):
    '''
    parent1 and parent2 are lists
    '''
    length = len(parent1)  # Lấy chiều dài gen

    # Creating parameters for random sublist
    firstCrossPoint = random.randint(0, length - 2)
    secondCrossPoint = random.randint(firstCrossPoint + 1, length - 1)

    print('crossPoint', firstCrossPoint, secondCrossPoint)

    # Lấy 2 đoạn của 2 gen
    parent1MiddleCross = parent1[firstCrossPoint:secondCrossPoint]
    parent2MiddleCross = parent2[firstCrossPoint:secondCrossPoint]

    print('parents', parent1MiddleCross, parent2MiddleCross)

    # Tạo 2 gen con tạm thời
    child1 = (parent1[:firstCrossPoint] +
              parent2MiddleCross + parent1[secondCrossPoint:])
    child2 = (parent2[:firstCrossPoint] +
              parent1MiddleCross + parent2[secondCrossPoint:])

    print('children', child1, child2)

    # Gép các số của đoạn gen bị cắt ra theo các cặp tương ứng
    relationsWithDupes = []
    for i in range(len(parent1MiddleCross)):
        relationsWithDupes.append(
            [parent2MiddleCross[i], parent1MiddleCross[i]])

    print('relationsWithDupes', relationsWithDupes)

    relations = []
    for pair in relationsWithDupes:
        for i in range(len(relationsWithDupes)):
            if pair[0] in relationsWithDupes[i] or pair[1] in relationsWithDupes[i]:
                if pair != relationsWithDupes[i]:
                    if pair[0] == relationsWithDupes[i][1]:
                        pair[0] = relationsWithDupes[i][0]
                    else:
                        pair[1] = relationsWithDupes[i][1]
        if pair not in relations and pair[::-1] not in relations:
            if (pair[0] != pair[1]):
                relations.append(pair)

    print('relations', relations)

    # Đối sánh
    # Đoạn gen phía trước
    for i in range(firstCrossPoint):
        val1 = child1[i]
        val2 = child2[i]
        for x in relations:
            if val1 == x[0]:
                child1[i] = x[1]
            if val2 == x[1]:
                child2[i] = x[0]

    # Đoạn gen phía sau
    for i in range(secondCrossPoint, length):
        val1 = child1[i]
        val2 = child2[i]
        for x in relations:
            if val1 == x[0]:
                child1[i] = x[1]
            if val2 == x[1]:
                child2[i] = x[0]
    # Trả về 2 cá thể
    return child1, child2
