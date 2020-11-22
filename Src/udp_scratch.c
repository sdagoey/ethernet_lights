/*
 * udp_scratch.c
 *
 *  Created on: Oct 9, 2018
 *      Author: 477grp2
 */

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "udp_scratch.h"
#include "vban.c"
/* USER CODE END Includes */


/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN Private variables */
uint8_t txData[100];
struct udp_pcb *upcb;
struct vban_header parsed_header;
extern uint16_t * rxData;

/* USER CODE END Private variables */


/* Private function definitions ----------------------------------------------*/

struct vban_header parse_vban_header(char *ptr){
    struct vban_header parsed_header;
    memcpy(&parsed_header.vban,ptr+HEADER_OFFSET,4);
    memcpy(&parsed_header.format_sr,ptr+SR_OFFSET,1);
    memcpy(&parsed_header.format_nbs,ptr+NBS_OFFSET,1);
    memcpy(&parsed_header.format_nbc,ptr+NBS_OFFSET,1);
    memcpy(&parsed_header.format_bit,ptr+NBS_OFFSET,1);
    memcpy(&parsed_header.streamname,ptr+STREAMNAME_OFFSET,16);
    memcpy(&parsed_header.nuFrame,ptr+FRAME_OFFSET,4);
    return parsed_header;
}

/* USER CODE BEGIN Private function definitions */
void udp_scratch_connect() {
	ip_addr_t destIPaddr;
	err_t err;

	upcb = udp_new();

	if (upcb != NULL) {
		IP4_ADDR(&destIPaddr, DEST_IP_ADDR0, DEST_IP_ADDR1, DEST_IP_ADDR2, DEST_IP_ADDR3);
		err = udp_connect(upcb, &destIPaddr, UDP_SERVER_PORT);
		if (err == ERR_OK) {
			// set receive callback for udp object
			udp_recv(upcb, udp_receive_callback, NULL);
		}
	}
}

void udp_receive_init(void)
{
   struct udp_pcb *upcb;
   err_t err;

   /* Create a new UDP control block  */
   upcb = udp_new();

   if (upcb)
   {
     /* Bind the upcb to the UDP_PORT port */
     /* Using IP_ADDR_ANY allow the upcb to be used by any local interface */
      err = udp_bind(upcb, IP_ADDR_ANY, UDP_SERVER_PORT);

      if(err == ERR_OK)
      {
        /* Set a receive callback for the upcb */
        udp_recv(upcb, udp_receive_callback, NULL);
      }
   }
}

void udp_scratch_send(uint16_t * txData, uint16_t count) {
    struct pbuf *p;
    uint16_t length = (sizeof(txData[0]) * count);
    p = pbuf_alloc(PBUF_TRANSPORT, length, PBUF_POOL);
    err_t err;

    if (p != NULL) {
        // copy txData into pbuf
        pbuf_take(p, (uint16_t *) txData, length);
        err = udp_send(upcb, p);
        HAL_GPIO_TogglePin(GPIOB, LD3_Pin);
        pbuf_free(p);
    }
}


void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, uint16_t port) {
    char * ptr = p->payload;
    char compare_id[4] = {'V','B','A','N'};
    parsed_header = parse_vban_header(ptr);
    if(!memcmp(parsed_header.vban,compare_id,sizeof(compare_id))){
      HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,0);

    }
	pbuf_free(p);
}
/* USER CODE END Private function definitions */
