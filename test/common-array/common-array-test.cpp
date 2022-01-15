#include <gtest/gtest.h>
extern "C" {
#include <common-array.h>
}

TEST(CommonArray, StringArrayTest) {
    char fileName[] = "common-array/string-array.txt";
    arr_string *pArrString = importStringArr(fileName);
    ASSERT_EQ(pArrString->size, 6);
    ASSERT_NO_THROW(printStringArr(pArrString));
    ASSERT_NO_THROW(freeStringArr(pArrString));
    printf("\n");
}

TEST(CommonArray, BoolArrayTest) {
    char fileName[] = "common-array/bool-array.txt";
    arr_bool *pArrBool = importBoolArr(fileName);
    ASSERT_EQ(pArrBool->size, 22);
    ASSERT_NO_THROW(printBoolArr(pArrBool));
    ASSERT_NO_THROW(freeBoolArr(pArrBool));
    printf("\n");
}

TEST(CommonArray, IntArrayTest) {
    char fileName[] = "common-array/int-array.txt";
    arr_int *pArrInt = importIntArr(fileName);
    ASSERT_EQ(pArrInt->size, 10);
    ASSERT_NO_THROW(printIntArr(pArrInt));
    ASSERT_NO_THROW(freeIntArr(pArrInt));
    printf("\n");
}

TEST(CommonArray, LongArrayTest) {
    char fileName[] = "common-array/long-array.txt";
    arr_long *pArrLong = importLongArr(fileName);
    ASSERT_EQ(pArrLong->size, 9);
    ASSERT_NO_THROW(printLongArr(pArrLong));
    ASSERT_NO_THROW(freeLongArr(pArrLong));
    printf("\n");
}

TEST(CommonArray, DoubleArrayTest) {
    char fileName[] = "common-array/double-array.txt";
    arr_double *pArrDouble = importDoubleArr(fileName);
    ASSERT_EQ(pArrDouble->size, 13);
    ASSERT_NO_THROW(printDoubleArr(pArrDouble));
    ASSERT_NO_THROW(freeDoubleArr(pArrDouble));
    printf("\n");
}
