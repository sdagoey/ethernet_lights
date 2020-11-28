# include "vban.h"

struct vban_packet parse_vban_packet(char *ptr){
    struct vban_packet parsed_packet;
    memcpy(&parsed_packet.vban,ptr+HEADER_OFFSET,4);
    memcpy(&parsed_packet.format_sr,ptr+SR_OFFSET,1);
    memcpy(&parsed_packet.format_nbs,ptr+NBS_OFFSET,1);
    memcpy(&parsed_packet.format_nbc,ptr+NBS_OFFSET,1);
    memcpy(&parsed_packet.format_bit,ptr+NBS_OFFSET,1);
    memcpy(&parsed_packet.streamname,ptr+STREAMNAME_OFFSET,16);
    memcpy(&parsed_packet.nuFrame,ptr+FRAME_OFFSET,4);
    //memcpy(&parsed_packet.payload,ptr+PAYLOAD_START,512);
    for(uint16_t i = 0; i < 256; i++){
    	uint16_t temp;
    	memcpy(&temp,ptr+PAYLOAD_START+2*i,2);
    	parsed_packet.payload[i] = (float32_t) (temp >> 8 | temp << 8);
    	//parsed_packet.payload[i] = temp;
    }
    return parsed_packet;
}



