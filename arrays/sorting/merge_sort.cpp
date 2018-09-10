#include<iostream>
using namespace std;

void merge(int *p, int start, int middle, int end){
    int i = 0;
    int j = 0;

    int track = start;

    int L[middle-start+1];
    int R[end-middle];

    for(int k=start; k<=middle; k++){
        L[k-start] = p[k];
    }

    for(int k=middle+1; k<=end; k++){
        R[k-middle-1] = p[k];
    }

    while(i<sizeof(L)/sizeof(L[0]) && j<sizeof(R)/sizeof(R[0])){
        if(L[i] < R[j]){
            p[track] = L[i];
            i++;
            track++;
        }
        else if(L[i] > R[j]){
            p[track] = R[j];
            j++;
            track++;
        }
        //cout << 'g';
    }

    while(i<sizeof(L)/sizeof(L[0])){
        p[track] = L[i];
        i++;
        track++;
    }
    while(j<sizeof(R)/sizeof(R[0])){
        p[track] = R[j];
        j++;
        track++;
    }
}

void mergeSort(int *p, int start, int end){
    if(start < end){
        int middle = (start+end)/2;
        mergeSort(p, start, middle);
        mergeSort(p, middle+1, end);
        merge(p, start, middle, end);
    }
}

int main(){
    int arr[] = {3,6,1,9,8,4,5,10,15,12,14,13};

    mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);

    for(int x: arr){
        cout << x << endl;
    }
}