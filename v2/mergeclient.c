#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <rpc/pmap_clnt.h>
#include"mergesort.h"

int main(int argc, char **argv)
{
    CLIENT *cl;
    merge_in in;
    merge_out *outp;
    deleteElm delm;
    position *p;
    key k;
    int i=0,n=0;
    if(argc < 4)
    {
        printf("usage : client <hostname> <command> <integer-value(s)>");
        exit(1);
    }
    cl = clnt_create (argv[1], merge_prog, merge_vers, "tcp");
    if (cl == NULL) 
	{
		clnt_perror(cl, "call failed");
		exit (1);
	}
    if(strcmp(argv[2],"i")==0)
    {	    
	    for(i = 0; i < argc - 3; i++)
	    {
		in.input_array[i] = atol(argv[i+3]);
	    }
	    in.size = argc-3;
	    if((outp = mergeproc_1(&in,cl))==NULL)
	    {
		printf("%s\n",clnt_sperror (cl,argv[1]));
	   	exit(1);
	    }
	    n = outp -> size;
	    for(i = 0; i<n ;i++)
		printf(" %ld ",outp -> output_array[i]);
	    printf("\n");
	    exit(0);
    }
    else if(strcmp(argv[2],"d")==0)
    {
		delm.elm = atol(argv[3]);
		if((outp = deleteproc_1(&delm,cl))==NULL)
		    {
			printf("%s\n",clnt_sperror (cl,argv[1]));
	   		exit(1);
		    }
		n = outp -> size;
		for(i = 0; i<n ;i++)
			printf(" %ld ",outp -> output_array[i]);
		printf("\n");
		exit(0);		
    }
    else if(strcmp(argv[2],"s")==0)
    {
		k.elm = atol(argv[3]);
		if((p = searchproc_1(&k,cl))==NULL)
		    {
			printf("%s\n",clnt_sperror (cl,argv[1]));
	   		exit(1);
		    }
		printf("The required key is at : %d \n",p->pos);
		exit(0);
    }   
	clnt_destroy(cl);
	return 0; 
}
