#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    int fd = open("test_mmap.bin", O_RDWR | O_CREAT | O_TRUNC, 0666);
    ftruncate(fd, 4096);
    unsigned char *ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    ptr[0] = 0xff;
    munmap(ptr, 4096);
    
    int fd2 = open("test_mmap.bin", O_RDWR);
    unsigned char *ptr2 = mmap(NULL, 4096, PROT_READ, MAP_SHARED, fd2, 0);
    printf("Read data: 0x%02x\n", ptr2[0]);
    return 0;
}
