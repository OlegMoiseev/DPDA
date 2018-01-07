#include "DPDA.h"
#include <iostream>


// 0 in stack ~ stack is empty; 0 ~ z0
DPDA::DPDA()
	: _currentState(0),
	  _dpdaTable(
	             {
		             {
			             {
				             {
					             {{&DPDA::toUndefinedState, &DPDA::toState1}},
					             // q0 -> 0, z    q0 -> 0, 1
					             {{&DPDA::toState0, &DPDA::toState0}} // q0 -> 1, z    q0 -> 1, 1
				             }
			             },

			             {
				             {
					             {{&DPDA::toUndefinedState, &DPDA::toState2}},
					             // q1 -> 0, z    q1 -> 0, 1
					             {{&DPDA::toUndefinedState, &DPDA::toUndefinedState}} // q1 -> 1, z    q1 -> 1, 1
				             }
			             },

			             {
				             {
					             {{&DPDA::toUndefinedState, &DPDA::toState1}},
					             // q2 -> 0, z    q2 -> 0, 1
					             {{&DPDA::toState3, &DPDA::toUndefinedState}} // q2 -> 1, z    q2 -> 1, 1
				             }
			             },

			             {
				             {
					             {{&DPDA::toUndefinedState, &DPDA::toState4}},
					             // q3 -> 0, z    q3 -> 0, 1
					             {{&DPDA::toState3, &DPDA::toState3}} // q3 -> 1, z    q3 -> 1, 1
				             }
			             },

			             {
				             {
					             {{&DPDA::toUndefinedState, &DPDA::toState5}},
					             // q4 -> 0, z    q4 -> 0, 1
					             {{&DPDA::toUndefinedState, &DPDA::toUndefinedState}} // q4 -> 1, z    q4 -> 1, 1
				             }
			             },

			             {
				             {
					             {{&DPDA::toUndefinedState, &DPDA::toState4}},
					             // q5 -> 0, z    q5 -> 0, 1
					             {{&DPDA::toUndefinedState, &DPDA::toUndefinedState}} // q5 -> 1, z    q5 -> 1, 1
				             }
			             }
		             }
	             }
	            )
{
	_stack.push(0);
}

void DPDA::printErrorInString(const unsigned int errorNumber)
{
	for (size_t j = 0; j < _input.size(); ++j)
	{
		std::cout << _input[j];
	}
	std::cout << std::endl;
	for (size_t j = 0; j < errorNumber; ++j)
	{
		std::cout << ' ';
	}
	std::cout << '^' << std::endl;
}

DPDA* DPDA::getInstance()
{
	return new DPDA();
}

void DPDA::toState0(const char signal)
{
	_stack.push(signal);
	_currentState = 0;
}

void DPDA::toState1(const char)
{
	_currentState = 1;
}

void DPDA::toState2(const char)
{
	_stack.pop();
	_currentState = 2;
}

void DPDA::toState3(const char signal)
{
	_stack.push(signal);
	_currentState = 3;
}

void DPDA::toState4(const char)
{
	_currentState = 4;
}

void DPDA::toState5(const char)
{
	_stack.pop();
	_currentState = 5;
}

void DPDA::toUndefinedState(const char)
{
	_currentState = -1;
}

int DPDA::interpreter(const char preSignal)
{
	switch (preSignal)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		default:
			return -1;
	}
}

bool DPDA::conformityCheck(const std::string& inputString)
{
	_input = inputString;
	size_t count;
	for (count = 0; count < _input.size(); ++count)
	{
		const char signal = interpreter(_input[count]);
		if (signal != -1)
		{
			const int stTop = _stack.top();
			(this ->* _dpdaTable[_currentState][signal][stTop])(signal);
		}
		else
		{
			std::cout << "Unresolved external symbol " << _input[count] << ':' << std::endl;
			printErrorInString(count);

			return false;
		}

		if (_currentState == -1)
		{
			std::cout << "Error in the typed character string:" << std::endl;
			printErrorInString(count);

			return false;
		}
	}

	if (_currentState == 5 && _stack.top() == 0)
	{
		_stack.pop();
		_currentState = 6;
	}

	if (_currentState == 2 && _stack.top() == 0)
	{
		_stack.pop();
		_currentState = 6;
	}

	if (_currentState == 0 && _stack.top() == 0)
	{
		_stack.pop();
		_currentState = 6;
	}

	if (_currentState == 6)
	{
		return true;
	}

	std::cout << "Error in the typed character string:" << std::endl;
	printErrorInString(count);
	return false;
}
