#include <iostream>

using namespace std;

#define M 100

struct Vector {
    int N; //The current number of elements in a[].
    int Max = M; //The maximum number of elements allocated to a[].(capacity)
    int *a;
};

void InitVector(Vector& v) { //Similar to vector<int> v.
    v.N = 0;
    v.Max = M;
    v.a = new int[v.Max];
}

void InitVector(Vector& v, int num) { //Similar to vector<int> v(n).
    if (num < M) {
        v.N = num;
        v.Max = M;
    }
    if (num > M) {
        v.Max = num + 1;
        v.N = num;
    }
    v.a = new int[v.Max];
    for (int i = 0; i < v.N; i++) {
        v.a[i] = NULL;
    }
}

void InitVector(Vector& v, int num, int val) { //Similar to vector<int> v(n, value).
    if (num < M) {
        v.N = num;
        v.Max = M;
    }
    if (num > M) {
        v.Max = num + 1;
        v.N = num;
    }
    v.a = new int[v.Max];
    for (int i = 0; i < v.N; i++) {
        v.a[i] = val;
    }
}

void AssignVector(Vector& v, int num, int val) { //Similar to v.assign(n,value).
    InitVector(v, num, val);
}

void ResizeVector(Vector& v, int num) { //Similar to v.resize(n).
    int *arr = new int[num];
    if (v.N == num){
        return;
    }
    if (num > v.Max) {
        v.Max = num + 1;
        for (int i = v.N; i < num; i++) {
            v.a[i] = NULL;
        }
        v.N = num;
    }
    if (num > v.N && num < v.Max) {
        for (int i = v.N; i < num; i++) {
            v.a[i] = NULL;
        }
        v.N = num;
    }
    if (num < v.N) {
        for (int i = 0; i < num; i++) {
            arr[i] = v.a[i];
        }
        delete[] v.a;
        v.a = arr;
        v.N = num;
    }
}

int SizeVector(Vector& v) { //Similar to v.size().
    return v.N;
}

int CapacityVector(Vector& v) { //Similar to v.capacity(). 
    return v.Max;
}

bool EmptyVector(Vector &v) { //Similar to v.empty().
    return v.N == 0;
}

int FrontVector(Vector &v) { //Similar to v.front().
    return v.a[0];
}

int BackVector(Vector& v) { //Similar to v.back();.
    return v.a[v.N - 1];
}

void Push_BackVector(Vector &v,int val) { //Similar to v.push_back(value).
    if (EmptyVector(v)) {
        v.N++;
        v.a[0] = val;
        return;
    }
    if (v.N == v.Max) {
        v.Max = v.Max + 1;
        v.N = v.N + 1;
    }
    v.N++;
    v.a[v.N - 1] = val;
}

void InsertVector(Vector& v, int index, int val) { //Similar to v.insert(position, value).
    if (index > v.N - 1) {
        return;
    }
    if (index == v.N - 1) {
        Push_BackVector(v, val);
        return;
    }
    if (v.N == v.Max) {
        v.Max = v.Max + 1;
        v.N = v.N + 1;
    }
    v.N++;
    for (int i = v.N; i >= index; i--) {
        v.a[i] = v.a[i - 1];
    }
    v.a[index] = val;
}

void Pop_BackVector(Vector &v) { //Similar to  v.pop_back().
    if (EmptyVector(v)) {
        return;
    }
    v.N--;
}

void EraseVector(Vector &v, int index) { //Similar to v.erase(position).
    if (EmptyVector(v)) {
        return;
    }
    if (index > v.N - 1) {
        return;
    }
    if (index == v.N - 1) {
        Pop_BackVector(v);
        return;
    }
    v.N--;
    int i;
    for (i = 0; i < v.N; i++) {
        if (i == index) {
            break;
        }
    }
    for (int j = i; j < v.N; j++)
        v.a[j] = v.a[j + 1];
}

void DisplayVector(Vector &v) { //To display the elements of vector v.
    if (EmptyVector(v)) {
        cout << "Empty Vector!" << endl;
        return;
    }
    cout << "Vector: { ";
    for (int i = 0; i < v.N; i++) {
        cout << v.a[i] << ", ";
    }
    cout << "\b\b" << " }" << endl;
}

int main()
{
    Vector v;
    InitVector(v,25,5);
    DisplayVector(v);
    cout << "The size of the vector is: " << SizeVector(v) << endl;
    ResizeVector(v, 15);
    cout << "The size of the vector after resize is: " << SizeVector(v) << endl;
    cout << "Vector after resize: " << endl;
    DisplayVector(v);
    cout << "The capacity of the vector is: " << CapacityVector(v) << endl;
    AssignVector(v, 17, 9);
    cout << "Vector after assign is: " << endl;
    DisplayVector(v);
    cout << endl << endl;

    Vector x;
    InitVector(x);
    Push_BackVector(x, 5);
    Push_BackVector(x, 4);
    Push_BackVector(x, 10);
    Push_BackVector(x, 3);
    Push_BackVector(x, 8);
    InsertVector(x,3,7);
    DisplayVector(x);
    cout << "The first element is: " << FrontVector(x) << endl;
    cout << "The last element is: " << BackVector(x) << endl;
    Pop_BackVector(x);
    cout << "The last element after pop_back is: " <<BackVector(x) << endl;
    DisplayVector(x);
    EraseVector(x, 3);
    cout << "Display Vector after Erase on index 3: " << endl;
    DisplayVector(x);
    cout << "The size of the vector is: " << SizeVector(x) << endl;   
}