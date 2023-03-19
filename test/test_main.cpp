#include "../gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

	setlocale(LC_ALL, "Russian");

    return RUN_ALL_TESTS();
}
