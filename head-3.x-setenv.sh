#! /bin/bash
#
#include/generated/autoconf.h
#include/linux/printk.h
# ou
#include/linux/kconfig.h
#include/linux/printk.h
#
#-------------------------------------------------------------------------------
# Linux Arietta:
#
# arm-buildroot-linux-gnueabi-gcc -Wp,-MD,mm/.swap.o.d
# -nostdinc
# -isystem /home/mroberto/cpti/hg/pig/head-3.x/toolchains/arm-buildroot-linux-gnueabi_sdk-buildroot-kh_4.9-gcc_9-arm/bin/../lib/gcc/arm-buildroot-linux-gnueabi/9.2.0/include
# -I./arch/arm/include
# -I./arch/arm/include/generated
# -I./include
# -I./arch/arm/include/uapi
# -I./arch/arm/include/generated/uapi
# -I./include/uapi
# -I./include/generated/uapi
# -include ./include/linux/kconfig.h
# -include ./include/linux/compiler_types.h
# -include ./include/linux/printk.h
# -D__KERNEL__
# -D__LINUX_ARM_ARCH__=4
# -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mfpu=vfp -funwind-tables -marm -Wa,-mno-warn-deprecated -march=armv4t -mtune=arm9tdmi -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -Wno-address-of-packed-member -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-var-tracking-assignments -Wdeclaration-after-statement -Wno-pointer-sign -Wno-stringop-truncation -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -fmacro-prefix-map=./= -Wno-packed-not-aligned
# -DKBUILD_BASENAME='"swap"' -DKBUILD_MODNAME='"swap"' -c -o mm/swap.o mm/swap.c
#
#-------------------------------------------------------------------------------
# KPIG:
#
# arm-buildroot-linux-gnueabi-gcc -Wp,-MD,/home/mroberto/cpti/hg/pig/head-3.x/pilox/tmp/tmp-kpig-arm/src-common/.dummydrv.o.d
# -nostdinc
# -isystem /home/mroberto/cpti/hg/pig/head-3.x/toolchains/arm-buildroot-linux-gnueabi_sdk-buildroot-kh_4.9-gcc_9-arm/bin/../lib/gcc/arm-buildroot-linux-gnueabi/9.2.0/include
# -I/home/mroberto/cpti/hg/pig/head-3.x/linux/arch/arm/include
# -I./arch/arm/include/generated
# -I/home/mroberto/cpti/hg/pig/head-3.x/linux/include
# -I./include
# -I/home/mroberto/cpti/hg/pig/head-3.x/linux/arch/arm/include/uapi
# -I./arch/arm/include/generated/uapi
# -I/home/mroberto/cpti/hg/pig/head-3.x/linux/include/uapi
# -I./include/generated/uapi
# -include /home/mroberto/cpti/hg/pig/head-3.x/linux/include/linux/kconfig.h
# -include /home/mroberto/cpti/hg/pig/head-3.x/linux/include/linux/compiler_types.h
# -I/home/mroberto/cpti/hg/pig/head-3.x/pilox/tmp/tmp-kpig-arm/src-common
# -I/home/mroberto/cpti/hg/pig/head-3.x/pilox/tmp/tmp-kpig-arm/src-common
# -D__KERNEL__
# -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mfpu=vfp -funwind-tables -marm -Wa,-mno-warn-deprecated
# -D__LINUX_ARM_ARCH__=4
# -march=armv4t -mtune=arm9tdmi -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -Wno-address-of-packed-member -Os -Wno-maybe-uninitialized --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-var-tracking-assignments -Wdeclaration-after-statement -Wno-pointer-sign -Wno-stringop-truncation -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -fmacro-prefix-map=/home/mroberto/cpti/hg/pig/head-3.x/linux/= -Wno-packed-not-aligned
# -I/home/mroberto/cpti/hg/pig/head-3.x/pilox/tmp/tmp-kpig-arm/src-common
# -DMODULE -DKBUILD_BASENAME='"dummydrv"' -DKBUILD_MODNAME='"dummydrv"'
# -c -o /home/mroberto/cpti/hg/pig/head-3.x/pilox/tmp/tmp-kpig-arm/src-common/dummydrv.o /home/mroberto/cpti/hg/pig/head-3.x/pilox/tmp/tmp-kpig-arm/src-common/dummydrv.c
#
#-------------------------------------------------------------------------------
# Pilox e Kpig:
#
# A1_TOOLCHAIN_NAME=arm-buildroot-linux-gnueabi
# A2_TOOLCHAIN_FILE=${A1_TOOLCHAIN_NAME}_sdk-buildroot-kh_4.9-gcc_9-arm
# A3_TOOLCHAIN_PATH=${PWD}/toolchains/${A2_TOOLCHAIN_FILE}/bin
# A4_CROSS_COMPILE=${A1_TOOLCHAIN_NAME}-
# ARCH=arm
# ARCH_AND_CROSS=ARCH=${ARCH} CROSS_COMPILE=${A4_CROSS_COMPILE}
# PATH=${A3_TOOLCHAIN_PATH}:${PATH}
# PIG_ROOTFS_ARCH=${PWD}/${ARCH}
# PILOX_MAKE_ARGS=${ARCH_AND_CROSS} PREFIX=${PIG_ROOTFS_ARCH}
#
#-------------------------------------------------------------------------------
# Kernel linux-arietta:
#
# A1_TOOLCHAIN_NAME=arm-buildroot-linux-gnueabi
# A2_TOOLCHAIN_FILE=${A1_TOOLCHAIN_NAME}_sdk-buildroot-kh_4.9-gcc_9-arm
# A3_TOOLCHAIN_PATH=${PWD}/../head-3.x/toolchains/${A2_TOOLCHAIN_FILE}/bin
# A4_CROSS_COMPILE=${A1_TOOLCHAIN_NAME}-
# ARCH=arm
# ARCH_AND_CROSS=ARCH=${ARCH} CROSS_COMPILE=${A4_CROSS_COMPILE}
# PATH=${A3_TOOLCHAIN_PATH}:${PATH}
# PILOX_MAKE_ARGS=${ARCH_AND_CROSS}
#

#-------------------------------------------------------------------------------
# A1_TOOLCHAIN_NAME=arm-buildroot-linux-gnueabi
# A2_TOOLCHAIN_FILE=${A1_TOOLCHAIN_NAME}_sdk-buildroot-kh_4.9-gcc_9-arm
# A3_TOOLCHAIN_PATH=/usr/local/toolchains/${A2_TOOLCHAIN_FILE}/bin
# A4_CROSS_COMPILE=${A1_TOOLCHAIN_NAME}-
# ARCH=arm
# ARCH_AND_CROSS=ARCH=${ARCH} CROSS_COMPILE=${A4_CROSS_COMPILE}
# PATH=${A3_TOOLCHAIN_PATH}:${PATH}
# PIG_ROOTFS_ARCH=${PWD}/${ARCH}
# PILOX_MAKE_ARGS=${ARCH_AND_CROSS} PREFIX=${PIG_ROOTFS_ARCH}


ARCH=arm
#CROSS_COMPILE=arm-buildroot-linux-gnueabi-
CROSS_COMPILE=arm-buildroot-linux-gnueabihf-
PATH_TOOLCHAIN=/home/mroberto/cpti/hg/pig/head-3.x/toolchains/${CROSS_COMPILE}_sdk-buildroot-kh_4.9-gcc_9-arm/bin

export PATH=$PATH_TOOLCHAIN:$PATH

#exit

#make ARCH=arm CROSS_COMPILE=arm-buildroot-linux-gnueabi- clean
make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE clean
make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE cpti-arietta_defconfig
make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE cpti-arietta.dtb
make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE -j8 zImage V=1
make ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE modules

