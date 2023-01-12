import random

# Phép lai ánh xạ từng phần (PMX - Partial Mappel Crossover)


def PMX_crossover(parent1, parent2, drone1, drone2):
    '''
    parent1 and parent2 are lists
    '''
    parent1 = standardized_gene(parent1, 0)
    parent2 = standardized_gene(parent2, 0)
    # print()
    print("Parent 1: ", parent1)
    print("Parent 2: ", parent2)

    length = len(parent1)  # Lấy chiều dài gen

    # Creating parameters for random sublist
    firstCrossPoint = 4  # random.randint(0, length - 2)
    secondCrossPoint = 9  # random.randint(firstCrossPoint + 1, length - 1)

    print()
    print('First cross point: ', firstCrossPoint,
          '\nSecond cross point: ', secondCrossPoint)
    print()

    # Lấy 2 đoạn của 2 gen
    parent1MiddleCross = parent1[firstCrossPoint:secondCrossPoint]
    parent2MiddleCross = parent2[firstCrossPoint:secondCrossPoint]

    drone1MiddleCross = drone1[firstCrossPoint:secondCrossPoint]
    drone2MiddleCross = drone2[firstCrossPoint:secondCrossPoint]

    print('Middle gene 1: ', parent1MiddleCross)
    print('Middle gene 2: ', parent2MiddleCross)
    print()

    # print('parentMiddleCross', parent1MiddleCross, parent2MiddleCross)

    # Create 2 temporary sub genes
    child1 = (parent1[:firstCrossPoint] +
              parent2MiddleCross + parent1[secondCrossPoint:])
    child2 = (parent2[:firstCrossPoint] +
              parent1MiddleCross + parent2[secondCrossPoint:])

    childDrone1 = (drone1[:firstCrossPoint] +
                   drone2MiddleCross + drone1[secondCrossPoint:])
    childDrone2 = (drone2[:firstCrossPoint] +
                   drone1MiddleCross + drone2[secondCrossPoint:])
    print()
    print('Temporary child 1: ', child1, '\nTemporary child 2: ', child2)
    print()

    # Gép các số của đoạn gen bị cắt ra theo các cặp tương ứng
    relationsWithDupes = []
    for i in range(len(parent1MiddleCross)):
        relationsWithDupes.append(
            [parent2MiddleCross[i], parent1MiddleCross[i]])

    print()
    print('Pairs: ', relationsWithDupes)

    # Chọn lọc ra các cặp phục vụ cho việc hoán đổi
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
            if (pair[0] != pair[1] and pair[0] not in parent1MiddleCross and pair[1] not in parent2MiddleCross):
                relations.append(pair)

    print('Good pairs: ', relations)
    print()

    # Đối sánh
    # Đoạn gen phía trước
    for i in range(firstCrossPoint):
        val1 = child1[i]
        val2 = child2[i]
        for x in relations:
            if val1 == x[0]:
                child1[i] = x[1]
                for j in range(firstCrossPoint):
                    if (child2[j] == x[1]):
                        childDrone1[i] = childDrone2[j]
                        break
            if val2 == x[1]:
                child2[i] = x[0]
                for j in range(firstCrossPoint):
                    if (child1[j] == x[0]):
                        childDrone2[i] = childDrone2[j]
                        break

    # Đoạn gen phía sau
    for i in range(secondCrossPoint, length):
        val1 = child1[i]
        val2 = child2[i]
        for x in relations:
            if val1 == x[0]:
                child1[i] = x[1]
                for j in range(secondCrossPoint, length):
                    if (child2[j] == x[1]):
                        childDrone1[i] = childDrone2[j]
                        break
            if val2 == x[1]:
                child2[i] = x[0]
                for j in range(secondCrossPoint, length):
                    if (child1[j] == x[0]):
                        childDrone2[i] = childDrone2[j]
                        break
    # print()
    # print('Child 1: ', child1, '\nChild 2: ', child2)
    # print()

    child1 = format_gene(child1)
    child2 = format_gene(child2)

    # Trả về 2 cá thể
    return child1, child2, childDrone1, childDrone2


def standardized_gene(parent, negativeCount):
    for i in range(len(parent)):
        if (parent[i] == -1):
            parent[i] += negativeCount
            negativeCount -= 1
    return parent


def format_gene(child):
    for i in range(len(child)):
        if (child[i] < 0):
            child[i] = -1
    return child


def main():
    print(PMX_crossover([6, 9, 7, 4, -1, 3, 8, -1, 2, 5, 10, 1],
                        [7, 6, 9, -1, 4, 8, 3, 5, 1, -1, 2, 10],
                        [6, 9, 7, -1, 4, 3, 8, -1, 2, 5, 10, 1],
                        [6, 9, 7, -1, 4, 3, 8, -1, 2, 5, 10, 1]))


if __name__ == '__main__':
    main()
