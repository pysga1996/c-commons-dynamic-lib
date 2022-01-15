#include <gtest/gtest.h>
extern "C" {
#include <common-matrix.h>
}

TEST(CommonMatrix, BoolMatrixTest) {
    char fileName[] = "common-matrix/bool-matrix.txt";
    matrix_bool *pMatrixBool = importBoolMatrix(fileName);
    ASSERT_NO_THROW(printBoolMatrix(pMatrixBool));
    ASSERT_EQ(pMatrixBool->size, 20);
    ASSERT_EQ(pMatrixBool->arr[2].size, 35);
    printf("\n");
}

TEST(CommonMatrix, IntMatrixTest) {
    char fileName[] = "common-matrix/int-matrix.txt";
    matrix_int *pMatrixInt = importIntMatrix(fileName);
    ASSERT_NO_THROW(printIntMatrix(pMatrixInt));
    ASSERT_EQ(pMatrixInt->size, 15);
    ASSERT_EQ(pMatrixInt->arr[2].size, 20);
    printf("\n");
}

TEST(CommonMatrix, LongMatrixTest) {
    char fileName[] = "common-matrix/long-matrix.txt";
    matrix_long *pMatrixLong = importLongMatrix(fileName);
    ASSERT_NO_THROW(printLongMatrix(pMatrixLong));
    ASSERT_EQ(pMatrixLong->size, 15);
    ASSERT_EQ(pMatrixLong->arr[2].size, 18);
    printf("\n");
}

TEST(CommonMatrix, DoubleMatrixTest) {
    char fileName[] = "common-matrix/double-matrix.txt";
    matrix_double *pMatrixDouble = importDoubleMatrix(fileName);
    ASSERT_NO_THROW(printDoubleMatrix(pMatrixDouble));
    ASSERT_EQ(pMatrixDouble->size, 12);
    ASSERT_EQ(pMatrixDouble->arr[2].size, 15);
    printf("\n");
}

TEST(CommonMatrix, StringMatrixTest) {
    char fileName[] = "common-matrix/string-matrix.txt";
    matrix_string *pMatrixString = importStringMatrix(fileName);
    ASSERT_NO_THROW(printStringMatrix(pMatrixString));
    ASSERT_EQ(pMatrixString->size, 12);
    ASSERT_EQ(pMatrixString->arr[2].size, 10);
    printf("\n");
}

