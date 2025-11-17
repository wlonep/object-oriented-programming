#include <iostream>
#include "ArrayDataSmart.h"
#include "CMyPoint.h"

using namespace std;

template<typename T>
void print_array(const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

template<>
void print_array(const char* arr, size_t N) {
    cout << arr << endl;
}

template<typename T, size_t N>
void show_array(T(&arr)[N]) {
    for (size_t i = 0; i < N; i++)
        cout << arr[i] << endl;
}

template<typename T, size_t N>
void sortAsc(T(&arr)[N]) {
    for (size_t i = 0; i < N - 1; i++) {
        for (size_t j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<size_t N>
void sortAsc(CMyPoint(&arr)[N]) {
    for (size_t i = 0; i < N - 1; i++) {
        for (size_t j = i + 1; j < N; j++) {
            if (arr[i].x > arr[j].x) {
                CMyPoint temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() {
    /*ArrayDataSmart arr(5);
    arr.addElement(10.1);
    arr.addElement(10.2);
    arr.addElement(10.3);
    arr.backup();
    arr.addElement(10.4);
    arr.addElement(10.5);
    cout << "arr: " << arr << endl;

    cout << "restore" << endl;
    arr.restore();
    cout << "arr: " << arr << endl;

    cout << "대입" << endl;
    ArrayDataSmart arr2(2);
    arr2 = arr;
    cout << "arr2: " << arr2 << endl;

    cout << "이동대입" << endl;
    ArrayDataSmart arr3(3);
    arr3 = std::move(arr);
    cout << "arr3: " << arr3 << endl;*/

    /*int arr1[]{1,2,5,4,3};
    double arr2[]{2.1,1.2,3.3};
    string arr3[]{"greenjoa3", "greenjoa1", "greenjoa2"};
    sortAsc(arr1);
    sortAsc(arr2);
    sortAsc(arr3);
    show_array(arr1);
    show_array(arr2);
    show_array(arr3);*/
    /*print_array<int>(arr1, size(arr1));
    print_array(arr2, size(arr2));
    print_array(arr3, size(arr3));*/

    /*CMyPoint arr[]{
        CMyPoint(100, 100), CMyPoint(50, 30),
        CMyPoint(150, 200), CMyPoint(80, 40)
    };
    show_array(arr);*/

    CMyPoint arr[]{ CMyPoint(20,30),CMyPoint(10,20),CMyPoint(40,50) };
    sortAsc(arr);
    show_array(arr);

    return 0;
}