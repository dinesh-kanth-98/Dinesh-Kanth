#include <stdio.h>

#define GEN_NUM_PARA_ENUM(NUM_PARA_ENUM, NUM_PARA_NAME) NUM_PARA_ENUM,
#define GEN_NUM_PARA_NAME(NUM_PARA_ENUM, NUM_PARA_NAME) NUM_PARA_NAME,

#define NUMBER_STRINGS(API)\
    API(NUMBER_ZERO,    "Zero")\
    API(NUMBER_ONE,     "One")\
    API(NUMBER_TWO,     "Two")\
    API(NUMBER_THREE,   "Three")\
    API(NUMBER_FOUR,    "Four")\
    API(NUMBER_FIVE,    "Five")\
    API(NUMBER_SIX,     "Six")\
    API(NUMBER_SEVEN,   "Seven")\
    API(NUMBER_EIGHT,   "Eight")\
    API(NUMBER_NINE,    "Nine")\
    API(NUMBER_TEN,     "Ten")\

typedef enum
{
    NUMBER_STRINGS(GEN_NUM_PARA_ENUM)
    MAX_NUMBERS,
} NUMBERS_e;

static char *numberStrings[MAX_NUMBERS] =
    {
        NUMBER_STRINGS(GEN_NUM_PARA_NAME)
    };

int main()
{
    NUMBERS_e num;
    for (num = NUMBER_ONE; num <= NUMBER_TEN; num++)
    {
        printf("Number: %d\n", num);
        printf("String: %s\n", numberStrings[num]);
        printf("\n");
    }
    return 0;
}
