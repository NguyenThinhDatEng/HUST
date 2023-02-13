
f = open("C:\\src\\git\\HUST\\IT4906_Evolutionary_Calculation-20221\\solomo\\50\\C101_0.5.dat", "r")
lines = []  # mảng chứa các dòng text trong file

# Đọc cả cả file dữ liệu


def readFile():
    for line in f:
        lines.append(line)
    return lines

# Đọc dữ liệu từ n dòng đầu tiên


def readNLines(n):
    for line in f:
        if (n > 0):
            lines.append(line)
            n -= 1
    return lines

# Đọc dữ liệu từ file kể từ dòng thứ n


def readFollowingLines(n):
    count = 1
    for line in f:
        if (count >= n):
            lines.append(line)
            n -= 1
        else:
            count += 1
    return lines


def main():
    # Đọc file
    readFile()
    # Đóng file
    f.close()


if __name__ == '__main__':
    main()
