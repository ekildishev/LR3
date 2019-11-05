// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
    int intNum = 73;
    double doubleNum = 50.5;
    auto *intNumPtr = new int(intNum);
    auto *doubleNumPtr = new double(doubleNum);
    auto intSharedPtr = SharedPtr<int>(intNumPtr);
    auto doubleSharedPtr = SharedPtr<double>(doubleNumPtr);
    EXPECT_EQ(intSharedPtr.use_count(), 1);

    EXPECT_EQ(intSharedPtr.get(), intNumPtr);
    EXPECT_EQ(doubleSharedPtr.get(), doubleNumPtr);

    auto intSharedPtrCopy = intSharedPtr;
    auto doubleSharedPtrCopy = doubleSharedPtr;
    EXPECT_EQ(static_cast<bool>(intSharedPtrCopy), true);
    EXPECT_EQ(*doubleSharedPtrCopy, doubleNum);

    auto intSharedPtrMove = SharedPtr<int>(std::move(intSharedPtrCopy));
    EXPECT_EQ(*intSharedPtrMove, intNum);
    EXPECT_EQ(static_cast<bool>(intSharedPtrMove), true);
    EXPECT_EQ(intSharedPtrMove.operator->(), intNumPtr);

    intSharedPtr.reset();
    EXPECT_EQ(intSharedPtrMove.use_count(), 0);
}
