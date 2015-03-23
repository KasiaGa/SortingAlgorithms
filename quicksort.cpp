#include<iostream>
using namespace std;

void quicksort(int *tab, int left, int right)
{
    int i, j, temp, x;
    i=left;
    j=right;
    x=tab[(left+right)/2];
    while(i<=j)
    {
        while(tab[i]<x)
            i++;
        while(tab[j]>x)
            j--;
        if(i<=j)
        {
            temp=tab[j];
            tab[j]=tab[i];
            tab[i]=temp;
            i++;
            j--;
        }
    }

    if(left<j)
        quicksort(tab, left, j);
    if(i<right)
        quicksort(tab, i, right);
}

int main()
{
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int *tab=new int[n];

    cout<<endl<<"enter the elements of an array"<<endl;
    for(int i=0; i<n; i++)
        cin>>tab[i];

    quicksort(tab, 0, n-1);

    cout<<endl<<"this is the result of using quicksort:"<<endl<<endl;
    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";

    cout<<endl;

    return 0;
}
