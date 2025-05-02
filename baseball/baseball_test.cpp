#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballTest, Test1) {
	EXPECT_EQ(1, 1);
};


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}