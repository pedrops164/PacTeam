#ifndef _DIRECTION_

#define _DIRECTION_

#pragma once

enum Direction { Up = 0, Down, Right, Left, Null };

Direction opposite(Direction direction);

#endif