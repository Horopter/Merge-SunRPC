/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "mergesort.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
mergeproc_1(merge_in *argp, merge_out *clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, mergeproc,
		(xdrproc_t) xdr_merge_in, (caddr_t) argp,
		(xdrproc_t) xdr_merge_out, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
deleteproc_1(deleteElm *argp, merge_out *clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, deleteproc,
		(xdrproc_t) xdr_deleteElm, (caddr_t) argp,
		(xdrproc_t) xdr_merge_out, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
searchproc_1(key *argp, position *clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, searchproc,
		(xdrproc_t) xdr_key, (caddr_t) argp,
		(xdrproc_t) xdr_position, (caddr_t) clnt_res,
		TIMEOUT));
}