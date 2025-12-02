#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>

// For testing only.

std::vector <unsigned char> ReadBinaryFile(std::string fileName)
{
	std::vector <unsigned char> data;
	std::ifstream ifp(fileName,std::ios::binary);
	if(true==ifp.is_open())
	{
		ifp.seekg(0,std::ios::end);
		auto size=ifp.tellg();
		ifp.seekg(0,std::ios::beg);

		if(0<size)
		{
			data.resize(size);
			ifp.read((char *)data.data(),size);
		}
	}
	return data;
}

int ReturnValue(int r,bool mustFail)
{
	if(true!=mustFail)
	{
		return r;
	}
	else
	{
		return 1-r;
	}
}

int main(int ac,char *av[])
{
	int usedArg=0;
	bool mustFail=false;
	if(0==strcmp(av[1],"-i"))
	{
		mustFail=true;
		usedArg=1;
	}

	auto data1=ReadBinaryFile(av[1+usedArg]);
	auto data2=ReadBinaryFile(av[2+usedArg]);

	int returnValue=1;

	if(0==data1.size() || 0==data2.size())
	{
		fprintf(stderr,"One of the files did not exist or file size is zero.\n");
		return ReturnValue(1,mustFail);
	}

	if(data1.size()!=data2.size())
	{
		fprintf(stderr,"Two files do not match.\n");
		return ReturnValue(1,mustFail);
	}

	for(size_t i=0; i<data1.size(); ++i)
	{
		if(data1[i]!=data2[i])
		{
			fprintf(stderr,"Contents do not match.\n");
			return ReturnValue(1,mustFail);
		}
	}

	return ReturnValue(0,mustFail);
}
