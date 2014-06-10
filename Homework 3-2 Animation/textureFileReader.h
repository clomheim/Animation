


struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};
typedef struct Image Image;


int ImageLoad(char *filename, Image *image);
Image * loadTexture(char fileName[]);