#include "values.h"

int main(int argc, char const *argv[]){
	const int SIZE = sizeof(struct Box);
	struct Box tmp;
	char tem[10];
	int shm_fd;
	struct Box *ptr;

	const char *name = "os";				

	printf("[data]\n");		
	printf("integer: ");	scanf("%i",&tmp.mi);
	printf("long: ");		scanf("%li",&tmp.ml);
	printf("char: ");		scanf("%s",tem);
	strcpy(tmp.mc, tem);		
	printf("\n");

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);		

	ftruncate(shm_fd,SIZE);

	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("map failed\n");
		return -1;
	}

	//sprintf(ptr,"%s",tmp.mc);
	ptr = &tmp;
	return 0;
}