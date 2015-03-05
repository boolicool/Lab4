#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\fonctionsModeles\FonctionsModele.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace fonctionsModelesTests
{		
	TEST_CLASS(fonctionsModelesTrouverMaxTests)
	{
	public:

		//QUESTION 1

		TEST_METHOD(TrouverMax_DansUnTableauDeFloat_DevraitRetournerLeMaximum)
		{
			const float MAX_ATTENDU = 33.1;
			float tabFloat[5] = { 22.2f, 11.1f, MAX_ATTENDU, -55.5f, -99.9f };

			Assert::AreEqual(MAX_ATTENDU, TrouverMax(tabFloat, 5));
		}

		TEST_METHOD(TrouverMax_DansUnTableauDeInt_DevraitRetournerLeMaximum)
		{
			const int MAX_ATTENDU = 34;
			int tabInt[5] = { 9, 2, 4, MAX_ATTENDU, -1 };

			Assert::AreEqual(MAX_ATTENDU, TrouverMax(tabInt, 5));
		}

		TEST_METHOD(TrouverMax_DansUnTableauDeString_DevraitRetournerLeMaximumSelonLordreAlphabetique)
		{
			const string MAX_ATTENDU = "Trois";
			string tabString[5] = { "Huit", "Cinq", "Deux", MAX_ATTENDU, "Quatre" };

			Assert::AreEqual(MAX_ATTENDU, TrouverMax(tabString, 5));
		}
	};
}