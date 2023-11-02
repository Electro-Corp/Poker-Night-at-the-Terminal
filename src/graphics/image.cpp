/*
*/
#include "image.h"

#include <cstring>

Graphics::Image::Image(std::string fPath, int x, int y){
    this->imagePath = fPath;
    this->x = x;
    this->y = y;
    FILE *fp = fopen(fPath.c_str(), "r");
    fseek(fp, 0L, SEEK_END);
    char buffer[ftell(fp)];
    rewind(fp);
    fread(buffer, sizeof(buffer), 1, fp);
    char *m = (char*)malloc((sizeof(char) * (sizeof(buffer) / sizeof(buffer[0]))));
    strcpy(m, buffer);
    char *p = strtok(m, " ");
    char *j = strtok(p, "\n");
    j = strtok(NULL, "\n");
    int width = atoi(j);
    int height = 0;
    //
    char *out = strtok(buffer, " \n");
    Color tmp = {0, 0, 0};
    int k = 0, c = 0, count = 0;
    while (out != NULL){
        if(k == 2) height = atoi(out);
        if(count <= 2 && k > 3){
        // printf("USING * %s\n",out);
            sscanf(out, "%d", &c);
            switch(count){
                case 0: tmp.r = c; break;
                case 1: tmp.g = c; break;
                case 2: tmp.b = c; break;
            }
            count++;
        }else if(k > 3){
            colorData.push_back(tmp);
            count = 0;
            //printf("[%d %d %d]\n",Colors[g-1].r, Colors[g-1].g, Colors[g-1].b);
            //getchar();
            out = strtok(NULL, " \n");
            out = strtok(NULL, " \n");
        }else{
        //printf("NOT USING * %s\n",out);
        }
        k++;
        out = strtok(NULL, " \n");
    }
    this->width = width;
    this->height = height;

}