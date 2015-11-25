/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "date.h"
#include <stdio.h>
#include <stdlib.h>

long* bin_date_1_svc(void *argp, struct svc_req *rqstp)
{
	static long  result;
  
	long time();
	result = time((long* )0);
	
	return &result;
}

char** str_date_1_svc(long *bintime, struct svc_req *rqstp)
{
	static char * result;
	
	char* ctime();
	result = ctime(bintime);

	return &result;
}
