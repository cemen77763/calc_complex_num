struct complexNumber
{
	float realPart;
	float imagePart;
};

void Sub(struct complexNumber first, struct complexNumber second, struct complexNumber* result){
	result->realPart = first.realPart - second.realPart;
	result->imagePart = first.imagePart - second.imagePart; 
}