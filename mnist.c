#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define IMAGE_SIZE 28

void read_mnist_images(const char *filename, unsigned char **images, int *nImages)
{



	int temp;
	int nsuc = 0;
	int rows, cols;

	printf("read_mnist_images \n");

	// FILE - datatype defined in stdio
	FILE *file = fopen(filename, "rb");

	if (!file)
		exit(1);
	else
		printf("File was opened \n");

	/*
		size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	*/
	nsuc = fread(&temp, sizeof(int), 1, file);  // int size is 4B
	printf("Magic number = %x \n\n", temp);
	printf("successfully read: %d \n\n", nsuc);


	
	nsuc = fread(nImages, sizeof(int), 1, file);	
	printf("successfully read: %d \n\n", nsuc);

	nsuc = fread(&rows, sizeof(int), 1, file);
	nsuc = fread(&cols, sizeof(int), 1, file);

	printf("nImages before swap = %d \n", *nImages); 
	printf("Rows before swap = %d \n", rows);
	printf("Cols before swap = %d \n", cols);

	/*
		__builtin_bswap32(uint32_t x) 
		- Returns x with the order of the bytes reversed; for example, 0xaabb becomes 0xbbaa. Byte here always means exactly 8 bits.
		- https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
	*/
	*nImages = __builtin_bswap32(*nImages);
	rows = __builtin_bswap32(rows);
	cols = __builtin_bswap32(cols);

	printf("nImages after swap = %d \n", *nImages); 
	printf("Rows after swap = %d \n", rows);
	printf("Cols after swap = %d \n", cols);


	*images = malloc((*nImages) * IMAGE_SIZE * IMAGE_SIZE);
	printf("Size of images (pointer) = %ld \n", sizeof(images));
	printf("Size of images (array) = %ld \n", strlen((char*)images));


}


void main()
{

	int nImages = 0;
	unsigned char *images = 0;
	read_mnist_images("data/train-images.idx3-ubyte", &images, &nImages);
}