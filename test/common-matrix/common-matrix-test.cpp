#include <gtest/gtest.h>
extern "C" {
#include <common-matrix.h>
}

TEST(CommonMatrix, StringMatrixTest) {
    char fileName[] = "common-matrix/int-matrix.txt";
    matrix_int *pMatrixInt = readIntMatrix(fileName);
//    ASSERT_EQ(pMatrixInt->size, 6);
    ASSERT_NO_THROW(printIntMatrix(pMatrixInt));
//    ASSERT_NO_THROW(freeIntMatrix(pMatrixInt));
    printf("\n");
}
