/*
    On Linux, SOKOL_GLCORE33 can use either GLX or EGL.

    Link with the following system libraries:
    - on Linux with EGL: X11, Xi, Xcursor, EGL, GL (or GLESv2), dl, pthread, m(?)
    - on Linux with GLX: X11, Xi, Xcursor, GL, dl, pthread, m(?)

    On Linux, you also need to use the -pthread compiler and linker option, otherwise weird
    things will happen, see here for details: https://github.com/floooh/sokol/issues/376
*/

#define SOKOL_IMPL
#define SOKOL_GLES3

#include "sokol_app.h"

void use_app_impl(void)
{
    sapp_run(&(sapp_desc){0});
}

#if defined(SOKOL_DUMMY_BACKEND)
int main() {
    return 0;
}
#else
sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    return (sapp_desc){0};
}
#endif
