#include <stdio.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include "i2c.h"

#define I2C_DEVNAME "/dev/i2c-1"

FILE *i2c_open(int addr) {
    FILE *f = fopen(I2C_DEVNAME, "wb");
    if (!f) {
        puts("Unable to open I2C bus!");
        return NULL;
    }
    int fd = fileno(f);
    if (ioctl(fd, I2C_SLAVE, addr) < 0) {
        perror("i2c_open: ioctl");
        fclose(f);
        return NULL;
    }
    return f;
}
