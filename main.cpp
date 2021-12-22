#include "FundLibs/BarakWinHelper/Barak.h"

//you should include glad 4.6

void prepr(hWindow* g_Win){
	g_Win->setXY(CW_USEDEFAULT, CW_USEDEFAULT);
	g_Win->setWH(512, 512);
	g_Win->rename(L"Graphical panel");
}

int main() {

	while (threadIsLive()) {
		//begin of writing your renderer

		static float theta = 0;
		theta += 0.05;

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);

		glPushMatrix();
		glRotatef(theta, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f, -0.5f);
		glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

		glEnd();

		glPopMatrix();

		//end of writing your renderer

		SwapBuffers();
	}
	return 99;
}