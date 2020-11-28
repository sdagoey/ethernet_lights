#ifndef vban_H_
#define vban_H_

#define HEADER_OFFSET 0
#define SR_OFFSET 4
#define NBS_OFFSET 5
#define NBC_OFFSET 6
#define FORMAT_BIT_OFFSET 7
#define STREAMNAME_OFFSET 8
#define FRAME_OFFSET 24
#define PAYLOAD_START 27

#include "main.h"
#include <string.h>
#include <stdio.h>
struct vban_packet{
    char vban[4];
    uint8_t format_sr;
    uint8_t format_nbs;
    uint8_t format_nbc;
    uint8_t format_bit;
    char streamname[16];
    uint32_t nuFrame;
    uint16_t payload[256];
};
struct vban_packet parse_vban_packet(char *ptr);
//struct vban_header parse_vban_header(char *ptr);

//struct vban_header parse_vban_header(char *ptr);
#endif
