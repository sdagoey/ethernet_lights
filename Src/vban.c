# include "vban.h"

struct vban_header{
    char vban[4];
    uint8_t format_sr;
    uint8_t format_nbs;
    uint8_t format_nbc;
    uint8_t format_bit;
    char streamname[16];
    uint32_t nuFrame;
};




