#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


struct complexNumber
{
	float realPart;
	float imagePart;
};

int main(void){
	int k;
	int flag = 1;
	void *handleAdd = NULL, *handleSub = NULL, *handleMul = NULL, *handleDiv = NULL;
	void (*add)(struct complexNumber, struct complexNumber, struct complexNumber*) = NULL;
	void (*sub)(struct complexNumber, struct complexNumber, struct complexNumber*) = NULL;
	void (*mul)(struct complexNumber, struct complexNumber, struct complexNumber*) = NULL;
	void (*div)(struct complexNumber, struct complexNumber, struct complexNumber*) = NULL;

	struct complexNumber first;
	struct complexNumber second;
	struct complexNumber result;
	first.realPart = 0; first.imagePart = 0;
	second.realPart = 0; second.imagePart = 0;

	while(flag){
		printf("What do u want? (1:Add, 2:Sub, 3:Mul, 4:Div 5:Save)...");
		scanf("%d", &k);
		switch(k){
			case 1:{
				if (!handleAdd){
					handleAdd = dlopen("./lib/libadd.so", RTLD_NOW);
					if (!handleAdd){
					fprintf(stderr, "%s\n", dlerror());
					exit(EXIT_FAILURE);
					}
					dlerror();
					add = dlsym(handleAdd, "Add");
				}
				break;
			}
			case 2:{
				if (!handleSub){
					handleSub = dlopen("./lib/libsub.so", RTLD_NOW);
					if (!handleSub){
					fprintf(stderr, "%s\n", dlerror());
					exit(EXIT_FAILURE);
					}
					sub = dlsym(handleSub, "Sub");
				}
				break;
			}
			case 3:{
				if (!handleMul){
					handleMul = dlopen("./lib/libmul.so", RTLD_NOW);
					if (!handleMul){
					fprintf(stderr, "%s\n", dlerror());
					exit(EXIT_FAILURE);
					}
					mul = dlsym(handleMul, "Mul");
				}
				break;
			}
			case 4:{
				if (!handleDiv){
					handleDiv = dlopen("./lib/libdiv.so", RTLD_NOW);
					if (!handleDiv){
					fprintf(stderr, "%s\n", dlerror());
					exit(EXIT_FAILURE);
					}
					div = dlsym(handleDiv, "Div");
				}
				break;
			}
			case 5:{
				flag = 0;
				break;
			}
			default: break;
		}
	}
	flag = 1;

	while(flag){

		printf("\nMenu:\n");
		if (handleAdd)
			printf("   1)Add\n");
		if (handleSub)
			printf("   2)Sub\n");
		if (handleMul)
			printf("   3)Mul\n");
		if (handleDiv)
			printf("   4)Div\n");

		printf("   5)Change numbers\n");
		printf("   6)Output\n");
		printf("   7)Ouit\n");

		printf("Choose option...");
		scanf("%d", &k);
		switch(k){
			case 1:{
				if (!handleAdd) break;
				add(first, second, &result);
				printf("   result is: %f + (%fi)\n", result.realPart, result.imagePart);
				break;
			}
			case 2:{
				if (!handleSub) break;
				sub(first, second, &result);
				printf("   result is: %f + (%fi)\n", result.realPart, result.imagePart);
				break;
			}
			case 3:{
				if (!handleMul) break;
				mul(first, second, &result);
				printf("   result is: %f + (%fi)\n", result.realPart, result.imagePart);
				break;
			}
			case 4:{
				if (!handleDiv) break;
				div(first, second, &result);
				printf("   result is: %f + (%fi)\n", result.realPart, result.imagePart);
				break;
			}
			case 5:{
				printf("Input real and image part of first number: ");
				scanf("%f", &first.realPart);
				scanf("%f", &first.imagePart);
				printf("Input real and image part of second number: ");
				scanf("%f", &second.realPart);
				scanf("%f", &second.imagePart);
				break;
			}
			case 6:{
				printf("   result is: %f + (%fi)\n", result.realPart, result.imagePart);
				break;
			}
			case 7:{
				flag = 0;
				break;
			}
			default: break;
		}
	}



	if (handleAdd) dlclose(handleAdd);
	if (handleSub) dlclose(handleSub);
	if (handleMul) dlclose(handleMul);
	if (handleDiv) dlclose(handleDiv);
	exit(EXIT_SUCCESS);
}
