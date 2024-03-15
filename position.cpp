#include "position.h"

Position::Position(int row, int col) : row(row), col(col) {}

int Position::getRow() const { return row; }

int Position::getCol() const { return col; }
