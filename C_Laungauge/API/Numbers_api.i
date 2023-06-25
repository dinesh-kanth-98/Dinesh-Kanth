            /* Removed Other Data of stdio.h  */
            
# 873 "/usr/include/st  dio.h" 3 4

# 2 "Numbers_api.c" 2
# 18 "Numbers_api.c"

# 18 "Numbers_api.c"
typedef enum
{
    NUMBER_ONE, NUMBER_TWO, NUMBER_THREE, NUMBER_FOUR, NUMBER_FIVE, NUMBER_SIX, NUMBER_SEVEN, NUMBER_EIGHT, NUMBER_NINE, NUMBER_TEN,
        MAX_NUMBERS,
} NUMBERS_e;

static char *numberStrings[MAX_NUMBERS] =
    {
        "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
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
