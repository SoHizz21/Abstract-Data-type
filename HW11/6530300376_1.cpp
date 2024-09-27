#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

void createDataFile(int size) {
    srand(time(0));
    ofstream datafile("data.txt");
    for (int i = 0; i < size; i++)
        datafile << rand() % 10000 << "\n";
    datafile.close();
}

int *readData(int size) {
    int *arr = new int[size];
    string data;
    try {
        ifstream ReadFile("data.txt");
        for (int i = 0; i < size; i++) {
            getline(ReadFile, data);
            stringstream ss(data);
            ss >> arr[i];
            ss.clear();
        }
        ReadFile.close();
    } catch (exception const &e) {
        cout << "There was an error: " << e.what() << endl;
    }
    return arr;
}

void printArrayToFile(const string &filename, int *arr, int size) {
    ofstream file(filename);
    for (int i = 0; i < size; i++)
        file << arr[i] << "\n";
    file.close();
}

void SelectionSort(int *arr, int size) {
    int min;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void BubbleSort(int *arr, int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = size - 1; j >= i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void InsertionSort(int *arr, int size) {
    int j, p, tmp;
    for (p = 1; p < size; p++) {
        tmp = arr[p];
        for (j = p; j > 0 && arr[j - 1] > tmp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

void ShellSort(int *arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int a[], int lpos, int rpos, int rightend) {
    int i, leftend, numelements, tmppos;
    int tmparr[rightend + 1];
    leftend = rpos - 1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;
    while (lpos <= leftend && rpos <= rightend) {
        (a[lpos] <= a[rpos]) ? tmparr[tmppos++] = a[lpos++] : tmparr[tmppos++] = a[rpos++];
    }
    while (lpos <= leftend) {
        tmparr[tmppos++] = a[lpos++];
    }
    while (rpos <= rightend) {
        tmparr[tmppos++] = a[rpos++];
    }
    for (i = 0; i < numelements; i++, rightend--) {
        a[rightend] = tmparr[rightend];
    }
}

void MergeSort(int a[], int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        MergeSort(a, left, center);
        MergeSort(a, center + 1, right);
        merge(a, left, center + 1, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        QuickSort(a, low, pivotIndex - 1);
        QuickSort(a, pivotIndex + 1, high);
    }
}

void RadixSort(int *a, int size) {
    int max = a[0], timesSorted = 0;
    for (int i = 1; i < size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    while (max != 0) {
        ++timesSorted;
        max /= 10;
    }
    queue<int> head[10];
    int mod = 10, div = 1;
    for (int index = 0; index < timesSorted; index++) {
        int headIndex = 0;
        for (int j = 0; j < size; j++) {
            head[a[j] % mod / div].push(a[j]);
        }
        for (int k = 0; k < size; k++) {
            while (head[headIndex].empty()) {
                ++headIndex;
            }
            a[k] = head[headIndex].front();
            head[headIndex].pop();
        }
        mod *= 10;
        div *= 10;
    }
}

void heapify(int a[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && a[l] > a[largest])
        largest = l;
    if (r < N && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, N, largest);
    }
}

void HeapSort(int *a, int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(a, N, i);

    for (int i = N - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int menu() {
    int in1;
    cout << "=========Menu======== " << endl;
    cout << "1) Create data file " << endl;
    cout << "2) Selection Sort" << endl;
    cout << "3) Bubble Sort " << endl;
    cout << "4) Insertion Sort " << endl;
    cout << "5) Shell Sort" << endl;
    cout << "6) Merge Sort" << endl;
    cout << "7) Quick Sort" << endl;
    cout << "8) Radix Sort" << endl;
    cout << "9) Heap Sort" << endl;
    cout << "10) Exit" << endl;
    cout << "Please choose > ";
    cin >> in1;
    return in1;
}

int main() {
    int size = 2000000;
    int *arr = nullptr;

    while (true) {
        switch (menu()) {
            case 1:
                createDataFile(size);
                cout << "Create file success!!" << endl;
                break;
            case 2:
                arr = readData(size);
                SelectionSort(arr, size);
                printArrayToFile("selectionsort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 3:
                arr = readData(size);
                BubbleSort(arr, size);
                printArrayToFile("bubblesort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 4:
                arr = readData(size);
                InsertionSort(arr, size);
                printArrayToFile("insertionsort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 5:
                arr = readData(size);
                ShellSort(arr, size);
                printArrayToFile("shellsort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 6:
                arr = readData(size);
                MergeSort(arr, 0, size - 1);
                printArrayToFile("mergesort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 7:
                arr = readData(size);
                QuickSort(arr, 0, size - 1);
                printArrayToFile("quicksort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 8:
                arr = readData(size);
                RadixSort(arr, size);
                printArrayToFile("radixsort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 9:
                arr = readData(size);
                HeapSort(arr, size);
                printArrayToFile("heapsort.txt", arr, size);
                delete[] arr;
                cout << "Create file success!!" << endl;
                break;
            case 10:
                cout << "Exit!";
                return 0;
            default:
                cout << "Plaese Try Again" << endl;
                break;
        }
    }
    return 0;
}

