#include "src/macro.h"
#include <signal.h>

//SIGUSR1	16	Exit	User Signal 1

static pid_t PID;
static int nss;

void sighandler(int signum){
	cout << ".";
	nss--;
	kill(PID,SIGUSR1);
}

int main(int argc, char const *argv[]){	
	cout << "M-PID: " << getpid() << endl;
	cout << "P-PID: "; cin >> PID;

	nss = ns;

	kill(PID,SIGUSR1);
	signal(SIGUSR2, sighandler);	
	while(true and nss>0){};
	cout << endl;

	return 0;
}
