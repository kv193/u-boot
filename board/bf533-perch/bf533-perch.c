/*
 * U-boot - main board file
 *
 * Copyright (c) 2005-2008 Analog Devices Inc.
 *
 * Licensed under the GPL-2 or later.
 */

#include <common.h>
/*#include <netdev.h>*/

DECLARE_GLOBAL_DATA_PTR;

int checkboard(void)
{
	printf("Board: Kvarta Lab BF533-PERCH board\n");
	printf("       Support: kvarta-lab@yandex.ru\n");
	return 0;
}


