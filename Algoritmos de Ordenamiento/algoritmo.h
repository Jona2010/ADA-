#include <iostream>
using namespace std;

void insertionSort(int *A, int n) 
{ 
    int i,aux,j; 
    for (i=1;i<n;i++)
	{ 
        aux=A[i]; 
        j=i-1; 

        while(j>=0 && A[j]>aux) 
		{ 
            A[j+1]=A[j]; 
            j=j-1; 
        } 
        A[j+1]=aux; 
    } 
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
   
void bubbleSort(int *A, int n) 
{
  bool swapped=true;
  int j=0;
  int aux;
 
  while (swapped) 
  {
    swapped=false;
    j++;
    for(int i=0;i<n-j;++i) 
	{
      if(A[i]>A[i+1]) 
	  {
        aux = A[i];
        A[i] = A[i + 1];
        A[i + 1] = aux;
        swapped = true;
      }
    }
  }
}


void merge(int *A, int l, int m, int r) 
{ 
    int i, j, k; 
    int x=m-l+1; 
    int y=r-m; 
  
    int L[x], R[y]; 
  
    for (i=0;i<x;i++) 
        L[i] = A[l+i]; 
    for (j=0;j<y;j++) 
        R[j] = A[m+1+j]; 
  
    i=0;
    j=0; 
    k=l; 

    while(i<x && j<y) 
    { 
        if(L[i]<=R[j]) 
        { 
            A[k]=L[i]; 
            i++; 
        } 
        else
        { 
            A[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while(i<x) 
    { 
        A[k]=L[i]; 
        i++; 
        k++; 
    } 
  
    while (j<y) 
    { 
        A[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int *A,int l,int r) 
{ 
    if(l<r) 
    {  
        int m=l+(r-l)/2; 
        
        mergeSort(A,l,m); 
        mergeSort(A,m+1,r); 
  
        merge(A,l,m,r); 
    }
} 

void mergeSort(int *A, int n)
{
    mergeSort(A,0,n-1);
}

int partition(int *A,int start,int end)
{
    int pivot=A[end];
    //P-index indicates the pivot value index
    
    int P_index=start;
    int i,t; //t is temporary variable
    
    //Here we will check if array value is 
    //less than pivot
    //then we will place it at left side
    //by swapping 
    
    for(i=start;i<end;i++)
    {
    	if(A[i]<=pivot)
        {
            t=A[i];
            A[i]=A[P_index];
            A[P_index]=t;
            P_index++;
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=A[end];
      A[end]=A[P_index];
      A[P_index]=t;
    
     //at last returning the pivot value index
     return P_index;
}

void Quicksort(int *A,int start,int end)
{
    if(start<end)
    {
         int P_index=partition(A,start,end);
             Quicksort(A,start,P_index-1);
             Quicksort(A,P_index+1,end);
    }
}

void quicksort(int *A,int n)
{
	Quicksort(A,0,n-1);
}

void heapify(int *A, int len, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && A[left] > A[largest])
        largest = left;

    if (right < len && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        swap(A[i], A[largest]);

        heapify(A, len, largest);
    }
}

void HeapSort(int *A, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(A, len, i);

    for (int i = len - 1; i >= 0; i--)
    {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}


void heapsort(int *A,int len)
{
	HeapSort(A,len);
}





