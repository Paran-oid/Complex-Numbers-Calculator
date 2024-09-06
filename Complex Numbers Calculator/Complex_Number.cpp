#include "Complex_Number.h"
#pragma once
int Rel;
int Im;
int Complex_Number::getIm()
{
	return Im;
}
int Complex_Number::getRel()
{
	return Rel;
}
void Complex_Number::setIm(int value)
{
	Im = value;
}
void Complex_Number::setRel(int value)
{
	Rel = value;
}

