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
					             {{&DPDA::toUndefinedState, &DPDA::toState1}},  // q0 -> 0, z    q0 -> 0, 1
					             {{&DPDA::toState0, &DPDA::toState0}} // q0 -> 1, z    q0 -> 1, 1
				             }
			             },

			             {
				             {
					             {{&DPDA::toUndefinedState, &DPDA::toState2}},  // q1 -> 0, z    q1 -> 0, 1
					             {{&DPDA::toUndefinedState, &DPDA::toUndefinedState}} // q1 -> 1, z    q1 -> 1, 1
				             }
			             },

						 {
							 {
								 {{&DPDA::toUndefinedState, &DPDA::toState1}},  // q2 -> 0, z    q2 -> 0, 1
								 {{&DPDA::toState0, &DPDA::toUndefinedState}} // q2 -> 1, z    q2 -> 1, 1
							 }
						 }
		             }
	             }
	            )
{
	_stack.push(0);
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

void DPDA::toState3(const char)
{
	_stack.pop();
	_currentState = 3;
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

bool DPDA::conformityCheck(const std::string &inputString)
{
	_input = inputString;
	for (size_t i = 0; i < _input.size(); ++i)
	{
		const char signal = interpreter(_input[i]);
		if (signal != -1)
		{
			const int stTop = _stack.top();
			(this->*_dpdaTable[_currentState][signal][stTop])(signal);
		}
		else
		{
			std::cout << "Unresolved external symbol " << _input[i] << std::endl;
			return false;
		}

		if (_currentState == -1)
		{
			return false;
		}
	}

	if (_currentState == 2 && _stack.top() == 0)
	{
		_currentState = 3;
		_stack.pop();
	}

	if (_currentState == 0 && _stack.top() == 0)
	{
		_currentState = 3;
		_stack.pop();
	}

	if (_currentState == 3)
	{
		return true;
	}

	return false;
}
