// Intentionally destroy EDC and ECC of TSUGARU_OS.mdf

#include <stdio.h>


int main(void)
{

	FILE *ifp=fopen("TSUGARU_OS.mdf","rb");
	if(NULL!=ifp)
	{
		FILE *ofp=fopen("intentionally_broken.mdf","wb");
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
		}
		fclose(ifp);
	}
	else
	{
		printf("Error opening input.\n");
	}
}
