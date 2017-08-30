#include<stdlib.h>
#include<stdio.h>
#include<rpc/rpc.h>
#include<pthread.h>
#include"mergesort.h"
static merge_out out;
position p;
static count = 0;

void mergeArrays(long *arr1, long *arr2, int n1, int n2, long *arr3, int k)
{
	int i = 0, j = 0;
	while (i<n1 && j <n2)
	{
		if (arr1[i] <= arr2[j])
			arr3[k] = arr1[i++];
		else
			arr3[k] = arr2[j++];
		k++;
	}
	while (i < n1)
	{
		arr3[k] = arr1[i++];
		k++;
	}
	while (j < n2)
	{
		arr3[k] = arr2[j++];
		k++;
	}
}

void merge(long *arr, int l, int mid, int r)
{
	int i=0, j=0, k;
	int rt = r - mid;
	int lt = mid - l + 1;
	long left[lt], right[rt];
	for (i = 0; i < lt; i++)
		left[i] = arr[l + i];
	for (j = 0; j < rt; j++)
		right[j] = arr[mid + 1+ j];
	mergeArrays(left,right,lt,rt,arr,l);
}
 
void mergesort(long *arr, int left, int right)
{
	if (left < right)
	{
		int pivot = left+(right-left)/2;
		mergesort(arr, left, pivot);
		mergesort(arr, pivot+1, right); 
		merge(arr, left, pivot, right);
	}
}

int search(long a[], int lt, int rt, long key)
{
	while (lt <= rt)
	{
		int mid = lt + (rt-lt)/2;
		if (a[mid] == key) 
			return mid; 
		else if (a[mid] > key) 
			rt = mid - 1; 
		else
			lt = mid + 1; 
	}
	return -1; 
}

int keepUnique(long *arr, int n)
{
	if (n==0 || n==1)
		return n;
	int i=0,j = 0;
	for (i=0; i < n-1; i++)
		if (arr[i] != arr[i+1])
			arr[j++] = arr[i]; 
	arr[j++] = arr[n-1];
	return j;
}

bool_t mergeproc_1_svc(merge_in *inp,merge_out *outp, struct svc_req *rqstp)
{
	++count;
	int size = 0, i=0;
	int isize = 0, osize = 0;
	isize = inp -> size;
	osize = out.size;
	size = isize+osize;
	long data[size];
	printf("Thread id = '%ld' started. Call_Id = %d.\n",pthread_self(),count);
	sleep(5);
	mergesort(inp -> input_array,0,isize - 1);
	mergeArrays(inp -> input_array,out.output_array,inp -> size,out.size,data,0);
	size = keepUnique(data,size);
	for(i = 0; i< size; i++)
	{
		out.output_array[i] = data[i];
		outp->output_array[i] = data[i];
	}
	out.size = size;
	outp->size = size;
	printf("Thread id = '%ld' is done. Call_Id = %d.\n",pthread_self(),count);
	return(TRUE);
}

bool_t deleteproc_1_svc(deleteElm *inp,merge_out *outp, struct svc_req *rqstp)
{
	++count;
	int osize = out.size;
	int i = 0, k = 0, n;
	long data[osize];
	printf("Thread id = '%ld' started. Call_Id = %d.\n",pthread_self(),count);
	sleep(5);
	for(i=0; i < osize ;i++)
	{
		if(out.output_array[i] != inp -> elm)
		{
			data[k] = out.output_array[i];
			k++;
		} 
	}
	n = k;
	out.size = n;
	outp->size = n;
	for(i=0;i<n;i++)
	{
		out.output_array[i] = data[i];
		outp->output_array[i] = data[i];
	}
	printf("Thread id = '%ld' is done. Call_Id = %d.\n",pthread_self(),count);
	return(TRUE);	
}

bool_t searchproc_1_svc(key * inp, position * pp, struct svc_req *rqstp)
{
	++count;
	printf("Thread id = '%ld' started. Call_Id = %d.\n",pthread_self(),count);
	sleep(5);
	pp->pos = search(out.output_array,0,out.size-1,inp->elm);
	printf("Thread id = '%ld' is done. Call_Id = %d.\n",pthread_self(),count);
	return(TRUE);
}

int merge_prog_1_freeresult(SVCXPRT *transp,xdrproc_t xdr_result,caddr_t result)
{
	xdr_free(xdr_result,result);
	return(1);
}
