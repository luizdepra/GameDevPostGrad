#include "Game.h"
#include "GameWindow.h"

void Game::setup()
{
    _sun = AstronomicalObject(0.0f, 0.0f, 5.0f, 5.0f, 5.0f, 0.99f, 0.72f, 0.07f);
    _planet = AstronomicalObject(0.0f, 15.0f, 0.5f, 50.0f, 30.0f, 0.52f, 0.58f, 0.16f);
    _moon = AstronomicalObject(0.0f, 1.0f, 0.1f, 120.0f, 90.0f, 0.4f, 0.4f, 0.4f);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, GAMEWINDOW.getRatio(), 0.01f, 100.0f);
    gluLookAt(0.0f, 5.0f, 35.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f );
    glMatrixMode(GL_MODELVIEW);
}

void Game::processEvents(const SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            exit = true;
            break;
    }
}

void Game::processLogics(float secs)
{
    Uint8* keys = SDL_GetKeyState(NULL);

    _sun.processLogics(secs);
    _planet.processLogics(secs);
    _moon.processLogics(secs);
}

void Game::draw() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    _sun.draw();
    _planet.draw();
    _moon.draw();
}

void Game::teardown()
{
}
