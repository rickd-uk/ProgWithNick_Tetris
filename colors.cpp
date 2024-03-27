#include "colors.h"

#include <vector>

constexpr int OPAQUE = 255;

const Color darkGray = {26, 31, 40, OPAQUE};
const Color green = {47, 230, 23, OPAQUE};
const Color red = {232, 18, 18, OPAQUE};
const Color orange = {236, 116, 17, OPAQUE};
const Color yellow = {237, 234, 4, OPAQUE};
const Color purple = {166, 0, 247, OPAQUE};
const Color cyan = {21, 204, 209, OPAQUE};
const Color blue = {13, 64, 216, OPAQUE};
const Color lightBlue = {59, 85, 162, OPAQUE};
const Color darkBlue = {44, 44, 127, OPAQUE};

std::vector<Color> GetCellColors() {
  return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}
