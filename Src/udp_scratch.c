/*
 * udp_scratch.c
 *
 *  Created on: Oct 9, 2018
 *      Author: 477grp2
 */

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "udp_scratch.h"
#include "vban.h"
#include "fft.h"
#include "arm_fft_bin_data.h"
#define FFT_Length_Tab 256
/* USER CODE END Includes */


/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN Private variables */
uint8_t txData[100];
struct udp_pcb *upcb;
struct vban_packet parsed_packet;
extern uint16_t * rxData;
extern float32_t fft_dataset[256*2];
extern float32_t testInput_f32_10khz[2048];
extern int compute_done;

/* USER CODE END Private variables */


/* Private function definitions ----------------------------------------------*/


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
        //HAL_GPIO_WritePin(GPIOB, LD3_Pin, err == ERR_OK);
        pbuf_free(p);
    }
}


void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, uint16_t port) {
    char * ptr = p->payload;
    char compare_id[4] = {'V','B','A','N'};
    char compare_streamname[16] = {'S','t','r','e','a','m','1'};
    parsed_packet = parse_vban_packet(ptr);
    float32_t temp_dataset[FFT_Length_Tab*2];
    if(!memcmp(parsed_packet.vban,compare_id,sizeof(compare_id))){
    	if(!memcmp(parsed_packet.streamname,compare_streamname,sizeof(compare_streamname)))
    	{
    		if(compute_done){
    			for(uint16_t i = 0; i < 255; i ++){
    				//fft_dataset[2*i] = 1;
    				temp_dataset[2*i] = (float32_t) (parsed_packet.payload[i]);
    				temp_dataset[2*i+1] = (float32_t) 0;
    			}
    			memcpy(fft_dataset,&temp_dataset,2*4*256);
    			//memcpy(fft_dataset,testInput_f32_10khz,2*FFT_Length_Tab*4);
    			compute_done = 0;
    			FFT_PROCESSING();
    		}
    		else{
    			compare_id[1] = 'b';
    		}
    	}
      //HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,0);
    }
	pbuf_free(p);
}
/* USER CODE END Private function definitions */
