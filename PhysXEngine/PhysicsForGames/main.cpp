#include "PhysicsApplication.h"

int main()
{
	PhysicsApplication app;

    if (app.Startup() == false)
    {
        return -1;
    }

    while (app.Update() == true)
    {
        app.Draw();
    }

    app.Shutdown();

    return 0;
}