#include <iostream>
#include <cmath>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int findSecondLargest(int arr[], int size) {
    int firstLargest = arr[0];
    int secondLargest = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < firstLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

void rearrangeArray(int arr[], int size) {
    int temp;
    int i = 0;

    while (i < size) {
        if (arr[i] == i) {
            ++i;
        } else {
            temp = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
        }
    }
}

int main() {
    const int m = 15;
    int array[m] = {2, 1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0};

    // Task 1
    int secondLargest = findSecondLargest(array, m);
    std::cout << "Second largest element: " << secondLargest << std::endl;

    // Task 2
    int lastPositiveIndex = -1;
    for (int i = 0; i < m; ++i) {
        if (array[i] > 0) {
            lastPositiveIndex = i;
        }
    }

    double sumBeforeLastPositive = 0;
    for (int i = 0; i <= lastPositiveIndex; ++i) {
        sumBeforeLastPositive += array[i];
    }

    std::cout << "Sum before last positive element: " << sumBeforeLastPositive << std::endl;

    // Task 3
    const double a = 1.0;
    const double b = 2.0;
    int newSize = m;
    for (int i = 0; i < newSize; ++i) {
        if (fabs(array[i]) >= a && fabs(array[i]) <= b) {
            for (int j = i; j < newSize - 1; ++j) {
                array[j] = array[j + 1];
            }
            --newSize;
            --i;  // Process the same index again, as it is replaced
        }
    }

    for (int i = newSize; i < m; ++i) {
        array[i] = 0;
    }

    std::cout << "Compressed array: ";
    printArray(array, newSize);

    // Task 4
    int minIndex = 0;
    for (int i = 1; i < m; ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }

    double sumBetweenNegatives = 0;
    int firstNegativeIndex = -1;
    int secondNegativeIndex = -1;

    for (int i = 0; i < m; ++i) {
        if (array[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            } else if (secondNegativeIndex == -1) {
                secondNegativeIndex = i;
                break;
            }
        }
    }

    for (int i = firstNegativeIndex + 1; i < secondNegativeIndex; ++i) {
        sumBetweenNegatives += array[i];
    }

    std::cout << "Sum between first and second negatives: " << sumBetweenNegatives << std::endl;

    int temp;
    for (int i = 0; i < m / 2; ++i) {
        temp = array[i];
        array[i] = array[m - i - 1];
        array[m - i - 1] = temp;
    }

    std::cout << "Reversed array: ";
    printArray(array, m);

    // Task 5
    int positiveCount = 0;
    int sumAfterLastZero = 0;
    int lastZeroIndex = -1;

    for (int i = 0; i < m; ++i) {
        if (array[i] > 0) {
            ++positiveCount;
        } else if (array[i] == 0) {
            lastZeroIndex = i;
        }
    }

    for (int i = lastZeroIndex + 1; i < m; ++i) {
        sumAfterLastZero += array[i];
    }

    std::cout << "Count of positive elements: " << positiveCount << std::endl;
    std::cout << "Sum after last zero: " << sumAfterLastZero << std::endl;

    newSize = 0;
    for (int i = 0; i < m; ++i) {
        if (fabs(array[i]) <= 1) {
            temp = array[i];
            array[i] = array[newSize];
            array[newSize] = temp;
            ++newSize;
        }
    }

    for (int i = newSize; i < m; ++i) {
        temp = array[i];
        array[i] = array[newSize];
        array[newSize] = temp;
        ++newSize;
    }

    std::cout << "Transformed array: ";
    printArray(array, m);

    return 0;
}
