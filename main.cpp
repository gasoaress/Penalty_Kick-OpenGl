#ifdef _APPLE_
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
float alpha = 30;
float beta = 0;
float delta = 1;
float x1 = 1.0;
float y1 = 1.0;
float z1 = 1.0;
float bola_z = 3, bola_x = 0, bola_y = 0.4;
float cuboX = 0.0f;
float cubeZ = -8.0;
float cubeSpeed = 0.1f;
int chutes = 0, n_gols = 0, erros = 0;
float sombra_x = 0, sombra_y = -0.5, sombra_z = 3;
bool animation = true, firstexe = true, entrou = false, fora = false, movimentou = false, cubeMovingRight = true;

// Vetor de translacao
GLsizei rsize = 50;
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
GLfloat windowWidth;
GLfloat windowHeight;

void Init()
{
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-8, 8, -8, 8, -8, 8);
}

void RestartInicio()
{
    alpha = 30;
    beta = 0;
    delta = 1;
    x1 = 1.0;
    y1 = 1.0;
    z1 = 1.0;
    bola_z = 3, bola_x = 0, bola_y = 0.4;
    sombra_x = 0, sombra_y = -0.5, sombra_z = 3;
    chutes = 0, n_gols = 0, erros = 0;

    animation = false, firstexe = true, entrou = false, fora = false, movimentou = false;

    // Vetor de translacao
    rsize = 50;
    xstep = 3.0f;
    ystep = 3.0f;
}

void RestartPosGol(int value)
{
    animation = true, firstexe = true, entrou = false, fora = false;
    x1 = 1.0;
    y1 = 1.0;
    z1 = 1.0;
    bola_z = 3;
    bola_x = 0;
    bola_y = 0.4;
    cuboX = 0;
    sombra_x = 0, sombra_y = -0.5, sombra_z = 3;
    glutPostRedisplay();
}

void Errou()
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(-0.3, 2.5, 0); // BARRA ESQ O
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(0.3, 2.5, 0); // BARRA DIR O
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();
}

void Gol()
{
    // G
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslated(-1.3, 2.5, 0); // BARRA ESQ G
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslated(-0.7, 0.2, 0); // BARRA MENOR DIREITA G
    glScalef(0.35, 18, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix(); // BARRA INFERIOR G
    glColor3f(1, 1, 0);
    glTranslated(-1, 2, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix(); // BARRA SUPERIOR G
    glColor3f(1, 1, 0);
    glTranslated(-1.1, 8, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix(); // BARRA SUPERIOR G
    glColor3f(1, 1, 0);
    glTranslated(-0.9, 4.2, 0);
    glScalef(0.5, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslated(-1.2, -1.4, 0);
    glScalef(0.3, 1, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslated(-2.7, -2, 0);
    glScalef(0.6, 0.3, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    // O

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslated(-0.3, 2.5, 0); // BARRA ESQ O
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslated(0.3, 2.5, 0); // BARRA DIR O
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix(); // BARRA INFERIOR 0
    glColor3f(1, 1, 0);
    glTranslated(0, 2, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix(); // BARRA SUPERIOR 0
    glColor3f(1, 1, 0);
    glTranslated(0, 7, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    // L
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslated(0.8, 2.5, 0); // BARRA ESQ L
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix(); // BARRA INFERIOR 0
    glColor3f(1, 1, 0);
    glTranslated(1, 2, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();
}

void Cubo_Timer(int value)
{
    if (cubeMovingRight)
    {
        cuboX += cubeSpeed;
        if (cuboX > 3.0f)
        {
            cuboX = 3.0f;
            cubeMovingRight = false;
        }
    }
    else
    {
        cuboX -= cubeSpeed;
        if (cuboX < -3.0f)
        {
            cuboX = -3.0f;
            cubeMovingRight = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, Cubo_Timer, 0);
}
/* void UpdateCubePosition()
{
    if (cubeMovingRight)
    {
        cuboX += cubeSpeed;
        if (cuboX > 3.0f)
        {
            cuboX = 3.0f;
            cubeMovingRight = false;
        }
    }
    else
    {
        cuboX -= cubeSpeed;
        if (cuboX < -3.0f)
        {
            cuboX = -3.0f;
            cubeMovingRight = true;
        }
    }
} */

void Verifica_Gol()
{
    if (bola_z <= -8)
    {
        animation = false;
        if (bola_x < -2.5 || bola_x > 2.5)
        { // VERIFICA SE A BOLA FOI PARA FORA
            chutes++;
            printf("CHUTES %d\n", chutes);
            animation = false, movimentou = false, fora = true;
            erros++;
            printf("erros %d\n", erros);
            return;
        }
        if (bola_x <= cuboX + 0.5 && bola_x >= cuboX - 0.5)
        {
            chutes++;
            animation = false, firstexe = false, movimentou = false, fora = true;
            erros++;
            printf("CUBO");
            return;
        }
        if (bola_x >= -2.5 && bola_x <= 2.5)
        { // VERIFICA SE A BOLA ENTROU
            animation = false, movimentou = false, entrou = true;
            chutes++;
            printf("CHUTES %d\n", chutes);
            n_gols++;
            printf("GOLS %d\n", n_gols);
            return;
        }
    }
}

void Animacao(int value)
{

    if (!animation)
    {
        glutTimerFunc(600, RestartPosGol, 0);
        return;
    }
    if (animation)
    {
        bola_z -= 0.2, sombra_z -= 0.2;
        Verifica_Gol();

        glutPostRedisplay();
        glutTimerFunc(16, Animacao, 0);
    }
}

void DesenhaTexto(void *font, char *string)
{
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);
    glColor3f(1, 1, 1);

    glPushMatrix();
    // CUBO
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0, 1, 0.5);
    glTranslatef(cuboX, -1, cubeZ);
    glScalef(1.0f, 1.0f, 1.0f);
    glutSolidCube(1.0f);

    glPopMatrix();

    glPushMatrix();                             // MARCA PENALTI
    glTranslatef(sombra_x, sombra_y, sombra_z); // Use as coordenadas (x1, y1, z1)
    glColor3f(0, 0, 0);
    // glTranslatef(0,10.0,0);
    glutSolidSphere(0.6f, 40, 20);
    glPopMatrix();

    glPushMatrix();                       // BOLA
    glTranslatef(bola_x, bola_y, bola_z); // Use as coordenadas (x1, y1, z1),
    glColor3f(1, 1, 1);
    glutSolidSphere(0.5, 40, 20);
    glPopMatrix();

    // glTranslatef(0,10.0,0);
    glLineWidth(5);
    glBegin(GL_LINES); // GOL

    glVertex3f(3, -0.9, -7);
    glVertex3f(3, 4.1, -7);
    //
    glVertex3f(3, 4, -7);
    glVertex3f(-3, 4, -7);
    //
    glVertex3f(-3, -0.9, -7);
    glVertex3f(-3, 4.1, -7);

    glVertex3f(3.5, 0, -7); // LINHA AREA TRAVE DIREITA
    glVertex3f(3.5, 0, -3);

    glVertex3f(3.5, -0.05, -3); // LINHA AREA MEIO
    glVertex3f(-3.5, -0.05, -3);

    glVertex3f(-3.5, -0.05, -7); // LINHA AREA TRAVE ESQ
    glVertex3f(-3.5, -0.05, -3);

    glVertex3f(-5.5, -0.05, -7); // LINHA DE FUNDO
    glVertex3f(5.5, -0.05, -7);
    glEnd();

    glTranslatef(0, -1, -2); // CAMPO
    glScalef(4, 0.6f, 4);
    glColor3f(0, 0.5, 0);
    glutSolidCube(3.0f);

    if (entrou)
        Gol();
    if (fora)
        Errou();

    glPushMatrix(); // PALAVRAS
    char n_gols_str[100], erros_str[100], chutes_str[100];
    sprintf(n_gols_str, "%d", n_gols);
    sprintf(erros_str, "%d", erros);
    sprintf(chutes_str, "%d", chutes);
    float z = -1.5; // Ajuste o valor para controlar o tamanho da fonte
    glColor3f(0.3, 0.2, 0.9);
    glRasterPos3d(-1.35, 5, z);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "CHUTES: ");
    glRasterPos3d(-0.92, 5, z); // Ajuste a posi��o x conforme necess�rio
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, chutes_str);

    glRasterPos3d(-1.35, 4, z); // Posi��o inicial da palavra
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "GOLS: ");
    glRasterPos3d(-1, 4, z);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, n_gols_str);

    glRasterPos3d(-1.35, 3, z);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "ERROS: ");
    glRasterPos3d(-0.95, 3, z); // Ajuste a posi��o x conforme necess�rio
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, erros_str);
    glPopMatrix();

    glutSwapBuffers();
}

void listeningSpKey(GLint tecla, GLint x, GLint y)
{
    switch (tecla)
    {
    case GLUT_KEY_UP:
        alpha = alpha - 1;
        break;
    case GLUT_KEY_DOWN:
        alpha = alpha + 1;
        break;
    case GLUT_KEY_LEFT:
        beta = beta + 1;
        break;
    case GLUT_KEY_RIGHT:
        beta = beta - 1;
        break;
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        delta = delta * 1.1f;

    if (key == 'w' || key == 'W')
        delta = delta * 0.9f;

    if (key == 'c' || key == 'C')
        system("C:\\Projetos\\nome\\bin\\Debug\\nome.exe");

    if (key == 'a' || key == 'A')
    {
        if (bola_x > -5 && !movimentou && bola_z > -8)
            bola_x -= 0.5, sombra_x -= 0.5;
        printf("BOLA X %f\n", bola_x);
    }
    if (key == 'd' || key == 'D')
    {
        if (bola_x < 5 && !movimentou && bola_z > -8)
            bola_x += 0.5, sombra_x += 0.5;
        printf("BOLA X %f\n", bola_x);
    }
    if (key == 'r' || key == 'R')
        RestartInicio();

    if (key == 27)
        exit(0);

    if (key == ' ')
        if (firstexe == true)
        {
            firstexe = false;
            movimentou = true;
            glutTimerFunc(0, Animacao, 0);
        }
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("FUTGLUT - GABRIEL LEITE");
    gluOrtho2D(0.0, 400, 0.0, 600);
    Init();

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);

    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glEnable(GL_NORMALIZE);

    glutTimerFunc(0, Cubo_Timer, 0);

    glutMainLoop();
}
