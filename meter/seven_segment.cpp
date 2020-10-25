#include <GLUT/glut.h>
#include "seven_segment.hpp"

void SevenSegment::draw_horizontal(int pos_x, int pos_y, bool fill=false){
  if (fill){
    glBegin(GL_POLYGON);
  } else {
	glBegin(GL_LINE_LOOP);
  }
  glVertex2i(pos_x, pos_y + 5);
  glVertex2i(pos_x + 5, pos_y);
  glVertex2i(pos_x + 25, pos_y);
  glVertex2i(pos_x + 30, pos_y + 5);
  glVertex2i(pos_x + 25, pos_y + 10);
  glVertex2i(pos_x + 5, pos_y + 10);
  glEnd();
}

void SevenSegment::draw_vertical(int pos_x, int pos_y, bool fill=false){
  if (fill){
    glBegin(GL_POLYGON);
  } else {
	glBegin(GL_LINE_LOOP);
  } 
  glVertex2i(pos_x + 5, pos_y);
  glVertex2i(pos_x, pos_y + 5);
  glVertex2i(pos_x, pos_y + 25);
  glVertex2i(pos_x + 5, pos_y + 30);
  glVertex2i(pos_x + 10, pos_y + 25);
  glVertex2i(pos_x + 10, pos_y + 5);
  glEnd();
}

void SevenSegment::seven_segment_unit(int pos_x, int pos_y, bool *fill_list){
  draw_horizontal(10, 0, fill_list[0]);
  draw_horizontal(10, 40, fill_list[1]);
  draw_horizontal(10, 80, fill_list[2]);
  draw_vertical(0, 10, fill_list[3]);
  draw_vertical(40, 10, fill_list[4]);
  draw_vertical(0, 50, fill_list[5]);
  draw_vertical(40, 50, fill_list[6]);
}
