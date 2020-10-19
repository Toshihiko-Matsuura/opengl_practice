#include <GLUT/glut.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>

int speed_num = 0;
std::string speed_str;

GLuint base;

void drawBitmapString(void *font, std::string speed_str){
  glPushAttrib(GL_CURRENT_BIT);
  glScalef(1.2f, 1.2f, 0.0f);
  for(int i = 0; i < (int)speed_str.size(); i++){
    glutBitmapCharacter(font, speed_str[i]);
  }
  glScalef(-1.2f, -1.2f, 0.0);
  glPopAttrib(); 
}

void base_design(){
  glLineWidth(2.0);
  glColor3d(1.0, 1.0, 1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(200, 400);
  glVertex2i(650, 400);
  glVertex2i(650, 100);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex2i(150, 50);
  glVertex2i(600, 50);
  glVertex2i(150, 350);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex2i(670, 400);
  glVertex2i(780, 400);
  glVertex2i(780, 290);
  glVertex2i(670, 290);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex2i(20, 50);
  glVertex2i(130, 50);
  glVertex2i(130, 160);
  glVertex2i(20, 160);
  glEnd();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3d(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2i(200, 400);
  glVertex2i(200 + (650 - 200) * speed_num / 100, 400);
  glVertex2i(200 + (650 - 200) * speed_num / 100, 400 - (400 - 100) * speed_num / 100 );
  glEnd();

  base_design();

  glRasterPos2i(670, 400);
  speed_str = std::to_string(speed_num);
  drawBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, speed_str.c_str());
  
  glFlush();

}

void timer(int value) {
  speed_num += 1;
  glutPostRedisplay(); //画面を再描写
  glutTimerFunc(100, timer, 0);
  if(speed_num > 100){
    speed_num = 0;
  }
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 'q':
  case 'Q':
  case '\033':  /* '\033' は ESC の ASCII コード */
    exit(0);
  default:
    break;
  }
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(800, 450);
  glutCreateWindow("B-tech Meter");
  glutInitDisplayMode(GLUT_RGBA);
  glutDisplayFunc(display);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //背景色を設定
  gluOrtho2D(0, 800, 450, 0); // 座標系の設定
  glutKeyboardFunc(keyboard);
  glutTimerFunc(100, timer, 0); //timer()を実行
  glutMainLoop();
  return 0;
}
