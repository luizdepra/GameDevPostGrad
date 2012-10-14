#ifndef ROTATINGTRIANGLE_H_INCLUDED
#define ROTATINGTRIANGLE_H_INCLUDED
#include "GameSteps.h"
#include "AstronomicalObject.h"

class Game : public GameSteps
{
    private:
        bool exit;

        AstronomicalObject _sun;
        AstronomicalObject _planet;
        AstronomicalObject _moon;

    public:
        explicit Game() : exit(false) {}

        virtual void setup();

        virtual void processEvents(const SDL_Event& event);
        virtual void processLogics(float secs);
        virtual void draw() const;

        virtual bool ended() { return exit; }

        virtual void teardown();

};

#endif // ROTATINGTRIANGLE_H_INCLUDED
