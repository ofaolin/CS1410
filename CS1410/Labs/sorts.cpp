//
//  main.cpp
//  CS1410
//
//  Created by Tyler Phalen on 2/1/22.
//

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

bool validInput = true; //boolean value to check validity of input
int counter = 0; //counter that affects number of input vals
int numList[6]; //master int list, input by user
int tempArr[6]; //temporary array to hold vals for sorting so master is not affected

void randInitArray(int arr[],int len){ //funtion to print the input array
    time_t nTime;
    srand((unsigned) time(&nTime));
    for (int i = 0; i <= len; i++){
        arr[i] = rand() % 999;
    }
    cout << endl << endl;
}

void swap(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;
}

bool validityChecker(int input){ //checks if input is -1
    if (input >= 0 || input <= -2)
        return true;
    else {
        cout << "Please input valid number";
        return false;
    }
}

void getInput() { //function to take 6 ints and puts them into numList, input of -1 will stop
    while (validInput != false && counter <= 5){
        int input;
        cout << "Input a number (-1 to stop): ";
        cin >> input;
        validInput = validityChecker(input);
        if (validInput == true) {
            numList[counter] = input;
            counter++;
        }
    }
    cout << endl;
}

void printArray(int arr[],int len){ //funtion to print the input array
    for (int i = 0; i <= len; i++){
        cout << arr[i];
        if (i < len)
            cout << ", ";
    }
    cout << endl << endl;
}

void arraySwap(int arr[],int len){ //swap master numList into temp array for sorting without affecting original
    for (int i = 0; i <= len; i++){
        tempArr[i] = arr[i];
    }
}

void unsort(){
    arraySwap(numList,5);

    cout << "Unsorting..." << endl << endl;

    printArray(tempArr,5);
}

void bubbleSort(int arr[],int len){ //takes array and sorts ints in ascending order using bubble sort algorithm
    cout << "Initiating Bubble Sort..." << endl << endl;
    int i = len;
    int lastRun = 6;
    bool swapCheck = false;
    do {
        if (arr[i] < arr[i-1]){
            swap(&arr[i],&arr[i-1]);
            swapCheck = true;
            lastRun++;
        }else if (arr[i-1] <= arr[i]) {
            swapCheck = false;
            lastRun--;
        }
        i--;
        if (i == 0)
            i = len;
    } while ((swapCheck == true) || (lastRun != 0));
}

int partition(int arr[],int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    
}

void quickSort(int arr[],int low, int high) { //takes array and sorts ints in ascending order using quick sort algorithm
    if (low < high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int maxVal(int arr[], int n){
    int max = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int m){
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / m) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / m) % 10] - 1] = arr[i];
        count[(arr[i] / m) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n){
    int max = maxVal(arr, n);
    
    for (int m = 1; max / m > 0; m *= 10)
        countingSort(arr, n, m);
}

int main() {
    int n = sizeof(tempArr) / sizeof(tempArr[0]);
    string inp;
    int inp2 = 0;
    string inp3;
    int done = 0;
    
    cout << "Lab: Sorts, by Tyler Phalen" << endl << endl;
    cout << "Would you like to input your own values? (y/n): ";
    cin >> inp;
    
    while (inp != "y" || inp != "n"){
        if (inp == "y"){
            getInput();
            arraySwap(numList, 5);
            break;
        }
        else if (inp == "n"){
            cout << "Continuing with random values...";
            randInitArray(numList,5);
            arraySwap(numList, 5);
            break;
        }
    }
    
    printArray(tempArr, n-1);
    
    while (inp2 != -1){
        cout << "Pick a sort(-1 to quit): Quick Sort(1), Bubble Sort(2), Radix Sort(3): ";
        cin >> inp2;
        switch (inp2) {
            case 1:
                cout << "Initiating Quick Sort..." << endl << endl;
                quickSort(tempArr, 0, n - 1);
                printArray(tempArr,5);
                done++;
                break;
            case 2:
                bubbleSort(tempArr,5);
                printArray(tempArr,5);
                done++;
                break;
            case 3:
                cout << "Initiating Radix Sort..." << endl << endl;
                radixSort(tempArr, n);
                printArray(tempArr,5);
                done++;
                break;
            case -1: cout << "exiting...";
                break;
            default:
                cout << "Please enter a valid selection" << endl;
                inp2 = 0;
        }
        if (done != 0){
            cout << "Would you like to try another sort? (y/n): ";
            cin >> inp3;
            if (inp3 == "y")
                unsort();
            else if (inp3 == "n") {
                cout << "goodbye" << endl;
                break;
            }
            else
                cout << "Please enter valid selection" << endl;
        }
    }
    
}
