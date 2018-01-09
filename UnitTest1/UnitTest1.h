#pragma once
#include <CppUnitTest.h>
#include "../DPDA/DPDA.h"
// ReSharper disable CppUnusedIncludeDirective
#include "../DPDA/DPDA.cpp"
// ReSharper restore CppUnusedIncludeDirective

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTestsDPDA
{
	TEST_CLASS(CheckDPDA)
	{
	private:
		DPDA _automata;
	public:
		TEST_METHOD(test0);
		TEST_METHOD(test1);
		TEST_METHOD(test2);
		TEST_METHOD(test3);
		TEST_METHOD(test4);
		TEST_METHOD(test5);
		TEST_METHOD(test6);
		TEST_METHOD(test7);
		TEST_METHOD(test8);
		TEST_METHOD(test9);

		TEST_METHOD(test10);
		TEST_METHOD(test11);
		TEST_METHOD(test12);
		TEST_METHOD(test13);
		TEST_METHOD(test14);
		TEST_METHOD(test15);
		TEST_METHOD(test16);
		TEST_METHOD(test17);
		TEST_METHOD(test18);
		TEST_METHOD(test19);
	};
}