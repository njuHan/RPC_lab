#include <stdio.h>
#include <stdlib.h>

/*bin_date returns the system time in binary format*/
long bin_date(void)
{
	long timeval;
	long time(); //unix time function, returns time
	
	timeval = time((long* )0);
	return timeval;
	
}

/*str_date convert a binary time into a date string*/
char* str_date(long bintime)
{
	char* ptr;
	char* ctime(); 
	
	ptr = ctime(&bintime);
	return ptr;
}

int main (int argc, char** argv)
{
	long lresult;
	char* sresult;
	if (argc != 1)
	{
		fprintf(stderr, "usage: %s\n", argv[0]);
		exit(1);
	}
	
	lresult = bin_date();
	printf("time is %ld\n", lresult);
	sresult = str_date(lresult);
	printf("data is %s", sresult);
	return 0;
}