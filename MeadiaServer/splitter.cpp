#include <string.h>
#include <memory.h>
#include "stdio.h"
#include<windows.h> 
#include "splitter.h"

namespace Cnvt
{

	unsigned char* GetFirstNalu(unsigned char *pBufIn, int nInSize,  int &nNaluSize)
	{
		unsigned char *p = pBufIn;
		int nStartPos = 0, nEndPos = 0;
		while (1)
		{
			if (p[0] == 0 && p[1] == 0 && p[2] == 1 )
			{
				nStartPos = p - pBufIn;
				break;
			}
			p++;
			if (p - pBufIn >= nInSize - 4)
				return 0;
		}
		p++;
		while (1)
		{
			if (p[0] == 0 && p[1] == 0 && p[2] == 0 && p[3] == 1)
			{
				nEndPos = p - pBufIn;
				break;
			}
			p++;
			if (p - pBufIn >= nInSize - 4)
			{
				nEndPos = nInSize;
				break;
			}
		}
		nNaluSize = nEndPos - nStartPos;
		unsigned char* pNalu = (unsigned char*)malloc(nNaluSize);
		memcpy(pNalu, pBufIn + nStartPos, nNaluSize);

		return pNalu;
	}
	unsigned char * GetOneNalu(unsigned char *pBufIn, int nInSize,  int &nNaluSize)
	{
		unsigned char *p = pBufIn;
		int nStartPos = 0, nEndPos = 0;
		int threezearo = 1;
		unsigned char* pNalu = 0;
		while (1)
		{
			if (p[0] == 0 && p[1] == 0 && p[2] == 0 && p[3] == 1|| p[0] == 0 && p[1] == 0 && p[2] == 1)
			{
				nStartPos = p - pBufIn;
				if (p[2] == 1)
					threezearo = 0;
				break;
			}
			p++;
			if (p - pBufIn >= nInSize - 4)
				return 0;
		}
		p++;
		while (1)
		{
			if (p[0] == 0 && p[1] == 0 && p[2] == 0 && p[3] == 1 || p[0] == 0 && p[1] == 0 && p[2] == 1)
			{
				nEndPos = p - pBufIn;
				break;
			}
			p++;
			if (p - pBufIn >= nInSize - 4)
			{
				nEndPos = nInSize;
				break;
			}
		}
		nNaluSize = nEndPos - nStartPos;
		if (threezearo == 1)
		{
			 pNalu = (unsigned char*)malloc(nNaluSize);
			memcpy(pNalu, pBufIn + nStartPos, nNaluSize);
		}
		else
		{
			pNalu = (unsigned char*)malloc(nNaluSize+1);
			pNalu[0] = 0;
			memcpy(pNalu+1, pBufIn + nStartPos, nNaluSize);
			nNaluSize = nNaluSize + 1;
		}


		return pNalu;
	}

	int IsVideojjSEI(unsigned char *pNalu, int nNaluSize)
	{
		unsigned char *p = pNalu;

		if (p[3] != 1 || p[4] != 6 || p[5] != 5)
			return 0;
		p += 6;
		while (*p++==0xff) ;
		const char *szVideojjUUID = "VideojjLeonUUID";
		char *pp = (char *)p;
		for (int i = 0; (unsigned int)i < strlen(szVideojjUUID); i++)
		{
			if (pp[i] != szVideojjUUID[i])
				return 0;
		}
		
		return 1;
	}
}
