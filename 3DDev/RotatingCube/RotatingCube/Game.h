#ifndef ROTATINGTRIANGLE_H_INCLUDED
#define ROTATINGTRIANGLE_H_INCLUDED
#include "GameSteps.h"

class Game : public GameSteps
{
    private:
        bool exit;

        float angle;

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
