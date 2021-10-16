#include "bmp.h"


#include <fstream>
#include <string>
#include <cstdio>

using namespace std;


int main(){
          BMP pic;
          string pa="test.bmp";
          pic.LoadPicture(pa);
          printf("Size:%d\n",pic.Size());
	printf("TOAL:%d\n",pic.FDEF());
	printf("Width:%d\n",pic.Width());
	printf("Height:%d\n",pic.Height());
	printf("BitCount:%d\n",pic.BitCount());
	printf("Compression:%d\n",pic.Compression());
	printf("SizeImage:%d\n",pic.SizeImage());
	printf("ClrUsed:%d\n",pic.ClrUsed());
	printf("ClrImportant:%d\n",pic.ClrImportant());
          return 0;
}
