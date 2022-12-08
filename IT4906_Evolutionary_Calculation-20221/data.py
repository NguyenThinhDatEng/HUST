# Thư viện
from common.func import getNumber
# Files
from file import readNLines

# Hằng số
N = 4


class Data:
    def __init__(self, DIMENSION, VEHICLE_CAPACITY, NUMBER_OF_VEHICLES, TIME_HORIZON):
        self.DIMENSION = DIMENSION
        self.VEHICLE_CAPACITY = VEHICLE_CAPACITY
        self.NUMBER_OF_VEHICLES = NUMBER_OF_VEHICLES
        self.TIME_HORIZON = TIME_HORIZON


def getData():
    lines = readNLines(N)
    data = Data(getNumber(lines[0]), getNumber(
        lines[1]), getNumber(lines[2]), getNumber(lines[3]))
    return data


def main():
    __name__


if __name__ == '__main__':
    main()
