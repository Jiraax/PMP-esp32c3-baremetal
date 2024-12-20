CFLAGS ?= -W -Wall -Wextra -Werror -Wundef -Wshadow
CFLAGS += -Wdouble-promotion -fno-common -Wconversion
CFLAGS += -march=rv32imc_zicsr -mabi=ilp32
CFLAGS += -Os -ffunction-sections -fdata-sections -I.
LDFLAGS ?= -Tlink.ld -nostdlib -nostartfiles -Wl,--gc-sections $(EXTRA_LINKFLAGS)
C ?= riscv32-esp-elf-gcc
SOURCES = startup.c main.c

build: firmware.bin

firmware.elf: $(SOURCES) hal.h link.ld pmp.h Makefile
	$(C) $(CFLAGS) $(CFLAGS_EXTRA) $(SOURCES) $(LDFLAGS) -o $@

firmware.bin: firmware.elf
	./esputil mkbin firmware.elf $@

flash: firmware.bin
	./esputil flash 0 firmware.bin

monitor:
	./esputil monitor

clean:
	@rm -rf *.{bin,elf,map,lst,tgz,zip,hex} firmware*
