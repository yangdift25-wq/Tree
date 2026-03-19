//求n个数中最大的前k个

#include"Heap.h"

//第一种思路是依次去pop，k次
void max_Heap(HPDataType* a,int n,int k)
{
  for(int i=0;i<k;k++)
  {
    HPPop(a);
  }
}



//第二种思路是创建一个k个元素的小堆，如果剩下的数比堆顶的元素要大，就替代堆顶的位置进入堆(然后向下调整)

//实现第二种思路
void max_Heap(HPDataType* a,int n,int k)
{
  int arr[k];
  for(int i=0;i<k;i++)
  {
    arr[i]=a[i];
  }
  //让arr变成小堆
  for(int i=(k-2)/2;i>=0;i--)
    {
      AdjustDown(a,k-1,0);
  for(int i=k;i<n;i++)
  {
    if(a[i]>arr[0])
    {
      arr[0]=a[i];
      AdjustDown(a,k-1,0);
    }
  }

}
