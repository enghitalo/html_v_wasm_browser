#define SOKOL_IMPL
#define SOKOL_GLES3
#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_log.h"
#include "sokol_glue.h"
// EMSCRIPTEN_KEEPALIVE

// void runSokolApp()
// {
//     sapp_run(&(sapp_desc){/* your configuration here */});
// }

// user-provided callback prototypes
int sapp_width(void);
int sapp_height(void);

/*
    The typical debug UI overlay useful for most sokol-app samples
*/

static inline void __dbgui_setup(int sample_count) { (void)(sample_count); }
static inline void __dbgui_shutdown(void) {}
static inline void __dbgui_draw(void) {}
static inline void __dbgui_event(const sapp_event *e) { (void)(e); }
static inline bool __dbgui_event_with_retval(const sapp_event *e)
{
    (void)(e);
    return false;
}

sg_pass_action pass_action;

void init(void)
{
    sg_setup(&(sg_desc){
        .context = sapp_sgcontext(),
        .logger.func = slog_func,
    });
    pass_action = (sg_pass_action){
        .colors[0] = {
            .load_action = SG_LOADACTION_CLEAR,
            .clear_value = {1.0f, 0.0f, 0.0f, 1.0f}}};
    __dbgui_setup(sapp_sample_count());
}

void frame(void)
{
    float g = pass_action.colors[0].clear_value.g + 0.01f;

    pass_action.colors[0].clear_value.g = (g > 1.0f) ? 0.0f : g;

    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());

    __dbgui_draw();
    sg_end_pass();
    sg_commit();
}

void cleanup(void)
{
    __dbgui_shutdown();
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = __dbgui_event,
        .width = 1280,
        .height = 720,
        .window_title = "Clear (sokol app)",
        .icon.sokol_default = true, // Reutileza o ícone no browser <3
        .logger.func = slog_func,
    };
}
