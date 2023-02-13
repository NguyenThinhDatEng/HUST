# Thư viện
import re
import itertools
import numpy as np

PERMUTATIONS_LIMIT = 100

# Lấy các số từ chuỗi (Phải có khoảng cách giữa chữ và số)


def getNumber(str):
    # Mảng chứa các số kiểu chuỗi
    numberList = re.findall(r'\b\d+\b', str)
    # Chuổi đổi sang kiểu số
    return int(numberList[0])


def getAllPermutations(array):
    # Mảng chứa tất cả các hoán vị
    output = []
    # Là hoán vị
    subArr = []
    # danh sách các hoán vị
    permutations = itertools.permutations(array)
    # Lấy từng hoán vị
    count = PERMUTATIONS_LIMIT
    for perm in permutations:
        subArr = list(perm)
        output.append(subArr)
        count -= 1
        if (count == 0):
            break
    # Trả về
    return output


def main():
    print(getAllPermutations([1, 2, 3]))


if __name__ == '__main__':
    main()
