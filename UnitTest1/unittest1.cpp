#include "UnitTest1.h"

void unitTestsDPDA::CheckDPDA::test0()
{
	const std::string inputStr("100");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = true;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test1()
{
	const std::string inputStr("100100");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = true;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test2()
{
	const std::string inputStr("100110000");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = true;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test3()
{
	const std::string inputStr("");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = true;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test4()
{
	const std::string inputStr("110000100");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = true;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test5()
{
	const std::string inputStr("1100");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test6()
{
	const std::string inputStr("011001111");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test7()
{
	const std::string inputStr("10");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test8()
{
	const std::string inputStr("100011000");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test9()
{
	const std::string inputStr("110010000");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}
// ============================================================================
void unitTestsDPDA::CheckDPDA::test10()
{
	const std::string inputStr("0");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test11()
{
	const std::string inputStr("1");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test12()
{
	const std::string inputStr("00");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test13()
{
	const std::string inputStr("11");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test14()
{
	const std::string inputStr("000");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test15()
{
	const std::string inputStr("111");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test16()
{
	const std::string inputStr("100100001");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test17()
{
	const std::string inputStr("100110000100");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test18()
{
	const std::string inputStr("10100");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}

void unitTestsDPDA::CheckDPDA::test19()
{
	const std::string inputStr("010101");
	const bool tmpAnswer = _automata.conformityCheck(inputStr);
	const bool expectedAnswer = false;
	Assert::AreEqual(expectedAnswer, tmpAnswer, L"!ERROR!");
}