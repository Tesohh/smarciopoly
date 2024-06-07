#ifndef SMARCIOMATH_HPP
#define SMARCIOMATH_HPP
#include "raylib.h"
#include <string>

Rectangle RotateRectangle(Rectangle rectangle, float rotation);
void DebugRectangle(Rectangle r, std::string prefix = "");

#endif
