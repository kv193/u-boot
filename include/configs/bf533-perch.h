/*
 * U-boot - Configuration file for CM-BF533 board
 */

#ifndef __CONFIG_CM_BF533_H__
#define __CONFIG_CM_BF533_H__

#include <asm/config-pre.h>

/* Processor Settings */
#define CONFIG_BFIN_CPU             bf533-0.6
#define CONFIG_BFIN_BOOT_MODE       BFIN_BOOT_BYPASS

/* Clock Settings */
#define CONFIG_CLKIN_HZ			25000000
#define CONFIG_CLKIN_HALF		0
#define CONFIG_PLL_BYPASS		0
#define CONFIG_VCO_MULT			10
#define CONFIG_CCLK_DIV			1
#define CONFIG_SCLK_DIV			5

/* Memory Settings */
#define CONFIG_MEM_ADD_WDTH	9
#define CONFIG_MEM_SIZE		32

#define CONFIG_EBIU_SDRRC_VAL	((((CONFIG_SCLK_HZ / 1000) * 64) / 8192) - (4 + 1))
#define CONFIG_EBIU_SDGCTL_VAL	(PSS | TWR_2 | TRCD_2 | TRP_2 | TRAS_4 | PASR_ALL | CL_2 | SCTLE)

#define CONFIG_EBIU_AMGCTL_VAL	(AMBEN_ALL | AMCKEN)
#define CONFIG_EBIU_AMBCTL0_VAL	(B1WAT_7 | B1RAT_11 | B1HT_2 | B1ST_3 | B0WAT_7 | B0RAT_11 | B0HT_2 | B0ST_3)
#define CONFIG_EBIU_AMBCTL1_VAL	(B3WAT_7 | B3RAT_11 | B3HT_2 | B3ST_3 | B2WAT_7 | B2RAT_11 | B2HT_2 | B2ST_3)

#define CONFIG_SYS_MONITOR_LEN	((256+256) * 1024)
#define CONFIG_SYS_MALLOC_LEN	(128 * 1024)

/* Flash Settings */
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_BASE		0x20000000
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_PROTECTION
#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_MAX_FLASH_SECT	71

/* Env Storage Settings */
#define CONFIG_ENV_IS_IN_FLASH	1
#define CONFIG_ENV_OFFSET	0x30000
#define CONFIG_ENV_SECT_SIZE	0x10000

/* Misc Settings */
#define CONFIG_BAUDRATE		57600
#define CONFIG_UART_CONSOLE	0

#define CONFIG_BOOTDELAY 1
#define CONFIG_BOOTCOMMAND "run mmc_attach; run load_os; bootm"
#define FLASHBOOT_ENV_SETTINGS \
        "bootargs=root=/dev/mmcblk0p1 rw clkin_hz=25000000 earlyprintk=serial,uart0,57600 rootdelay=3\0" \
        "image_name=uImage\0" \
        "load_os=ext2load mmc 0 0x1000000 $(image_name)\0" \
        "mmc_attach=mmc_spi 2;mmcinfo;ext2ls mmc 0\0"

#define CONFIG_BFIN_SPI
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_MMC_SPI
#define CONFIG_ENV_SPI_MAX_HZ   30000000
#define CONFIG_SF_DEFAULT_SPEED 30000000
#define CONFIG_CMD_EXT2

/* Pull in common ADI header for remaining command/environment setup */
#include <configs/bfin_adi_common.h>

#endif
