
f = open("C:\\Users\\thinh\\OneDrive\\Tài liệu\\20221\\Tinh toan tien hoa\\Code\\solomo\\10\\C101_0.5.dat", "r")
lines = []  # mảng chứa các dòng text trong file


def readFile():
    # Xử lý dữ liệu được đọc từ file
    for line in f:
        lines.append(line)
    return lines


def main():
    # Đọc file
    readFile()
    # Đóng file
    f.close()


if __name__ == '__main__':
    main()
