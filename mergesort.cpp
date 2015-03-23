#include<iostream>
using namespace std;

void mergesort(int *tab, int tsize, int mid)
{
    int i=0;
    int *merged=new int[tsize];
    int left=0, right=mid;
    while(left<mid && right<tsize)
    {
        if(tab[left]<=tab[right])
        {
            merged[i]=tab[left];
            left++;
            i++;
        }
        else
        {
            merged[i]=tab[right];
            right++;
            i++;
        }
    }
    while(left<mid)
    {
        merged[i]=tab[left];
        left++;
        i++;
    }
    while(right<tsize)
    {
        merged[i]=tab[right];
        right++;
        i++;
    }
    for(int j=0; j<tsize; j++)
        tab[j]=merged[j];
}

void merge1(int *tab, int tsize)
{
    if(tsize==1)
        return;
    int mid=tsize/2;
    merge1(tab, mid);
    merge1(tab+mid, tsize-mid);
    mergesort(tab, tsize, mid);

}
int main()
{
    int n;
    cout<<"enter the size on an array"<<endl;
    cin>>n;
    int *tab=new int[n];

    cout<<endl<<"enter the elements of an array"<<endl;
    for(int i=0; i<n; i++)
        cin>>tab[i];

    merge1(tab, n);

    cout<<endl<<"this is the result of using mergesort:"<<endl<<endl;
    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";

    cout<<endl;

    return 0;
}
