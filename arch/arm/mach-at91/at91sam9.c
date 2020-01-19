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
#include "soc.h"

static const struct at91_soc at91sam9_socs[] = {
	AT91_SOC(AT91SAM9260_CIDR_MATCH, 0, "at91sam9260", NULL),
	AT91_SOC(AT91SAM9261_CIDR_MATCH, 0, "at91sam9261", NULL),
	AT91_SOC(AT91SAM9263_CIDR_MATCH, 0, "at91sam9263", NULL),
	AT91_SOC(AT91SAM9G20_CIDR_MATCH, 0, "at91sam9g20", NULL),
	AT91_SOC(AT91SAM9RL64_CIDR_MATCH, 0, "at91sam9rl64", NULL),
	AT91_SOC(AT91SAM9G45_CIDR_MATCH, AT91SAM9M11_EXID_MATCH,
		 "at91sam9m11", "at91sam9g45"),
	AT91_SOC(AT91SAM9G45_CIDR_MATCH, AT91SAM9M10_EXID_MATCH,
		 "at91sam9m10", "at91sam9g45"),
	AT91_SOC(AT91SAM9G45_CIDR_MATCH, AT91SAM9G46_EXID_MATCH,
		 "at91sam9g46", "at91sam9g45"),
	AT91_SOC(AT91SAM9G45_CIDR_MATCH, AT91SAM9G45_EXID_MATCH,
		 "at91sam9g45", "at91sam9g45"),
	AT91_SOC(AT91SAM9X5_CIDR_MATCH, AT91SAM9G15_EXID_MATCH,
		 "at91sam9g15", "at91sam9x5"),
	AT91_SOC(AT91SAM9X5_CIDR_MATCH, AT91SAM9G35_EXID_MATCH,
		 "at91sam9g35", "at91sam9x5"),
	AT91_SOC(AT91SAM9X5_CIDR_MATCH, AT91SAM9X35_EXID_MATCH,
		 "at91sam9x35", "at91sam9x5"),
	AT91_SOC(AT91SAM9X5_CIDR_MATCH, AT91SAM9G25_EXID_MATCH,
		 "at91sam9g25", "at91sam9x5"),
	AT91_SOC(AT91SAM9X5_CIDR_MATCH, AT91SAM9X25_EXID_MATCH,
		 "at91sam9x25", "at91sam9x5"),
	AT91_SOC(AT91SAM9N12_CIDR_MATCH, AT91SAM9CN12_EXID_MATCH,
		 "at91sam9cn12", "at91sam9n12"),
	AT91_SOC(AT91SAM9N12_CIDR_MATCH, AT91SAM9N12_EXID_MATCH,
		 "at91sam9n12", "at91sam9n12"),
	AT91_SOC(AT91SAM9N12_CIDR_MATCH, AT91SAM9CN11_EXID_MATCH,
		 "at91sam9cn11", "at91sam9n12"),
	AT91_SOC(AT91SAM9XE128_CIDR_MATCH, 0, "at91sam9xe128", "at91sam9xe128"),
	AT91_SOC(AT91SAM9XE256_CIDR_MATCH, 0, "at91sam9xe256", "at91sam9xe256"),
	AT91_SOC(AT91SAM9XE512_CIDR_MATCH, 0, "at91sam9xe512", "at91sam9xe512"),
	{ /* sentinel */ },
};


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


static void __init at91sam9_common_init(void)
{
	struct soc_device *soc;
	struct device *soc_dev = NULL;

	soc = at91_soc_init(at91sam9_socs);
	if (soc != NULL)
		soc_dev = soc_device_to_device(soc);

	of_platform_default_populate(NULL, NULL, soc_dev);
}

static void __init at91_map_io(void)
{
	/* Map static IO for FIQ module usage */
	iotable_init(at91_iomap_desc, sizeof(at91_iomap_desc)/sizeof(at91_iomap_desc[0]));
}

static void __init at91sam9_dt_device_init(void)
{
	at91sam9_common_init();
	at91sam9260_pm_init();
}

static const char *const at91_dt_board_compat[] __initconst = {
	"atmel,at91sam9",
	NULL
};

DT_MACHINE_START(at91sam_dt, "Atmel AT91SAM9")
	/* Maintainer: Atmel */
	.init_machine	= at91sam9_dt_device_init,
	.dt_compat	= at91_dt_board_compat,
	.map_io		= at91_map_io,
MACHINE_END

static void __init at91sam9g45_dt_device_init(void)
{
	at91sam9_common_init();
	at91sam9g45_pm_init();
}

static const char *const at91sam9g45_board_compat[] __initconst = {
	"atmel,at91sam9g45",
	NULL
};

DT_MACHINE_START(at91sam9g45_dt, "Atmel AT91SAM9G45")
	/* Maintainer: Atmel */
	.init_machine	= at91sam9g45_dt_device_init,
	.dt_compat	= at91sam9g45_board_compat,
	.map_io		= at91_map_io,
MACHINE_END

static void __init at91sam9x5_dt_device_init(void)
{
	at91sam9_common_init();
	at91sam9x5_pm_init();
}

static const char *const at91sam9x5_board_compat[] __initconst = {
	"atmel,at91sam9x5",
	"atmel,at91sam9n12",
	NULL
};

DT_MACHINE_START(at91sam9x5_dt, "Atmel AT91SAM9")
	/* Maintainer: Atmel */
	.init_machine	= at91sam9x5_dt_device_init,
	.dt_compat	= at91sam9x5_board_compat,
	.map_io		= at91_map_io,
MACHINE_END
