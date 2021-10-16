#include "Use.h"
#include "bmp.h"

#include <cstdio>
#include <string>

BMP::BMP(){
          palette=NULL;
}

void BMP::LoadPicture(string path){
          //打开文件
	_bmp=fopen(path.c_str(), "rb");
	if (_bmp == 0)return;

	unsigned short int T= 0x4d42;

	fread(&DM, 2, 1, _bmp);

	if(DM != T)//跳到错误方案
	{
		printf("haerd:%x\n",DM);
		State=false;
		printf("NOT BMP\n");
	return;
	}


	fseek(_bmp, 2, 0);
	fread(&bfSize, 4, 1, _bmp);//文件大小

	fseek(_bmp, 4, SEEK_CUR);
	fread(&DEF, 4, 1, _bmp);//偏移量

	fseek(_bmp, 4, SEEK_CUR);
	fread(&biWidth, 4, 1, _bmp);//宽
	
	fread(&biHeight, 4, 1, _bmp);//高:可以为负数
	
	fread(&biCompression, 2, 1, _bmp);//颜色位数
	
	fread(&biBitCount, 4, 1, _bmp);//压缩位数
	fread(&biSizeImage, 4, 1, _bmp);//图像未压缩大小 4B
	fread(&biClrUsed, 4, 1, _bmp);//实际颜色索引数 4B
	fread(&biClrImportant, 4, 1, _bmp);//主要颜色索引数 4B
}

unsigned int BMP::Size(){
	return bfSize;
}

unsigned int BMP::FDEF(){
	return DEF;
}

int BMP::Width(){
	return biWidth;
}

int BMP::Height(){
	return biHeight;
}

unsigned short BMP::Compression(){
	return biCompression;
}

unsigned int BMP::BitCount(){
	return biBitCount;
}

unsigned int BMP::SizeImage(){
	return biSizeImage;
}

unsigned int BMP::ClrUsed(){
	return biClrUsed;
}

unsigned int BMP::ClrImportant(){
	return biClrImportant;
}
