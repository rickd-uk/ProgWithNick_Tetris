#pragma once

#ifndef POSITION_H
#define POSITION_H

class Position {
 public:
  Position(int row, int col);
  int getRow() const;
  int getCol() const;

 private:
  int row;
  int col;
};

#endif
