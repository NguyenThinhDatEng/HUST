# 10970.8     10970.8     1                       0           0
# 10655.2     10655.2     1           -315.6      -94.68      94.68
# 10829.3     10675.836   0.11853     174.1       -14.046     118.506

import numpy as np

# define variables
data = np.array([10970.8, 10655.2, 10829.3])
smoothing_parameter = 0.3
N = len(data)            # number of days
result = np.zeros(8)  # save the elements in table
predict = np.zeros(N)

# Implementation


def simple_exponential_smoother(pre_smoothed, discount_factor, error):
    smoothed = pre_smoothed + discount_factor * error
    return smoothed


def discount_factor(Q, D):
    return abs(Q / D)


def error(currentData, pre_smoothed):
    return currentData - pre_smoothed


def smoothed_error(error, pre_smoothed_error):
    return smoothing_parameter * error + (1 - smoothing_parameter) * pre_smoothed_error


def deviation(error, pre_deviation):
    return smoothing_parameter * abs(error) + (1 - smoothing_parameter) * pre_deviation


def solve():
    # first data point
    result[1] = result[4] = 1
    result[2] = result[3] = data[0]
    result[6] = result[7] = 0
    predict[0] = result[3]
    # N - 1 next data points
    for i in range(1, N):
        result[5] = error(data[i], result[3])
        # Error
        result[6] = smoothed_error(result[5], result[6])
        # Q
        result[7] = deviation(result[5], result[7])
        # D
        result[4] = discount_factor(result[6], result[7])
        # λ
        result[3] = simple_exponential_smoother(
            result[3], result[4], result[5])
        # Smoothed
        result[2] = data[i]
        result[1] = i
        # Day
        predict[i] = result[3]


def main():
    for val in data:
        print(val)
    print()
    solve()
    for val in predict:
        print(val)


if __name__ == '__main__':
    main()
