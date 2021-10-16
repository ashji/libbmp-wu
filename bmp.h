#ifndef _BMP_H_
#define _BMP_H_
#include "Use.h"

#include <cstdio>
#include <string>

using namespace::std;


class BMP{
        public:
		BMP();
		void LoadPicture(string path);// Load picture

		//数据
		unsigned int Size();//大小
		unsigned int FDEF();//偏移量
		int Width();//宽
		int Height();//高
		unsigned short Compression();//颜色位数
		unsigned int BitCount();//压缩位数
		unsigned int SizeImage();//图像未压缩大小 4B
		unsigned int ClrUsed();//实际颜色索引数 4B
		unsigned int ClrImportant();//主要颜色索引数 4B
        private:
		//操作数据
		FILE* _bmp;
		Color *palette;//调色板
		bool State;//装态

		
		//图片数据
		unsigned short DM;//DM 2B
		unsigned int bfSize;//图像大小 4B
		unsigned int DEF;//偏移量=文件头(14B)+位图信息头(40B)+调色板索引数x[R,G,B,A](4B) 4B
		int biWidth;//宽 4B
		int biHeight;//高 4B
		unsigned int biCompression;//0:不压缩 1:8bit 4B
		unsigned short biBitCount;//颜色位数 4 8 16 32 2B
		unsigned int biSizeImage;//图像未压缩大小 4B
		unsigned int biClrUsed;//实际颜色索引数 4B
		unsigned int biClrImportant;//主要颜色索引数 4B
};

#endif //_BMP_H_
