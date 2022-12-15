# Libraries
import random
import numpy as np
import math
# Files
import file
from data import getData
from common import func as commonFunc
from genetic_algorithm import partial_mapped_crossover as algorithm

# Hằng số
NUMBER_OF_TRUCKS = 3
NUMBER_OF_DRONES = 3
TRUCK_SPEED = 30  # km/h
DRONE_SPEED = TRUCK_SPEED * 1.5
DRONE_LIMIT_TIME = 15  # phút
N = 6  # Lấy dữ liệu từ dòng số 6
LIMITED_GENS = 50  # Số lượng gen giới hạn

# Lấy mảng chứa các dòng dữ liệu trong file
lines = file.readFollowingLines(N)

# Khởi báo các biến
numberOfTrucks = NUMBER_OF_TRUCKS  # số lượng xe tải
numberOfCustomers = len(lines)  # số lượng khách hàng + 1
numberOfDrones = NUMBER_OF_DRONES  # số lượng drone
customerX = []  # Lưu trữ hoành độ của các khách hàng
customerY = []  # Lưu trữ tung độ của các khách hàng
releaseDate = []  # Lưu thời gian sản phẩm sẵn sàng của các khách hàng
vector = []  # vector nối các depot với các vị trí khách hàng
angles = np.zeros((numberOfCustomers, numberOfCustomers)
                  )  # chứa góc các vector với nhau
# mảng chứa thời gian ước lượng từ gốc depot đến vị trí các khách hàng (phút)
timeOfDepotToCustomer = []
# Mảng chứa thời gian bay của drone đến các vị trí khách hàng
# Nếu vị trí khách hàng nằm ngoài khoảng bay được của drone -> gán -1
timeDepotToCusByDrone = []
# mảng chứa tổng thời gian từ depot đến vị trí khách hàng và release date
heuristicTime = [0]
# Trung bình (Thời gian từ depot đến vị trí các khách hàng + release date)
averageOfHeuristicTime = 0
# Mảng chứa vị trí các khách hàng đến thăm của từng xe tải
destination = []
# Mảng chứa điểm đến của các xe tải
truckDestinations = [[]]
# Phương sai
variance = 0


# Khởi tạo các biến
for line in lines:
    lineNum = line.split()
    customerX.append(int(lineNum[0]))
    customerY.append(int(lineNum[1]))
    releaseDate.append(int(lineNum[-1]))
    vector.append([customerX[-1] - customerX[0], customerY[-1] - customerY[0]])

# khởi tạo mảng chứa thời gian bay của drone
for arr in vector:
    # Tính khoảng cách theo eclip
    distance = math.sqrt(arr[0] * arr[0] + arr[1] * arr[1])
    # Tính thời gian
    time = distance / DRONE_SPEED * 60  # đổi ra phút
    # Kiểm tra giới hạn bay
    if (time <= DRONE_LIMIT_TIME):
        timeDepotToCusByDrone.append(time)
    else:
        timeDepotToCusByDrone.append(-1)

# Khởi tạo mảng các góc giữa các vector


def getAngle(v1, v2):
    numerator = v1[0] * v2[0] + v1[1] * v2[1]
    denominator = math.sqrt(v1[0] * v1[0] + v1[1] * v1[1]) * \
        math.sqrt(v2[0] * v2[0] + v2[1] * v2[1])
    cos = round(numerator/denominator, 10)
    angle = math.degrees(math.acos(cos))
    return angle if angle >= 0 else angle + 360


for i in range(1, numberOfCustomers):
    for j in range(i, numberOfCustomers):
        angles[i][j] = getAngle(vector[i], vector[j])
        angles[j][i] = angles[i][j]

# Khởi tạo mảng chứa thời gian ước lượng từ gốc depot đến vị trí các khách hàng
for i in range(1, numberOfCustomers):
    # tính khoảng cách theo Manhattan
    distance = abs(customerX[i] - customerX[0]) + \
        abs(customerY[i] - customerY[0])
    # append thời gian
    timeOfDepotToCustomer.append(
        distance/TRUCK_SPEED * 60)  # đổi ra đơn vị phút
    heuristicTime.append(timeOfDepotToCustomer[-1] + releaseDate[i])
    # tính tổng
    averageOfHeuristicTime += heuristicTime[-1]

# Khời tạo giá trị trung bình
averageOfHeuristicTime /= NUMBER_OF_TRUCKS
# Khởi tạo phương sai
variance = averageOfHeuristicTime / 5

# chuyển đổi list sang array
customerX = np.array(customerX)
customerY = np.array(customerY)
releaseDate = np.array(releaseDate)
vector = np.array(vector)

# Lấy 1 vị trí khách hàng ngẫu nhiên
customerLocation = random.randint(1, numberOfCustomers - 1)

# Lặp từ phần tử đầu đến kế cuối,
# Vì khi đến phần tử cuối là đã sắp xếp thành công


def getCustomerList(arr):
    # Khởi tạo vị trí khách hàng
    location = []
    for i in range(0, numberOfCustomers):
        location.append(i)
    # Hoán đổi vị trí
    for i in range(0, numberOfCustomers):
        for j in range(i + 1, numberOfCustomers):
            if (arr[i] > arr[j]):
                # Hoán đổi giá trị
                tmp = arr[i]
                arr[i] = arr[j]
                arr[j] = tmp
                # hoán đổi vị trí
                tmp = location[i]
                location[i] = location[j]
                location[j] = tmp
    return location


# Sắp xếp vị trí các khách hàng theo góc quay từ bé đến lớn
locations = getCustomerList(angles[customerLocation])

# Cập nhật mảng đích đến
count = NUMBER_OF_TRUCKS - 1
lastIndex = 1
for i in range(1, numberOfCustomers):
    if (count > 0):
        sum = 0
        for j in range(lastIndex, i + 1):
            sum += heuristicTime[locations[j]]
        if (abs(sum - averageOfHeuristicTime) <= variance):
            for k in range(lastIndex, i + 1):
                destination.append(locations[k])
            lastIndex = i + 1
            destination.append(-1)
            count -= 1

for k in range(lastIndex, numberOfCustomers):
    destination.append(locations[k])
print(destination)

# Cập nhật mảng 2 chiều chứa các điểm đến của từng xe
for location in destination:
    if (location != -1):
        truckDestinations[-1].append(location)
    else:
        truckDestinations.append([])

print(truckDestinations, '\n')

# Thiết lập mảng chứa các đoạn gen chưa hoàn chỉnh
subGensTable = []
for i in range(NUMBER_OF_TRUCKS):
    subGensTable.append(commonFunc.getAllPermutations(truckDestinations[i]))

# Thiết lập mảng chứa các gen hoàn chỉnh
print("=== Bảng gen ===")
gensTable = []
for i in range(LIMITED_GENS):
    # Khởi tạo từng gen
    gensTable.append([])
    for subgen in subGensTable:
        # Lấy ngẫu nhiên 1 đoạn gen
        randomIndex = random.randint(0, len(subgen) - 1)
        # Đẩy vào đoạn gen chưa hoàn chỉnh
        gensTable[-1] += subgen[randomIndex] + [-1]
    # Loại bỏ -1 ở cuối mảng
    gensTable[-1].pop()
    # show từng dòng
    print(gensTable[-1])

# Tạo bảng gen mới
newGensTable = []
for i in range(LIMITED_GENS):
    # Lấy ngẫu nhiên 2 gen trong bảng gen
    nextIndex = random.randint(0, LIMITED_GENS - 1)
    while (nextIndex == i):
        nextIndex = random.randint(0, LIMITED_GENS - 1)
    # Lai ghép tạo gen mới
    newGens = algorithm.PMX_crossover(
        gensTable[i], gensTable[nextIndex])
    newGensTable.append(newGens[0])
    newGensTable.append(newGens[1])

print("\n=== Bảng gen mới ===")
for gen in newGensTable:
    print(gen)
