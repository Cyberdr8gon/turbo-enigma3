#include "stdafx.h"
#include "CppUnitTest.h"
#include "../turboEnigma3/collision.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gameCode_TEST
{		
	TEST_CLASS(collisionTests)
	{
	public:
		
		TEST_METHOD(can_walk_on_floor)
		{
			// TODO: Your test code here
      Assert::AreEqual(0, canWalk(Tile::Floor));
		}

    TEST_METHOD(can_walk_on_corridor)
		{
      Assert::AreEqual(0, canWalk(Tile::Corridor));
		}

    TEST_METHOD(cant_walk_on_wall)
		{
      Assert::AreEqual(1, canWalk(Tile::Wall));
		}

    TEST_METHOD(closed_door_toggles)
		{
      Assert::AreEqual(2, canWalk(ClosedDoor));
		}

	};
}