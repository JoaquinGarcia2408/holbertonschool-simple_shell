#include <stdio.h>
#include <unistd.h>

int main(void)
	
{
	pid_t parent_id;

	parent_id = getppid();
	printf("%d\n",parent_id);
	return (0);
}
