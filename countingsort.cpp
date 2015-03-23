#include<iostream>
using namespace std;

/* n - the size of an array;
k - the number such that all keys are from 0 to k-1 */

void countingsort(int *A, int n, int k)
{
    int B[n];
    int C[k];

    for(int i=0; i<k; i++)
        C[i]=0;
    for(int i=0; i<n; i++)
        C[A[i]]++;
    for(int i=1; i<k; i++)
        C[i]=C[i]+C[i-1];
    for(int i=n-1; i>=0; i--)
    {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }

    for(int i=0; i<n; i++)
        A[i]=B[i];
}

int main()
{
    int n, k;
    cout<<"enter the size on an array"<<endl;
    cin>>n;
    int *A=new int[n];

    cout<<"enter the number k such that all the keys are from 0 to k-1"<<endl;
    cin>>k;

    cout<<endl<<"enter the elements of an array"<<endl;
    for(int i=0; i<n; i++)
        cin>>A[i];

    countingsort(A, n, k);

    cout<<endl<<"this is the result of using counting sort:"<<endl<<endl;
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";

    cout<<endl;

    return 0;
}
