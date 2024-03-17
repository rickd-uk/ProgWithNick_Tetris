#include "position.h"

Position::Position(int row, int col) : row(row), col(col) {}

int Position::GetRow() const { return row; }

int Position::GetCol() const { return col; }
