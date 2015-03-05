#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace fonctionsModelesTests
{		
	TEST_CLASS(fonctionsModelesCalculerSomme)
	{
	public:

		//	Question 2
				
		TEST_METHOD(CalculerSomme_DansUnTableauDeFloat_DevraitRetournerLaSomme)
		{
			float tabFloat[5]   = { 22.2f, 11.1f, 33.1f, -55.5f, -99.9f };
			float sommeAttendue = tabFloat[0] + tabFloat[1] + tabFloat[2] + tabFloat[3] + tabFloat[4];

			Assert::AreEqual(sommeAttendue, CalculerSomme(tabFloat, 5));
		}

		TEST_METHOD(CalculerSomme_DansUnTableauDeInt_DevraitRetournerLaSomme)
		{
			int tabInt[5] = { 9, 2, 4, 34, -1 };
			int sommeAttendue = tabInt[0] + tabInt[1] + tabInt[2] + tabInt[3] + tabInt[4];

			Assert::AreEqual(sommeAttendue, CalculerSomme(tabInt, 5));
		}

		TEST_METHOD(CalculerSomme_DansUnTableauDeString_DevraitRetournerLaConcatenationDesString)
		{
			string tabString[5] = { "Huit", "Cinq", "Deux", "Trois", "Quatre" };
			string sommeAttendue = tabString[0] + tabString[1] + tabString[2] + tabString[3] + tabString[4];

			Assert::AreEqual(sommeAttendue, CalculerSomme(tabString, 5));
		}
	};
}