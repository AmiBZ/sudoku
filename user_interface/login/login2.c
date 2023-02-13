
#include "SDL.h"

extern void InitVideo();
extern void Redraw();

int main(int argc, char *argv[])
{

    SDL_ShowSimpleMessageBox();
    SDL_Quit();

    return 0;
}
