/*
 *  Setup code for AT91SAM9
 *
 *  Copyright (C) 2011 Atmel,
 *                2011 Nicolas Ferre <nicolas.ferre@atmel.com>
 *
 * Licensed under GPLv2 or later.
 */

#ifdef CONFIG_HAVE_TCM
 #error "nao compativel com HAVE_TCM (conflito de endereco virtual)"
#else
 // reusa o mesmo endereco virtual desse TCM. assim se ele mudar em uma nova
 // versao de kernel a gente muda junto e nao gera conflito com outras coisas.
 #define CONFIG_HAVE_TCM
 #include <asm/memory.h>
 #ifndef ITCM_OFFSET
   #error "ITCM_OFFSET nao definido"
 #endif
#endif

#include <linux/of.h>
#include <linux/of_platform.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/system_misc.h>

#include "generic.h"


#define AT91_SYSC_PHYS	UL(0xffffc000)
#define AT91_SPI1_PHYS	UL(0xf0004000)
#define AT91_TC0_PHYS	UL(0xF8008000)
#define AT91_TC3_PHYS	UL(0xF800C000)
static struct map_desc at91_iomap_desc[] __initdata = {
	{
		.virtual	= ITCM_OFFSET,
		.pfn		= __phys_to_pfn(AT91_SYSC_PHYS),
		.length		= SZ_16K,
		.type		= MT_DEVICE,
	},
	{
		.virtual	= ITCM_OFFSET + SZ_16K,
		.pfn		= __phys_to_pfn(AT91_SPI1_PHYS),
		.length		= SZ_16K,
		.type		= MT_DEVICE,
	},
	{
		.virtual	= ITCM_OFFSET + SZ_16K * 2,
		.pfn		= __phys_to_pfn(AT91_TC0_PHYS),
		.length		= SZ_16K,
		.type		= MT_DEVICE,
	},
	{
		.virtual	= ITCM_OFFSET + SZ_16K * 3,
		.pfn		= __phys_to_pfn(AT91_TC3_PHYS),
		.length		= SZ_16K,
		.type		= MT_DEVICE,
	}
};

static void __init at91sam9_init(void)
{
	of_platform_default_populate(NULL, NULL, NULL);

	at91sam9_pm_init();
}

static const char *const at91_dt_board_compat[] __initconst = {
	"atmel,at91sam9",
	NULL
};

static void __init at91_map_io(void)
{
	/* Map static IO for FIQ module usage */
	iotable_init(at91_iomap_desc, sizeof(at91_iomap_desc)/sizeof(at91_iomap_desc[0]));
}

DT_MACHINE_START(at91sam_dt, "Atmel AT91SAM9")
	/* Maintainer: Atmel */
	.init_machine	= at91sam9_init,
	.dt_compat	= at91_dt_board_compat,
	.map_io		= at91_map_io,
MACHINE_END

