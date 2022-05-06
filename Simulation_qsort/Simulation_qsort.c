#include<stdio.h>
void smp(char* q, char* w,int e)
{
	int r = 0;
	for (r = 0; r < e; r++)
	{
		char r = *q;
		*q = *w;
		*w = r;
		q++;
		w++;
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void My_qsort(void* q, int w, int e,int (*cmp)(void* e1,void* e2))
{
	int r = 0;
	for (r = 0; r < w-1; r++)
	{
		int t = 0;
		for (t = 0; t < w - 1 - r; t++)
		{
			if (cmp((char*)q + t * e, (char*)q + (t + 1) * e) > 0)
			{
				smp((char*)q + t * e, (char*)q + (t + 1) * e,e);
			}
		}
	}
}
int main()
{
	int q[] = { 8,3,6,4,1,9,2,7,5 };
	int w = sizeof(q) / sizeof(q[0]);
	int e = sizeof(q[0]);
	My_qsort(q, w, e, cmp_int);
	int r = 0;
	for (r = 0; r < w; r++)
	{
		printf("%d ", q[r]);
	}
	printf("\n");
	return 0;
}