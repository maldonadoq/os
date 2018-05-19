#include "src/macro.h"
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static int num;

static pid_t PID;
static int nsr;

void sighandler(int signum){
	//srand(time(NULL));
	num = rand()%10;	

	int fd;
	char s[1];		

	mknod(FIFO_NAME, S_IFIFO | 0666, 0);
	fd = open(FIFO_NAME, O_WRONLY);	
	s[0] = '0'+num;
	write(fd, s, sizeof(s));
	close(fd);

	cout << num << " ";
	nsr++;

	kill(PID,SIGUSR2);
}	

int main(int argc, char const *argv[]){			
	
	cout << "M-PID: " << getpid() << endl;
	cout << "P-PID: "; cin >> PID;

	nsr = 0;
	signal(SIGUSR1, sighandler);
	while(true and nsr<ns){};
	cout << endl;
	
	unlink(FIFO_NAME);
	return(0);
}
