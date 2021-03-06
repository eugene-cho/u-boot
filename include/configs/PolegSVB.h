/*---------------------------------------------------------------------------------------------------------*/
/*  Nuvoton Technology Corporation confidential                                                            */
/*                                                                                                         */
/*  Copyright (c) 2009 by Nuvoton Technology Corporation                                                   */
/*  All rights reserved                                                                                    */
/*                                                                                                         */
/*<<<------------------------------------------------------------------------------------------------------*/
/* File Contents:                                                                                          */
/*   PolegSVB.h                                                                                           */
/*            This file contains configurations for the PolegSVB compilation                              */
/*  Project:                                                                                               */
/*            U-Boot                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/

#ifndef __POLEGPALLADIUM_H
#define __POLEGPALLADIUM_H


/*---------------------------------------------------------------------------*/
/* Please Start here and Select Board's configuration                        */
/*---------------------------------------------------------------------------*/

/* ########## Activate Palladium bypasses ########## */
/*#define _PALLADIUM_                       1*/

/* ########## Remove flash support ########## */
/*#define _CONFIG_NO_FLASH_                 1       */


/* ########## Enable DELL_DRB HW changes from PolegSVB ########## */
/*#define CONFIG_SYS_DELL_DRB_HW            1*/


/*
	* Warning: changing CONFIG_SYS_TEXT_BASE requires
	* adapting the initial boot program.
	* Since the linker has to swallow that define, we must use a pure
	* hex number here!
	*/

/* DO NOT move this Define !*/
#ifndef CONFIG_SYS_TEXT_BASE
#ifdef _PALLADIUM_
#define CONFIG_SYS_TEXT_BASE		0x8200           /* Palladium   */
/*#define CONFIG_SYS_TEXT_BASE		0x80080000       // BOOT From FLASH (depend on booter)*/
#else
#define CONFIG_SYS_TEXT_BASE		0x8200           /* BOOT Block will copy u-boot.bin image A/B to General location in DDR. */
/*#define CONFIG_SYS_TEXT_BASE		0x80080000       // BOOT From FLASH (depend on booter)*/
/*#define CONFIG_SYS_TEXT_BASE		0x80005200       // BOOT From FLASH (depend on booter)*/
#endif
#endif


#define CONFIG_SYS_MEM_TOP_HIDE   (_16MB_ + _32MB_)  /* 16MB Graphics Memory size to hide + 32MB for VCD ECE DVC. */


/* Uncomment to remove L1/L2-Caches */
/*=========================================*/
/*#define CONFIG_SYS_ICACHE_OFF*/
/*#define CONFIG_SYS_DCACHE_OFF*/
/*#define CONFIG_SYS_L2CACHE_OFF        1*/
/*=========================================*/


#include "nuvoton.h"



/*---------------------------------------------------------------------------------------------------------*/
/* For Debugging                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
/*#define DEBUG                           1*/
/*#define VERBOSE_GLOBAL                  1*/
/*#define VERBOSE_EMC                     1*/
/*#define VERBOSE_GMAC                    1*/
/*#define ET_DEBUG                        1*/
/*#define VERBOSE_SPI_FLASH               1           // FIU spi Debug*/



#define CONFIG_ARM_ERRATA_794072           /* ARM CORTEX-A9 Errata */


/*---------------------------------------------------------------------------------------------------------*/
/* L2-Cache controler PL310 for Cortex A9                                                                                    */
/*---------------------------------------------------------------------------------------------------------*/

#ifndef CONFIG_SYS_L2CACHE_OFF
#define CONFIG_SYS_L2_PL310		1
#define CONFIG_SYS_PL310_BASE	0xF03FC000       /* L2 - Cache Regs Base (4k Space)*/
#endif

#define CONFIG_SYS_CACHELINE_SIZE	   32

#define CONFIG_BOARD_LOWLEVEL_INIT      1


/*---------------------------------------------------------------------------------------------------------*/
/* Size of malloc() pool                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define CONFIG_SYS_MALLOC_LEN           (CONFIG_ENV_SIZE + 1024*1024)


/*---------------------------------------------------------------------------------------------------------*/
/* Serial Console Configuration                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#ifdef _PALLADIUM_
	#define CONFIG_BAUDRATE                 600
#else
	#define CONFIG_BAUDRATE                 115200
#endif

#undef CONFIG_SYS_BAUDRATE_TABLE
#define CONFIG_SYS_BAUDRATE_TABLE       { 300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200 }


/*---------------------------------------------------------------------------------------------------------*/
/* Networking                                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
#define CONFIG_ETH_DEVS                 CHIP_NUM_OF_EMC_ETH + CHIP_NUM_OF_GMAC_ETH   /* 2 EMC + 2 GMAC */

#define CONFIG_NET_MULTI

#define CONFIG_IPADDR                   127.0.0.1
#define CONFIG_NETMASK                  255.255.255.0
#define CONFIG_SERVERIP                 127.0.0.1
#define CONFIG_GATEWAYIP                127.0.0.1

#define CONFIG_ETHADDR                  "00:00:F7:A0:FF:FC"      /* EMC1 */
#define CONFIG_HAS_ETH1
#define CONFIG_ETH1ADDR                 "00:00:F7:A0:FF:FD"      /* EMC2 */
#define CONFIG_HAS_ETH2
#define CONFIG_ETH2ADDR                 "00:00:F7:A0:FF:FE"      /* GMAC1 */
#define CONFIG_HAS_ETH3
#define CONFIG_ETH3ADDR                 "00:00:F7:A0:FF:FF"      /* GMAC2 */

#ifndef CONFIG_CMD_NET
#define CONFIG_CMD_NET
#endif

#define CONFIG_CMD_GMAC
#define CONFIG_CMD_RNG



/* Ethernet driver configuration */
#define CONFIG_PHYLIB
#define CONFIG_ETH_DESIGNWARE
#define CONFIG_NUC970_ETH
#define CONFIG_PHY_BROADCOM

#define CONFIG_GMAC_RGMII_PHY           0x19           /* GMAC RGMII Phy Address (see PolegSVB schematic) */
#define CONFIG_NUC970_PHY_ADDR          0x03           /* EMC RMII Phy Address (see PolegSVB schematic) */
#define CONFIG_PHY_RESET_DELAY			10000		   /* in usec */
#define CONFIG_PHY_GIGE			                       /* Include GbE speed/duplex detection */

/*---------------------------------------------------------------------------------------------------------*/
/* USB                                                                                                     */
/*---------------------------------------------------------------------------------------------------------*/

/* USB UHH support options */
#define CONFIG_CMD_USB
#define CONFIG_USB_HOST
/*#define CONFIG_USB_OHCI*/
#define CONFIG_USB_EHCI
#define CONFIG_USB_STORAGE
#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS 1


/*---------------------------------------------------------------------------------------------------------*/
/* Crypto                                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
/* #define CONFIG_CMD_SHA1SUM */
/* #define CONFIG_CMD_SHA256SUM */
#define CONFIG_CMD_HASH



#define CONFIG_LAST_STAGE_INIT




/*---------------------------------------------------------------------------------------------------------*/
/* Environment organization                                                                                */
/*---------------------------------------------------------------------------------------------------------*/


#undef  CONFIG_BOOTARGS
#define CONFIG_BOOTARGS   "earlycon=${earlycon} root=/dev/ram console=${console} mem=${mem} ramdisk_size=48000 basemac=${ethaddr}"



#define CONFIG_BOOTDELAY                2



#undef  CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS   "uimage_flash_addr=80200000\0"   \
		"stdin=serial\0"   \
		"stdout=serial\0"   \
		"stderr=serial\0"    \
		"ethact=ETH${eth_num}\0"   \
		"romboot=echo Booting Kernel from flash; echo +++ uimage at 0x${uimage_flash_addr}; " \
		"echo Using bootargs: ${bootargs};bootm ${uimage_flash_addr}\0" \
		"autostart=yes\0"   \
		"eth_num=0\0"    \
		"common_bootargs=setenv bootargs earlycon=${earlycon} root=/dev/ram console=${console} mem=${mem} ramdisk_size=48000 basemac=${ethaddr}\0"   \
		"ftp_prog=setenv ethact ETH${eth_num}; dhcp; tftp 10000000 image-bmc; cp.b 10000000 80000000 ${filesize}\0"   \
		"ftp_run=setenv ethact ETH${eth_num}; dhcp; tftp 10000000 image-bmc; bootm 10200000\0"   \
		"sd_prog=fatload mmc 0 10000000 image-bmc; cp.b 10000000 80000000 ${filesize}\0"  \
		"sd_run=fatload mmc 0 10000000 image-bmc; bootm 10200000\0"   \
		"usb_prog=usb start; fatload usb 0 10000000 image-bmc; cp.b 10000000 80000000 ${filesize}\0"    \
		"usb_run=usb start; fatload usb 0 10000000 image-bmc; bootm 10200000\0"   \
		"ethaddr=" CONFIG_ETHADDR "\0"	\
		"eth1addr=" CONFIG_ETH1ADDR "\0"  \
		"eth2addr=" CONFIG_ETH2ADDR "\0"  \
		"eth3addr=" CONFIG_ETH3ADDR "\0"  \
		"\0"




#undef  CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND "run common_bootargs;setenv ethact ETH${eth_num}; run romboot"

#define CONFIG_ENV_SIZE                  0x10000              /* Changed on UBOOT 201510.10.6.9 ! Total Size of Environment Sector (64K)*/
#define CONFIG_SYS_ENV_OFFSET           0x100000              /* Changed on UBOOT 201510.10.6.9 ! environment starts here */








#ifdef _CONFIG_NO_FLASH_
	#define CONFIG_SYS_NO_FLASH             1
	#undef	CONFIG_CMD_IMLS
	#define CONFIG_ENV_IS_NOWHERE
#else

#define CONFIG_ENV_IS_IN_FLASH          1                                           /* We save the environment in flash */

#define CONFIG_ENV_ADDR                 (CONFIG_FLASH_BASE + CONFIG_SYS_ENV_OFFSET) /* Flash addr of environment */

#define CONFIG_SYS_CONSOLE_ENV_OVERWRITE 1
#define CONFIG_ENV_OVERWRITE             1
#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#define CONFIG_FLASH_VERIFY              1
#endif



#endif /* __POLEGPALLADIUM_H*/

