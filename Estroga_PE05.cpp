#include <iostream>
#include <cmath>

const int MAX_SIZE = 10;

// Function prototypes
void inputData(int num[], int& size);
int findLargest(int num[], int size);
int findSmallest(int num[], int size);
double calculateAverage(int num[], int size);
double calculateVariance(int num[], int size, double average);
double calculateStandardDeviation(double variance);
void output(int largest, int smallest, double average, double standardDeviation, double variance);

// Main function
int main() {
    int num[MAX_SIZE];
    int size = 0;
    double average, variance, standardDeviation;

    std::cout << "Programming Exercise 05\nEzra Aneurin A. Estroga\nBSCS 1 | CMSC 28 (K)\n\n";
    std::cout << "This program will ask the user to input positive or negative numbers and it will proceed to perform basic statistics on these numbers when zero is encountered or it has reached the array's max size, which is 10.The statistics used assumes that the data are from the population.\n\n";
    std::cout << "WARNING! The best accuracy of the program is limited to three-digit number. So please refrain from entering too large numbers.\n\n";

    inputData(num, size);

    int largest = findLargest(num, size);
    int smallest = findSmallest(num, size);
    average = calculateAverage(num, size);
    variance = calculateVariance(num, size, average);
    standardDeviation = calculateStandardDeviation(variance);

    output(largest, smallest, average, standardDeviation, variance);

    return 0;
}

// Function to input data
void inputData(int num[], int& size) {
    std::cout << "\nInput a number (input 0 to stop): ";
    for (int i = 0; i < MAX_SIZE; ++i) {
        while (true) {
            std::cin >> num[i];
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a number: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else if (num[i] == 0) {
                size = i;
                return;
            } else {
                if (size < MAX_SIZE) {
                    size++;
                }
                break;
            }
        }
    }
}

// Function to find the largest number
int findLargest(int num[], int size) {
    int max = num[0];
    for (int i = 1; i < size; ++i) {
        if (num[i] > max) {
            max = num[i];
        }
    }
    return max;
}

// Function to find the smallest number
int findSmallest(int num[], int size) {
    int min = num[0];
    for (int i = 1; i < size; ++i) {
        if (num[i] < min) {
            min = num[i];
        }
    }
    return min;
}

// Function to calculate the average
double calculateAverage(int num[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += num[i];
    }
    return sum / size;
}

// Function to calculate the variance
double calculateVariance(int num[], int size, double average) {
    double sumOfSquares = 0;
    for (int i = 0; i < size; ++i) {
        sumOfSquares += (num[i] - average) * (num[i] - average);
    }
    return sumOfSquares / size;
}

// Function to calculate the standard deviation
double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

// Function to output the results
void output(int largest, int smallest, double average, double standardDeviation, double variance) {
    std::cout << "\nLargest = " << largest << std::endl;
    std::cout << "Smallest = " << smallest << std::endl;
    std::cout << "Average = " << average << std::endl;
    std::cout << "Standard deviation = " << standardDeviation << std::endl;
    std::cout << "Variance = " << variance << std::endl;
}
