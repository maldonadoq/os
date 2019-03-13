#include "values.h"

int main(int argc, char const *argv[]){
	const int SIZE = 4096;
	char message[100];
	int shm_fd;
	void *ptr;

	while(1){		
		const char *name = "os";				

		printf("data: ");
		if(scanf("%s",message)){};

		ptr = NULL;
		shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

		if(ftruncate(shm_fd,SIZE)){};

		ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
		if (ptr == MAP_FAILED) {
			printf("map failed\n");
			return -1;
		}

		sprintf(ptr,"%s",message);
		ptr += strlen(message);
	}	
	return 0;
}