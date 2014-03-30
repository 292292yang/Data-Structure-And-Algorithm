/*******************************
		   ��������
Author:��ͤ���� Date:2014-02-28
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>

void Quick_Sort(int *,int,int);
int findPoss(int *,int,int);

int main()
{
	int num; 
	printf("�����������Ԫ�صĸ�����");
	scanf("%d",&num);

	int i;
	int *arr = (int *)malloc(num*sizeof(int));
	printf("������������%d��Ԫ�أ�����Ϊ��������",num);
	for(i=0;i<num;i++)
		scanf("%d",arr+i);

	printf("����������˳��");
	Quick_Sort(arr,0,num-1);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}

/*
������������ͨ���ݹ�ʵ��
*/
void Quick_Sort(int *a,int low,int high)
{
	int pos;

	if(low < high)
	{
	   pos = findPoss(a,low,high);
	   Quick_Sort(a,low,pos-1);		//�������������
	   Quick_Sort(a,pos+1,high);	//�ұ����������� 
	}
}

/*
�ú������طָ����ֵ���ڵ�λ��,aΪ������������׵�ַ��
low�տ�ʼ��ʾ����Χ�ڵĵ�һ��Ԫ�ص�λ�ã��������ƶ���
high�տ�ʼ��ʾ����Χ�ڵ����һ��λ�ã��������ƶ�
*/
int findPoss(int *a,int low,int high)
{
	int val = a[low];
	while(low < high)
	{
	   while(low<high && a[high]>=val)
	      high--;
	   a[low] = a[high];

	   while(low<high && a[low]<=val)
	      low++;
	   a[high] = a[low];	     
	}

	//����low=high
	a[low] = val;
	return low;
}
