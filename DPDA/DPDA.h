#ifndef DPDA_H
#define DPDA_H

#include <string>
#include <stack>
#include <array>


class DPDA
{
private:
	std::string _input;
	std::stack<unsigned char> _stack;
	int _currentState;
	using States = void(DPDA::*)(const char signal);
	
	constexpr static int Q = 6;
	constexpr static int ALPHABET = 2;
	constexpr static int ALPHABET_STACK = 2;

	std::array<std::array<std::array<States, ALPHABET_STACK>, ALPHABET>, Q> _dpdaTable;

	void toState0(const char signal);
	void toState1(const char signal);
	void toState2(const char signal);
	void toState3(const char signal);
	void toState4(const char signal);
	void toState5(const char signal);

	void toUndefinedState(const char signal);

	static int interpreter(const char preSignal);

	void printErrorInString(const unsigned int errorNumber);
public:
	DPDA();
	bool conformityCheck(const std::string &inputString);
};
#endif // DPDA_H
