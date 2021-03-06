#include "pch.h"
#include "../lab2/Astroid.cpp"

TEST(AstroidConstructor, DefaultConstructor) {
    Prog2::Astroid a1;
ASSERT_EQ(1, a1.getR());
}

TEST(AstroidConstructor, InitConstructors) {
    Prog2::Astroid a2(2);
ASSERT_EQ(2, a2.getR());
}

TEST(AstroidConstructor, TestException) {
ASSERT_ANY_THROW(Prog2::Astroid a3(-3));
}

TEST(AstroidMethods, Setters) {
    Prog2::Astroid a3;
    a3.setR(3);
    ASSERT_EQ(3, a3.getR());
    ASSERT_ANY_THROW(a3.setR(0));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}