//juggling algorithm
//return type as array 
#include<iostream>

using namespace std;

void usingTemporaryArray(int *arr, int n, int d);
void rotateOneByOne(int *arr, int n, int d);
void reversalAlgorithm(int *arr, int n, int d);

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int d;
    cout << "Enter Value of d: " << endl;
    cin >> d;
    
    //method1: using temporary array
    usingTemporaryArray(arr, n, d);
    
    //method2: rotate one by one
    //rotateOneByOne(arr, n, d);

    //method3: reverse algorithm
    //reversalAlgorithm(arr, n, d);

    for(int x : arr){
        cout << x << " ";
    }
    
    return 0;

}

void usingTemporaryArray(int *arr, int n, int d){
    cout << n << endl;
    int temp[d];

    for(int i=0; i<d; i++){
        temp[i] = arr[i];
    }

    for(int i=0;i<n-d; i++){
        arr[i] = arr[d+i];
    }

    for(int i=n-d;i<n;i++){
        arr[i]=temp[i+d-n];
    }
}

void rotateOneByOne(int *arr, int n, int d){
    for(int i=0; i<d; i++){
        int temp = arr[0];
        for(int j=0; j<n-1; j++){
            arr[j] = arr[j+1];
        }
        arr[n-1] = temp;
    }
}

void reverse(int *arr, int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void reversalAlgorithm(int *arr, int n, int d){
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}