#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public ::testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(std::string quessNumber) {
		try {
			game.guess(quessNumber);
			FAIL();
		}
		catch (std::exception& e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, Invalid_Case) {
	assertIllegalArgument("12s");
	assertIllegalArgument("12");
	assertIllegalArgument("121");
};


TEST_F(BaseballFixture, S2B0) {
	GuessResult result = game.guess("103");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);
};

TEST_F(BaseballFixture, S1B2) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 1);
	EXPECT_EQ(result.balls, 2);
};

TEST_F(BaseballFixture, MatchedNumberCase) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(result.strikes, 3);
	EXPECT_EQ(result.balls, 0);
};


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}