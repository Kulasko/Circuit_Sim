#include "stdafx.h"
#include "CppUnitTest.h"

#include "../arschitek_utils/string_utils.h"

using arschitek_utils::split;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace arschitek_utils_test
{		
	TEST_CLASS(StringUtils)
	{
	public:
		
		TEST_METHOD(SplitNormal)
		{
			string testdata = "Das ist ein normaler Test.";
			vector<string> test_out = split(testdata);
			Assert::AreEqual(static_cast<size_t>(5), test_out.size());
			Assert::AreEqual(string("Das"), test_out[0]);
			Assert::AreEqual(string("ist"), test_out[1]);
			Assert::AreEqual(string("ein"), test_out[2]);
			Assert::AreEqual(string("normaler"), test_out[3]);
			Assert::AreEqual(string("Test."), test_out[4]);
		}
		
		TEST_METHOD(SplitDelimiterLast)
		{
			string testdata = "Das ist ein Test mit Leerzeichen am Ende. ";
			vector<string> test_out = split(testdata);
			Assert::AreEqual(static_cast<size_t>(8), test_out.size());
			Assert::AreEqual(string("Das"), test_out[0]);
			Assert::AreEqual(string("ist"), test_out[1]);
			Assert::AreEqual(string("ein"), test_out[2]);
			Assert::AreEqual(string("Test"), test_out[3]);
			Assert::AreEqual(string("mit"), test_out[4]);
			Assert::AreEqual(string("Leerzeichen"), test_out[5]);
			Assert::AreEqual(string("am"), test_out[6]);
			Assert::AreEqual(string("Ende."), test_out[7]);

		}
	};
}