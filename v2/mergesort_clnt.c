/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "mergesort.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

merge_out *
mergeproc_1(merge_in *argp, CLIENT *clnt)
{
	static merge_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, mergeproc,
		(xdrproc_t) xdr_merge_in, (caddr_t) argp,
		(xdrproc_t) xdr_merge_out, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

merge_out *
deleteproc_1(deleteElm *argp, CLIENT *clnt)
{
	static merge_out clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, deleteproc,
		(xdrproc_t) xdr_deleteElm, (caddr_t) argp,
		(xdrproc_t) xdr_merge_out, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

position *
searchproc_1(key *argp, CLIENT *clnt)
{
	static position clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, searchproc,
		(xdrproc_t) xdr_key, (caddr_t) argp,
		(xdrproc_t) xdr_position, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
