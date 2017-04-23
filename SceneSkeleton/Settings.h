#pragma once
struct MCOORD {
	int x, y;
	MCOORD operator -(MCOORD &rhs) {
		return{ x - rhs.x, y - rhs.y };
	}
	MCOORD& operator = (MCOORD &rhs) {
		x = rhs.x, y = rhs.y;
		return (*this);
	}
};

#pragma region Screen
#define SCREENWIDTH 1280
#define SCREENHEIGHT 960
#pragma endregion

#pragma region ID Codes
enum eControlCode { UP_KEY, DOWN_KEY, LEFT_KEY, RIGHT_KEY, SHOOT_KEY, TANK_TURRET_LEFT, TANK_TURRET_RIGHT };
enum eTexID { TANK_BASE_TEX, TANK_TURRET_TEX, BOULDER_TEX };
#pragma endregion

#pragma region Tank
#define TANK_MOVE_SPEED 115
#define TANK_TURN_SPEED 2.5f
#define TANK_TURRET_TURN_SPEED 1.8f
#pragma endregion
