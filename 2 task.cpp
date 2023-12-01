#include <iostream>

const int SIZE = 100;
const int MIN_VALUE = -100;
const int MAX_VALUE = 100;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int array[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    std::cout << "Original array: ";
    printArray(array, SIZE);

    int positiveIndex = 0; //для додатних чисел
    int negativeIndex = SIZE - 1; //для від'ємних чисел 
    int zeroIndex = SIZE / 2; //для нулів 

    while (positiveIndex < zeroIndex && negativeIndex > zeroIndex) {
        while (positiveIndex < zeroIndex && array[positiveIndex] <= 0) {
            ++positiveIndex;
        }
        while (negativeIndex > zeroIndex && array[negativeIndex] >= 0) {
            --negativeIndex;
        }
        if (positiveIndex < zeroIndex && negativeIndex > zeroIndex) {
            std::swap(array[positiveIndex], array[negativeIndex]);
            ++positiveIndex;
            --negativeIndex;
        }
    }

    std::cout << "Modified array: ";
    printArray(array, SIZE);

    return 0;
}
