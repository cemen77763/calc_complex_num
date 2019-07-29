struct complexNumber
{
	float realPart;
	float imagePart;
};

void Mul(struct complexNumber first, struct complexNumber second, struct complexNumber* result){
	result->realPart = first.realPart*second.realPart - first.imagePart*second.imagePart;
	result->imagePart = first.realPart*second.imagePart + first.imagePart*second.realPart; 
}