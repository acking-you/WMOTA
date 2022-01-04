//
// Created by Alone on 2021-12-23.
//

#ifndef WMOTA_PRINT_QRCODE_H
#define WMOTA_PRINT_QRCODE_H
#define QR_CODE(PATH) void print_qrcode(){\
    FILE* fd = fopen(PATH, "r");\
    if(fd==NULL){\
        perror("fopen");\
        exit(-1);\
    }\
    char buf[1024*1024];\
    fseek(fd, 0, SEEK_END);\
    int f_size =  ftell(fd);\
    if(f_size==0){\
        perror("ftell");\
        exit(-1);}\
    fseek(fd, 0, SEEK_SET);\
    fread(buf,1,f_size,fd);\
    buf[f_size] = '\0';\
    system("cls");\
    printf("\033[7m%s",buf);\
    printf("\033[0;32;31m请执行以下三个步骤对二维码进行扫描：1.把终端放大到全屏 2.按住ctrl+鼠标滚轮进行缩放 3.把终端恢复到原来的大小即可看到二维码\033[m");\
    fclose(fd);}\



#endif //WMOTA_PRINT_QRCODE_H
