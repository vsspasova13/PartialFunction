#include "ReadFromFile.h"
#include "Arrayy.h"
#include <fstream>

ReadFromFile::ReadFromFile(const MyString& fileName)
{
	this->fileName = fileName;
}

void ReadFromFile::readStrings(std::ifstream& ifs, Vector<MyString>& vect)
{
	int ind=0;
	char ch;
	char buff[1024] = "";
	ifs.read((char*)&ch, 1);
	while (ch != '\0')
	{
		buff[ind] = ch;
		ind++;
		ifs.read((char*)&ch, 1);
	}
	buff[ind] = '\0';
	vect.pushBack(buff);
	//ifs.close();
	
}


PartialFunction* ReadFromFile::handleCase()
{
	short n, t;

	std::ifstream ifs(fileName.c_str(), std::ios::binary);
	if (!ifs.is_open())
	{
		throw std::exception("Couldn't open the file!");
	}

	ifs.read((char*)&n, sizeof(short));
	ifs.read((char*)&t, sizeof(short));
	if (t == 0)n *= 2;

	int* values;
	Factory fact;
	Vector<MyString> vect;

	values = new int[n];
	if(t>=0 &&t<=2){
	ifs.read((char*)values, sizeof(int) * n);}

	Arrayy arr(values, n);
	delete[]values;

	switch (t)
	{
	case 0:
		ifs.close();
		return fact.FunctionByValues(arr.getData(), n);
		break;

	case 1:
		
		ifs.close();
		return fact.FunctionByDefinedValues(arr.getData(), n);
		break;

	case 2:
		
		ifs.close();
		return fact.FunctionByValuesZerosAndOnes(arr.getData(), n);
		break;

	case 3:
		
		for (size_t i = 0; i < n; i++)
		{
			readStrings( ifs, vect);
		}
		ifs.close();
		return fact.MaxFunc(vect, n);
		break;

	case 4:
		
		for (size_t i = 0; i < n; i++)
		{
			readStrings(ifs, vect);
		}
		ifs.close();
		return fact.MinFunc(vect, n);
		break;
	}

}
