#include <stdlib.h>
#include <stdio.h>


/*
	


*/

void read_mnist_images(const char *filename,
	// , unsigned char **images,
	 int *nImages
	)
{



	int temp;
	int nsuc = 0;

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
	nsuc = fread(&temp, sizeof(int), 1, file);
	printf("Magic number = %x \n\n", temp);
	printf("successfully read: %d \n\n", nsuc);


	
	nsuc = fread(nImages, sizeof(int), 1, file);
	printf("nImages = %d \n\n", *nImages);  // why do I get this number???
	printf("successfully read: %d \n\n", nsuc);


	printf("Size of int = %d B\n", sizeof(int));
	printf("Size of char = %d B\n", sizeof(char));

}


void main()
{

	int nImages = 0;

	read_mnist_images("/home/advo/dev/miniMNIST_C/data/train-images.idx3-ubyte", &nImages);
}