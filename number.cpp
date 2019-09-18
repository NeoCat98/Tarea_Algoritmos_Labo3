#include <iostream>
#include <string>

using namespace std;


void heapify(int A[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n and A[l]<A[largest]){
        largest = l;
    }
    if(r<n and A[r]<A[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(A[i],A[largest]);
        heapify(A,n,largest);
    }
}

void printHeapify(int A[],int n){
    for(int j=0;j<n;j++){
        cout<<"print="<<A[j]<<" ";
    }
}

void heapSort(int A[],int n){
    for(int i = (n/2-1); i>=0;i--){
        heapify(A,n,i);
    }

    for(int i =(n-1); i >= 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}


int missingNumber(int A[],int n){
    heapSort(A,n);
    if(A[0]%2==0){
        return A[0]+2;
    }
    else{
        return A[0]+1;
    }
}

int main()
{
    int T;
    cout<< "Ingrese la cantidad de casos de prueba(T): "<<endl;
    cin>>T;
    int number[T];
    for(int i=0; i<T ; i++){
        int n;
        cout<<"Ingrese el longitud del arreglo(N): "<<endl;2
        cin>>n;
        int A[n];
        cout<<"Ingrese los valores del arreglo separados por espacio: "<<endl;
        for(int j=0;j<n;j++){
            cin>>A[j];
        }
        number[i] = missingNumber(A,n);
    }
    for(int i=0;i<T;i++){
        cout<<"Resultado para la prueba "<<i+1<<": "<<number[i]<<endl;
    }
    return 0;
}
