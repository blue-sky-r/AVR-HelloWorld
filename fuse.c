#include <avr/io.h>

FUSES = {
    .low = LFUSE_DEFAULT | ~FUSE_CKDIV8,
    .high = HFUSE_DEFAULT,
    .extended = EFUSE_DEFAULT
};
