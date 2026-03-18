#include"Heap.h"

int main()
{
	int a[]={4,3,4,5,6,888,999,46,5363,243,33,2}
	HP hp;
		HPInit(&hp);
		for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
		{
			HPPush(&hp, a[i]);
		}
		//利用判空进行打印
		while (!HPEmpty(&hp))
		{
			printf("%d", HPTop(&hp));
			HPPop(&hp);
		}

		////找出最小的前k个
		//int k = 0;
		//scanf("%d", &k);
		//while (k--)
		//{
		//	printf("%d ", HPTop(&hp));
		//	HPPop(&hp);
		//}
		HeapDestory(&hp);
		//建堆
		/*for (int i = 1; i < n; i++)
		{
			AdjustUp(a, i);
		}*/

		return 0;
}
