#pragma once

namespace BULLET
{
	enum ID {��, ��, ��, ��, ��};
}
namespace OBJ
{
	enum ID {OBJ_MONSTER, OBJ_PLAYER, OBJ_BULLET, OBJ_SHIELD, OBJ_MOUSE, OBJ_END};
	enum STATE {PLAYER_RUN, PLAYER_SLIDE, PLAYER_RUSH, PLAYER_JUMP, PLAYER_DOUBLEJUMP, PLAYER_PAIN, PLAYER_DIE};
}

namespace MAP {
	enum ID {MAP_BLOCK, MAP_OBSTACLE, MAP_COIN, MAP_JELLY, MAP_END};
	//enum ID {MAP_BLOCK, MAP_END};
}