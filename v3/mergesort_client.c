/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "mergesort.h"


void
merge_prog_1(char *host)
{
	CLIENT *clnt;
	enum clnt_stat retval_1;
	merge_out result_1;
	merge_in  mergeproc_1_arg;
	enum clnt_stat retval_2;
	merge_out result_2;
	deleteElm  deleteproc_1_arg;
	enum clnt_stat retval_3;
	position result_3;
	key  searchproc_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, merge_prog, merge_vers, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	retval_1 = mergeproc_1(&mergeproc_1_arg, &result_1, clnt);
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_2 = deleteproc_1(&deleteproc_1_arg, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_3 = searchproc_1(&searchproc_1_arg, &result_3, clnt);
	if (retval_3 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	merge_prog_1 (host);
exit (0);
}
