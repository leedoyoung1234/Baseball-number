#include <string>
#include <stdexcept>
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const std::string& question) : question(question) {

	}
	GuessResult guess(const std::string& guessNumber) {
		assertIllegalArgument(guessNumber);
		//if (guessNumber == question)
		//{
		//	return { true, 3, 0 };
		//}
		//return { false, 0, 0 };
#if 1
		GuessResult result;
		result.solved = false;
		result.strikes = 0;
		result.balls = 0;
		for (size_t i = 0; i < guessNumber.length(); ++i) {
			if (guessNumber[i] == question[i]) {
				result.strikes++;
			}
			else if (question.find(guessNumber[i]) != std::string::npos) {
				result.balls++;
			}
		}
		if (result.strikes == 3) {
			result.solved = true;
		}
		return result;
#endif
	}
private:
	bool isDuplicatedNumber(const std::string& guessNumber) {
		for (size_t i = 0; i < guessNumber.length(); ++i) {
			for (size_t j = i + 1; j < guessNumber.length(); ++j) {
				if (guessNumber[i] == guessNumber[j]) {
					return true;
				}
			}
		}
		return false;
	}

	void assertIllegalArgument(const std::string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw std::length_error("Must be three letters.");
		}
		for (char ch : guessNumber)
		{
			if (ch < '0' || ch > '9') {
				throw std::invalid_argument("Must be a number.");
			}
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("Must not have the same nummber.");
		}
	}
	std::string question;
};