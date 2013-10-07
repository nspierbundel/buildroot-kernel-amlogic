//      pinmux.h
//      
//      Copyright 2011 Unknown <jerry.yu@jerryyu-Lenovo>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//      
#ifndef __INCLUDE_MACH_MESON3_H_
#define __INCLUDE_MACH_MESON3_H_
#include <linux/types.h>
#define AO				9
#define PINMUX_REG(n)	n
#define PINMUX_END_ITEM {.reg=0xffffffff}



/**
 * structure and data type
 */
typedef struct __pinmux_item{
	uint32_t reg;
	uint32_t clrmask;
	uint32_t setmask;
}pinmux_item_t;
struct __pinmux_set_s{
	bool (* chip_select)(bool);///@todo implement it later .
	pinmux_item_t * pinmux;
};

typedef struct __pinmux_set_s pinmux_set_t;

/**
 * UTIL interface  
 * these function can be implement in a tools
 */
 /**
  * @return NULL is fail
  * 		errno NOTAVAILABLE , 
  * 			  SOMEPIN IS LOCKED
  */
pinmux_set_t* pinmux_cacl_str(char * pad,char * sig ,...);
pinmux_set_t* pinmux_cacl_int(uint32_t pad,uint32_t sig ,...);
pinmux_set_t* pinmux_cacl(char * str);///formate is "pad=sig pad=sig "
char ** pin_get_list(void);
char ** sig_get_list(void);
char * pin_getname(uint32_t pin);
char * sig_getname(uint32_t sig);
uint32_t pins_num(void);
/**
 * Util Get status function
 */
uint32_t pin_sig(uint32_t pin);
uint32_t sig_pin(uint32_t sig);
/**
 * pinmux set function
 * @return 0, success , 
 * 		   SOMEPIN IS LOCKED, some pin is locked to the specail feature . You can not change it
 * 		   NOTAVAILABLE, not available .
 */
int32_t pinmux_set(pinmux_set_t *);
int32_t pinmux_clr(pinmux_set_t *);
int32_t pinmux_set_locktable(pinmux_set_t*);

/**  Imported from M3 kernel  **/

int clear_mio_mux(unsigned mux_index, unsigned mux_mask);
int set_mio_mux(unsigned mux_index, unsigned mux_mask);
void clearall_pinmux(void);

#define ETH_BANK0_GPIOY1_Y9     0
#define ETH_BANK0_REG1          6
#define ETH_BANK0_REG1_VAL              (0x1ff<<8)

#define ETH_CLK_IN_GPIOY0_REG6_18       0
#define ETH_CLK_OUT_GPIOY0_REG6_17      1

int eth_set_pinmux(int bank_id, int clk_in_out_id, unsigned long ext_msk);

/*UART*/
#define UART_PORT_AO                (0)   /* ALWAYS_ON GPIOAO_0-> GPIOAO-3*/
#define UART_PORT_A                 (1)
#define UART_PORT_B                 (2)
#define UART_PORT_C                 (3)

#define UART_AO_GPIO_AO0_AO1_STD    (0)
#define UART_AO_GPIO_AO0_AO3_FULL   (1)
#define UART_A_GPIO_X13_X14_STD     (2)
#define UART_A_GPIO_X13_X16_FULL    (3)
#define UART_B_GPIO_X17_X18_STD     (4)
#define UART_B_GPIO_X17_X20_FULL    (5)
#define UART_B_GPIO_X23_X24_STD     (6)
#define UART_C_GPIO_X21_X22_STD     (7)
#define UART_C_GPIO_X21_X24_FULL    (8)

void uart_set_pinmux(int port, int uart_bank);

/*AUDIO*/

#define AUDIO_OUT_JTAG              0
#define AUDIO_OUT_GPIOA             1
#define AUDIO_OUT_TEST_N            2
#define AUDIO_IN_JTAG               3
#define SPDIF_OUT_GPIOA             4
#define SPDIF_OUT_GPIOB             5
#define SPDIF_OUT_TEST_N            6
#define SPDIF_IN_GPIOA              7
#define SPDIF_IN_GPIOB              8

void set_audio_pinmux(int type);


#endif
