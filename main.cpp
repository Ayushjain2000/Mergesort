#include <iostream>
using namespace std;


void Merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int b[100];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
        for(;i<=mid;i++)
        {
            b[k++]=a[i];
        }
        for(;j<=h;j++)
        {
            b[k++]=a[j];
        }

        for(int i=l;i<=h;i++)
        {
            a[i]=b[i];
        }

}
void mergesort(int a[],int n)
{
  int p,l,h,mid,i;
  for(p=2;p<=n;p=p*2)
  {
      for(i=0;i+p-1<n;i=i+p)
      {
          l=i;
          h=i+p-1;
          mid=(l+h)/2;
          Merge(a,l,mid,h);

      }
      if(p/2<n)
        Merge(a,0,p/2-1,n-1);
  }
}

int main()
{  int i;
    int a[]={10,13,5,4,2,8,6,9};

     mergesort(a,8);
    for(i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
