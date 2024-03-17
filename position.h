#pragma once

#ifndef POSITION_H
#define POSITION_H

class Position {
 public:
  Position(int row, int col);
  int GetRow() const;
  int GetCol() const;

 private:
  int row;
  int col;
};

#endif
