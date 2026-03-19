#include"Heap.h"
//1.
//逐个插入建堆(时间复杂度(n))
/*void test()
{
  HP php;
  HPInit(&php);
  int a[]={1,2,34,3,563,6243,34};
  int n=sizeof(a)/sizeof(size[0]);
  for(int i=0;i<n;i++)
  {
    HPPush(&php,a[i]);
  }
HeapSort(php.a,php.size-1);
}*/
//2.
//向下调整建堆(更推荐这种时间复杂度o(n))
void BuildHeap(HPDataType* a,int n)
{
  //这里n是下标，为什么减1呢？因为i*2+1<=n,如果n是元素个数那么i*2+1<n,则i=(n-2)/2
  for(int i=(n-1)/2;i>=0;i--)
{
  AdjustDown(a,n,i);//为什么传i呢，因为这里i是每一个子树的根，从子树的根向下比
}
}
//排序
void HeapSort(HPDataType* a,int n)
{
  int end=n;
  while(end>0)
  {
    Swap(&a[0],&a[end]);
    end--;
    AdjustDown(a,end,0);
  }
  }
