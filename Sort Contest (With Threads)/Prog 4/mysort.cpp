#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

const int TOTAL_NUMBERS = 1000000;
const int NUM_THREADS = 16;
const int SECTION_SIZE = TOTAL_NUMBERS / NUM_THREADS;

unsigned long long global_swaps = 0;
mutex locker;
int* numbers = new int[TOTAL_NUMBERS];

// Bubble sort on a vector passed by reference
void bubble(int start, int end, int ThreadID) {
    unsigned long long local_swaps = 0;
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                local_swaps++;
            }
        }
    }
    locker.lock();
    global_swaps += local_swaps;
    locker.unlock();

    cout << "Process " << ThreadID << " swap count:" << local_swaps << endl;
}


void merge(int *merged, int *left, int lSize, int *right, int rSize) {
    int i = 0, j = 0, k = 0;
    while (i < lSize && j < rSize) {
        if (left[i] <= right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }
    while (i < lSize) merged[k++] = left[i++];
    while (j < rSize) merged[k++] = right[j++];
}


int main(int argc, char *argv[]) {
    ifstream numfile(argv[1]); // Open input file

    // Read numbers from file into stack
    for (int i = 0; i < TOTAL_NUMBERS; i++) {
        numfile >> numbers[i];
    }
    numfile.close(); // Close input file

    cout << "Starting bubble sort with " << TOTAL_NUMBERS << " numbers" << endl;

    thread threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int start = i * SECTION_SIZE;
        int end = (i + 1) * SECTION_SIZE;
        threads[i] = thread(bubble, start, end, i + 1);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }

    cout << "Finished bubble sort on all sections." << endl;

    int sections = NUM_THREADS;
    int size = SECTION_SIZE;

    while (sections > 1) {
        for (int i = 0; i < sections / 2; ++i) {
            int* merged = new int[size * 2];
            int* left = &numbers[i * size * 2];
            int* right = &numbers[i * size * 2 + size];
            merge(merged, left, size, right, size);

            for (int j = 0; j < size * 2; ++j) {
                numbers[i * size * 2 + j] = merged[j];
            }
            delete[] merged;
        }
        sections /= 2;
        size *= 2;
    }

    ofstream outfile(argv[2]); // Open output file
    
    // Write sorted numbers to output file
    for (int i = 0; i < TOTAL_NUMBERS; i++) {
        outfile << numbers[i] << endl;
    }

    outfile.close(); // Close output file
    cout << "Output written to " << argv[2] << endl;
    cout << "Total Swaps: " << global_swaps << endl;

    delete[] numbers;
    return 0;
}
