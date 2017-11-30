#ifndef SPLITTER_H
#define SPLITTER_H

namespace Cnvt
{
	unsigned char * GetFirstNalu(unsigned char *pBufIn, int nInSize,  int &nNaluSize);
	unsigned char * GetOneNalu(unsigned char *pBufIn, int nInSize, int &nNaluSize, int &naluHeaderSize);
	int IsVideojjSEI(unsigned char *pNalu, int nNaluSize);
}


#endif // SPLITTER_H
