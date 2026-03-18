//实现一个小堆

#include"Heap.h"

//初始化堆
void HPInit(HP* php)
{
	//如果传过来的是空指针，那么php->a这个行为很危险，所以要assert断言来判断
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
//销毁堆
void HPDestory(HP* php)
{
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
//swap交换函数
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//调整(这里面会用swap交换)
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = (child - 1) / 2;
			parent = (parent - 1) / 2;
		}
		else {
			break;
		}
	}
}

//插入堆
void HPPush(HP* php, HPDataType x)
{
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a,sizeof(HPDataType)*newcapacity);
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	//向上调整，使得满足小堆
	AdjustUp(php->a, php->size - 1);
}

//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child<=n)
	{
	if ( child<n && a[child + 1] < a[child])
	{
		child++;
	}

	if (a[parent] > a[child])
	{
		swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
	else {
		break;
	}
	}
}
//堆的删除(要求删除堆顶的数据)
//要交换堆最尾部与根节点，并且删除根节点，然后进行向下调整
void HPPop(HP* php)
{
	assert(php);
	assert(php->size);
	Swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;
	AdjustDown(php->a, php->size - 1, 0);
}
//获取堆的
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size);
	return php->a[0];
}
//判空
//看元素个数，不看是否为空指针因为即使没有了元素，也可能不为空指针
bool HPEmpty(HP* php)
{
	return php->size == 0;
}

//利用上面三个函数实现while循环来打印堆 
