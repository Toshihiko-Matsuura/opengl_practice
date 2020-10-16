#include <GLUT/glut.h>
#include <stdlib.h>

int wide = 10;

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
  glVertex2i(200 + (650 - 200) * wide / 100, 400);
  glVertex2i(200 + (650 - 200) * wide / 100, 400 - (400 - 100) * wide / 100 );
  glEnd();

  base_design();

  glFlush();

}

void timer(int value) {
  wide += 1;
  glutPostRedisplay(); //画面を再描写
  glutTimerFunc(100, timer, 0);
  if(wide > 100){
    wide = 0;
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
