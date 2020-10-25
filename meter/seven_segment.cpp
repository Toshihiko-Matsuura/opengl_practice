#include <GLUT/glut.h>
#include "seven_segment.hpp"

void SevenSegment::draw_horizontal(int pos_x, int pos_y, bool fill=false){
  if (fill){
    glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 1.0);
  } else {
	glBegin(GL_LINE_LOOP);
	glColor3d(0.2, 0.2, 0.2);
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
	glColor3d(1.0, 1.0, 1.0);
  } else {
	glBegin(GL_LINE_LOOP);
	glColor3d(0.2, 0.2, 0.2);
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
  draw_horizontal(pos_x + 10, pos_y, fill_list[0]);
  draw_horizontal(pos_x + 10, pos_y + 40, fill_list[1]);
  draw_horizontal(pos_x + 10, pos_y + 80, fill_list[2]);
  draw_vertical(pos_x, pos_y + 10, fill_list[3]);
  draw_vertical(pos_x + 40, pos_y + 10, fill_list[4]);
  draw_vertical(pos_x, pos_y + 50, fill_list[5]);
  draw_vertical(pos_x + 40, pos_y + 50, fill_list[6]);
}
