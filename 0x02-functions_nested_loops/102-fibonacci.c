#include <stdio.h>
/**
* prints the first 50 nuumbers in fibonacci sequence
* starting with 1 and 2, followed by a new line
* The numbers must be separated by comma, followed by a space , 
* You are allowed to use the standard library
*
* 
*
* Return 0
*/
int main() {

	int i;
	int n=50;

	// initialize first and second terms
	int t1 = 0;
	t2 = 1;

	// initialize the next term (3rd term)
	int nextTerm = t1 + t2;

	// print the first two terms t1 and t2
	printf("%d, %d,\n", t1, t2);

	// print 3rd to nth terms
	for (i = 3; i <= n; ++i)
	{
		printf("%d, ", nextTerm);
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;
	}
return 0;
}
