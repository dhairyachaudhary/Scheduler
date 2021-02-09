/* 
	Name: Dhairya Chaudhary
	Roll_Number: 2019035
*/

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

//TEST SCRIPT 1

int main() {
	pid_t pid;
	pid=fork();

	if (pid>0){
		printf("Child: %d \t Parent: %d\n",pid, getpid());

		if (pid<0){
			errno=22;
			perror("Error");
		}

		long rt=syscall(442,pid,1000000000);

		if (rt==0){
			struct timeval t1,t2;
			gettimeofday(&t1,NULL);
			for(long long i=0;i<1000000000;i++);
				gettimeofday(&t2,NULL);

			printf("\n%lf ms with soft real-time guarantees \n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
		}

		else{
			errno=22;
			perror("Error");
		}

		int status;
		waitpid(-1, &status, 0);

	} 

	else if (pid==0){
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		for(long long i=0;i<1000000000;i++);
			gettimeofday(&t2,NULL);
		printf("\n%lf ms without soft real-time guarantees\n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
	} 

	else {
		errno=11;
		perror("Error");
		exit(1);
	}

	return 0;

}
