//------------------------------------------------------------------------------
//  noentry-sapp.c
//
//  This demonstrates the SOKOL_NO_ENTRY mode of sokol_app.h, in this mode
//  sokol_app.h doesn't "hijack" the platform's main() function instead the
//  application must provide this. The sokol_app.h implementation must be
//  compiled with the SOKOL_NO_ENTRY define (see sokol-noentry.c/.m,
//  which is compiled into a static link lib sokol-noentry)
//
//  This sample also demonstrates the optional user-data callbacks.
//------------------------------------------------------------------------------

#define SOKOL_IMPL
#define SOKOL_GLES3
#define HANDMADE_MATH_IMPLEMENTATION
#define HANDMADE_MATH_NO_SSE
// #include "HandmadeMath.h"
#define SOKOL_DLL
#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include <stdlib.h> // calloc, free

// #include "noentry-dll-sapp.glsl.h"

sg_pass_action pass_action;
typedef struct
{
    float rx, ry;
    sg_pipeline pip;
    sg_bindings bind;
} app_state_t;

// user-provided callback prototypes
void init(void *user_data);
void frame(void *user_data);
void cleanup(void);

// don't provide a sokol_main() callback, instead the platform's standard main() function

sapp_desc sokol_main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    app_state_t *state = calloc(1, sizeof(app_state_t));

    sapp_run(&(sapp_desc){
        .user_data = state,
        .init_userdata_cb = init,
        .frame_userdata_cb = frame,
        .cleanup_cb = cleanup, // cleanup doesn't need access to the state struct
        .width = 800,
        .height = 600,
        .sample_count = 4,
        .window_title = "Noentry DLL (sokol-app)",
        // .logger.func = slog_func,
    });
    free(state); // NOTE: on some platforms, this isn't reached on exit

    return (sapp_desc){0};
}

void init(void *user_data)
{
    sg_setup(&(sg_desc){
        .context = sapp_sgcontext()});
}

void frame(void *user_data)
{
    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());
    sg_end_pass();
    sg_commit();
}

void cleanup(void)
{
    sg_shutdown();
}