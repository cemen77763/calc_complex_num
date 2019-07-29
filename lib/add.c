struct complexNumber
{
	float realPart;
	float imagePart;
};

void Add(struct complexNumber first, struct complexNumber second, struct complexNumber* result){
	result->realPart = first.realPart + second.realPart;
	result->imagePart = first.imagePart + second.imagePart; 
}