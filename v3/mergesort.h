/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MERGESORT_H_RPCGEN
#define _MERGESORT_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


struct merge_in {
	long input_array[100];
	int size;
};
typedef struct merge_in merge_in;

struct merge_out {
	long output_array[100];
	int size;
};
typedef struct merge_out merge_out;

struct deleteElm {
	long elm;
};
typedef struct deleteElm deleteElm;

struct position {
	int pos;
};
typedef struct position position;

struct key {
	long elm;
};
typedef struct key key;

#define merge_prog 0x31240000
#define merge_vers 1

#if defined(__STDC__) || defined(__cplusplus)
#define mergeproc 1
extern  enum clnt_stat mergeproc_1(merge_in *, merge_out *, CLIENT *);
extern  bool_t mergeproc_1_svc(merge_in *, merge_out *, struct svc_req *);
#define deleteproc 2
extern  enum clnt_stat deleteproc_1(deleteElm *, merge_out *, CLIENT *);
extern  bool_t deleteproc_1_svc(deleteElm *, merge_out *, struct svc_req *);
#define searchproc 3
extern  enum clnt_stat searchproc_1(key *, position *, CLIENT *);
extern  bool_t searchproc_1_svc(key *, position *, struct svc_req *);
extern int merge_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define mergeproc 1
extern  enum clnt_stat mergeproc_1();
extern  bool_t mergeproc_1_svc();
#define deleteproc 2
extern  enum clnt_stat deleteproc_1();
extern  bool_t deleteproc_1_svc();
#define searchproc 3
extern  enum clnt_stat searchproc_1();
extern  bool_t searchproc_1_svc();
extern int merge_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_merge_in (XDR *, merge_in*);
extern  bool_t xdr_merge_out (XDR *, merge_out*);
extern  bool_t xdr_deleteElm (XDR *, deleteElm*);
extern  bool_t xdr_position (XDR *, position*);
extern  bool_t xdr_key (XDR *, key*);

#else /* K&R C */
extern bool_t xdr_merge_in ();
extern bool_t xdr_merge_out ();
extern bool_t xdr_deleteElm ();
extern bool_t xdr_position ();
extern bool_t xdr_key ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MERGESORT_H_RPCGEN */
