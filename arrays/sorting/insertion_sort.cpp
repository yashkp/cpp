#include<iostream>
using namespace std;

void insertionSort(int *p, int n){
    int indexTillSorted=0;

    // for(int i=1; i<n; i++){
    //     int val = (p[i]);
    //     for(int j=0;j<i; j++){
    //         if(*(p+i) < *(p+j)){
    //             for(int k=i; k>j; k--){
    //                 *(p+k) = *(p+k-1);
    //             }
    //             *(p+j) = val;
    //             break;
    //         }
    //     }
    // }

    for(int i=1; i<n; i++){
        int val=p[i];
        int hole=i;
        while(hole>0 && p[hole-1] > val){
            p[hole] = p[hole-1];
            hole--;
        }
        p[hole] = val;
    }
}

int main(){
    int arr[] = {3,6,1,9,8,4,5,10,15,12,14,13};

    insertionSort(arr, sizeof(arr)/sizeof(arr[0]));

    for(int x:arr){
        cout << x << endl;
    }
}