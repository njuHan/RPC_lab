#include <stdio.h>
#include <rpc/rpc.h>
#include <linux/netconf.h>
#include "date.h"

int main(int argc, char** argv)
{
	CLIENT* cl; //rpc handle
	char* server;
	long* lresult;
	char** sresult;
	
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s hostname\n", argv[0]);
		exit(1);
	}
	
	server = argv[1]; //get the name of the server
	
	//create the client handle
	if ( (cl = clnt_create(server, DATE_PROG, DATE_VERS, "UDP")) == NULL )
	{
		//failed
	  clnt_pcreateerror(server);
	  exit(1);
	}
	
	//call the procedure bin date
	if ( (lresult = bin_date_1(NULL, cl)) == NULL )
	{
		//failed
	  clnt_perror(cl, server);
	  exit(1);
	}
	
	printf("time on %s is %ld\n", server, *lresult);
	
	if ( (sresult = str_date_1(lresult, cl)) == NULL)
	{
		//failed
		clnt_perror(cl, server);
		exit(1);
	}
	printf("date is %s\n", *sresult);
	clnt_destroy(cl); //get rid of the handle
	return 0;
	

	
}