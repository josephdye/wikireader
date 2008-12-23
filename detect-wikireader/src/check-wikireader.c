/*
 * (C) Copyright 2008 OpenMoko, Inc.
 * Author: xiangfu liu <xiangfu@openmoko.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <unistd.h>
#include <syslog.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ET_EXEC		2
#define EM_C33		0x6b

#define ELFMAG0		0x7f
#define ELFMAG1		0x45
#define ELFMAG2		0x4c
#define ELFMAG3		0x46

typedef struct {
	unsigned char  e_ident[16];	/* ELF "magic number" */
	unsigned short e_type;		/* Identifies object file type */
	unsigned short e_machine;	/* Specifies required architecture */
	unsigned int e_version;		/* Identifies object file version */
	unsigned int e_entry;		/* Entry point virtual address */
	unsigned int e_phoff;		/* Program header table file offset */
	unsigned int e_shoff;		/* Section header table file offset */
	unsigned int e_flags;		/* Processor-specific flags */
	unsigned short e_ehsize;		/* ELF header size in bytes */
	unsigned short e_phentsize;	/* Program header table entry size */
	unsigned short e_phnum;		/* Program header table entry count */
	unsigned short e_shentsize;	/* Section header table entry size */
	unsigned short e_shnum;		/* Section header table entry count */
	unsigned short e_shstrndx;	/* Section header string table index */
} __attribute__ ((packed)) elf32_hdr;

extern char **environ;

int check_wikireader(char *path)
{
	elf32_hdr hdr;
	int r;
	int file;

	if ( (file = open(path, O_RDWR, 
			  S_IRUSR | S_IWUSR |
			  S_IRGRP | S_IROTH) ) < 0) {
		syslog(LOG_INFO, "can't open --%s--", path);
		return -1;
	}

	r = read(file, &hdr, sizeof(hdr));
	if ( r != sizeof(hdr)) {
		syslog(LOG_INFO, "can't read --%s-%d-%d-%d-", path, file, r, sizeof(hdr));
		return -1;
	}

	if (hdr.e_ident[0] != ELFMAG0 ||
	    hdr.e_ident[1] != ELFMAG1 ||
	    hdr.e_ident[2] != ELFMAG2 ||
	    hdr.e_ident[3] != ELFMAG3) {
		syslog(LOG_INFO, "not ELF file");
		return -1;
	}

	if (hdr.e_type != ET_EXEC) {
		syslog(LOG_INFO, "invalid ELF file type");
		return -1;
	}

	if (hdr.e_machine != EM_C33) {
		syslog(LOG_INFO, "invalid ELF machine type");
		return -1;
	}

	/*TODO: open websit wiki.openmoko.com
	 */
	syslog(LOG_INFO, "yes. this is wikireader sd card --%s--.", path );
	system("firefox   http://wiki.openmoko.org");
	syslog(LOG_INFO, "firefox");

	return 0;
}