// Intentionally destroy EDC and ECC of TSUGARU_OS.mdf

#include <stdio.h>


int main(int ac,char *av[])
{
	FILE *ifp=fopen(av[1],"rb");
	if(NULL!=ifp)
	{
		FILE *ofp=fopen(av[2],"wb");
		if(NULL!=ofp)
		{
			unsigned char buf[2352];
			while(2352==fread(buf,1,2352,ifp))
			{
				for(int i=2064; i<2352; ++i)
				{
					buf[i]=0;
				}
				fwrite(buf,1,2352,ofp);
			}
			fclose(ofp);
		}
		else
		{
			printf("Error opening output.\n");
			return 1;
		}
		fclose(ifp);
	}
	else
	{
		printf("Error opening input.\n");
		return 1;
	}
	return 0;
}
