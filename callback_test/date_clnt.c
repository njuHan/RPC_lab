/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "date.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
bin_date_1(void *argp, long *clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, BIN_DATE,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_long, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
str_date_1(long *argp, char **clnt_res, CLIENT *clnt)
{
	return (clnt_call(clnt, STR_DATE,
		(xdrproc_t) xdr_long, (caddr_t) argp,
		(xdrproc_t) xdr_wrapstring, (caddr_t) clnt_res,
		TIMEOUT));
}
