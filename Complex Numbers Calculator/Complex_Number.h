#pragma once
class Complex_Number
{
private:
	int Rel;
	int Im;
public:
	int getIm()
	{
		return Im;
	}
	int getRel()
	{
		return Rel;
	}
	void setIm(int value)
	{
		Im = value;
	}
	void setRel(int value)
	{
		Rel = value;
	}

};

