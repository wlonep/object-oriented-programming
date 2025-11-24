#include <algorithm>

#include "Student.h"

template<typename T1, typename T2, size_t N>
int search(const T1 (&arr)[N], const T2& query) {
    for (size_t i = 0; i < N; i++) {
        if (arr[i] == query) return static_cast<int>(i);
    }
    return -1;
}

int main() {
    cout << "202211305 박지원" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    int idx1 = search(arr, 3);
    if (idx1 != -1) cout << arr[idx1] << endl;

    string id[3] = {"greenjoa1", "greenjoa2", "greenjoa3"};
    int idx2 = search(id, "greenjoa2");
    if (idx2 != -1) cout << id[idx2] << endl;

    Student std[3] {
        Student("greenjoa1", 70),
        Student("greenjoa2", 50),
        Student("greenjoa3", 80),
    };
    int idx3 = search(std, "greenjoa2");
    if (idx3 != -1) cout << std[idx3] << endl;

    int idx4 = search(std, Student("greenjoa3", 80));
    if (idx4 != -1) cout << std[idx4] << endl;

    return 0;
}