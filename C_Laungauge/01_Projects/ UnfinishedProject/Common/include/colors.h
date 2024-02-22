#ifndef COLORS_H
#define COLORS_H
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

// Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

// Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

// High intensity text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

// Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

// Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

// Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

// High intensity background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

// Reset
#define RESET "\e[0m\n"

// Color printf macros Not included  High intensity background,Regular background,Regular underline text

// Regular text
#define PBLK(FormatLiteral, ...)  printf(BLK FormatLiteral RESET, ##__VA_ARGS__)
#define PRED(FormatLiteral, ...)  printf(RED FormatLiteral RESET, ##__VA_ARGS__)
#define PGRN(FormatLiteral, ...)  printf(GRN FormatLiteral RESET, ##__VA_ARGS__)
#define PYEL(FormatLiteral, ...)  printf(YEL FormatLiteral RESET, ##__VA_ARGS__)
#define PBLU(FormatLiteral, ...)  printf(BLU FormatLiteral RESET, ##__VA_ARGS__)
#define PMAG(FormatLiteral, ...)  printf(MAG FormatLiteral RESET, ##__VA_ARGS__)
#define PCYN(FormatLiteral, ...)  printf(CYN FormatLiteral RESET, ##__VA_ARGS__)
#define PWHT(FormatLiteral, ...)  printf(WHT FormatLiteral RESET, ##__VA_ARGS__)

// Regular bold text
#define PBBLK(FormatLiteral, ...) printf(BBLK FormatLiteral RESET, ##__VA_ARGS__)
#define PBRED(FormatLiteral, ...) printf(BRED FormatLiteral RESET, ##__VA_ARGS__)
#define PBGRN(FormatLiteral, ...) printf(BGRN FormatLiteral RESET, ##__VA_ARGS__)
#define PBYEL(FormatLiteral, ...) printf(BYEL FormatLiteral RESET, ##__VA_ARGS__)
#define PBBLU(FormatLiteral, ...) printf(BBLU FormatLiteral RESET, ##__VA_ARGS__)
#define PBMAG(FormatLiteral, ...) printf(BMAG FormatLiteral RESET, ##__VA_ARGS__)
#define PBCYN(FormatLiteral, ...) printf(BCYN FormatLiteral RESET, ##__VA_ARGS__)
#define PBWHT(FormatLiteral, ...) printf(BWHT FormatLiteral RESET, ##__VA_ARGS__)

// High intensity text
#define PHBLK(FormatLiteral, ...) printf(HBLK FormatLiteral RESET, ##__VA_ARGS__)
#define PHRED(FormatLiteral, ...) printf(HRED FormatLiteral RESET, ##__VA_ARGS__)
#define PHGRN(FormatLiteral, ...) printf(HGRN FormatLiteral RESET, ##__VA_ARGS__)
#define PHYEL(FormatLiteral, ...) printf(HYEL FormatLiteral RESET, ##__VA_ARGS__)
#define PHBLU(FormatLiteral, ...) printf(HBLU FormatLiteral RESET, ##__VA_ARGS__)
#define PHMAG(FormatLiteral, ...) printf(HMAG FormatLiteral RESET, ##__VA_ARGS__)
#define PHCYN(FormatLiteral, ...) printf(HCYN FormatLiteral RESET, ##__VA_ARGS__)
#define PHWHT(FormatLiteral, ...) printf(HWHT FormatLiteral RESET, ##__VA_ARGS__)

// Bold high intensity text
#define PBHBLK(FormatLiteral, ...) printf(BHBLK FormatLiteral RESET, ##__VA_ARGS__)
#define PBHRED(FormatLiteral, ...) printf(BHRED FormatLiteral RESET, ##__VA_ARGS__)
#define PBHGRN(FormatLiteral, ...) printf(BHGRN FormatLiteral RESET, ##__VA_ARGS__)
#define PBHYEL(FormatLiteral, ...) printf(BHYEL FormatLiteral RESET, ##__VA_ARGS__)
#define PBHBLU(FormatLiteral, ...) printf(BHBLU FormatLiteral RESET, ##__VA_ARGS__)
#define PBHMAG(FormatLiteral, ...) printf(BHMAG FormatLiteral RESET, ##__VA_ARGS__)
#define PBHCYN(FormatLiteral, ...) printf(BHCYN FormatLiteral RESET, ##__VA_ARGS__)
#define PBHWHT(FormatLiteral, ...) printf(BHWHT FormatLiteral RESET, ##__VA_ARGS__)

#define PCUSTOM(FormatLiteral, ...) printf(FormatLiteral RESET, ##__VA_ARGS__)

#endif