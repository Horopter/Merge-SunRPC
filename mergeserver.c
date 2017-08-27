#include<stdlib.h>
#include<stdio.h>
#include<rpc/rpc.h>
#include<pthread.h>
#include"mergesort.h"
static merge_out out;
position p;

void merge(long arr[], int l, int mid, int r)
{
    int i=0, j=0, k;
    int rt =  r - mid;
    int lt = mid - l + 1;
    
    long left[lt], right[rt];

    for (i = 0; i < lt; i++)
        left[i] = arr[l + i];
    for (j = 0; j < rt; j++)
        right[j] = arr[mid + 1+ j];

    i = 0; 
    j = 0; 
    k = l; 

    while (i < lt && j < rt)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < lt)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rt)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
 
void mergesort(long arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = left+(right-left)/2;
        mergesort(arr, left, pivot);
        mergesort(arr, pivot+1, right); 
        merge(arr, left, pivot, right);
    }
}


merge_out* mergeproc_1_svc(merge_in *inp, struct svc_req *rqstp)
{
    int size = 0, i=0;
    int isize = 0, osize = 0;
    long data[200];
    //printf("Variables declared. \n");
    isize = inp -> size;
    //printf("\n isize = %d \n",isize);
    osize = out.size;
    //printf("\n osize = %d \n",osize);
    size = isize+osize;
    //printf("\n size = %d \n",size);
    if(osize != 0) 
    {
        //printf("\n earlier output array : \n");
        for(i = 0; i< osize; i++)
        {
            data[i] = out.output_array[i];
            //printf(" %ld ",data[i]);
        }
    }
    //printf("\n earlier input array : \n");
    for(i = osize; i< size;i++)
    {
        data[i] = inp -> input_array[i-osize];
        //printf(" %ld ",data[i]);
    }
    //printf("\n merged array : \n");
    for(i = 0; i< size; i++)
    {
        //printf(" %ld ", data[i]);
    }       
    mergesort(data,0,size-1);
    for(i = 0; i< size; i++)
    {
        out.output_array[i] = data[i];
    }
    out.size = size;
    //printf("\n mergesorted array : \n");
    for(i = 0; i< size; i++)
    {
        printf(" %ld ", out.output_array[i]);
    }
    return(&out);
}

merge_out * deleteproc_1_svc(deleteElm *inp, struct svc_req *rqstp)
{
	int osize = out.size;
	int i = 0, k = 0, n;
	long data[200];
	for(i=0; i<osize;i++)
	{
		if(out.output_array[i] != inp -> elm)
		{
			data[k] = out.output_array[i];
			k++;
		} 
	}
	n = k;
	out.size = n;
	for(i=0;i<n;i++)
	{
		out.output_array[i] = data[i];
	}
	return(&out);	
}

position * searchproc_1_svc(key * inp, struct svc_req *rqstp)
{
	int osize = out.size;
	int i = 0;
	for(i=0; i<osize; i++)
	{
		if(out.output_array[i] == inp -> elm)
		{
			p.pos = i+1;
			break;
		}
	}
	return(&p);
}
