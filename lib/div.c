#include <stdio.h>

struct complexNumber
{
	float realPart;
	float imagePart;
};

void Div(struct complexNumber first, struct complexNumber second, struct complexNumber* result){
	if ((second.realPart != 0) && (second.imagePart != 0)){
		result->realPart = (first.realPart*second.realPart + first.imagePart*second.imagePart)/(second.realPart*second.realPart + second.imagePart*second.imagePart);
		result->imagePart = (first.imagePart*second.realPart - first.realPart*second.imagePart)/(second.realPart*second.realPart + second.imagePart*second.imagePart);
	} else printf("\n IMPOSSIBLE \n");
}