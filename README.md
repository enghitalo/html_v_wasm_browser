`git submodule init . && git submodule add https://github.com/floooh/sokol external_lib/sokol`

`git submodule add https://github.com/emscripten-core/emscripten external_lib/emscripten`

`git submodule update --init --recursive` update sokol lib

```bash
git submodule [--quiet] [--cached]
   or: git submodule [--quiet] add [-b <branch>] [-f|--force] [--name <name>] [--reference <repository>] [--] <repository> [<path>]
   or: git submodule [--quiet] status [--cached] [--recursive] [--] [<path>...]
   or: git submodule [--quiet] init [--] [<path>...]
   or: git submodule [--quiet] deinit [-f|--force] (--all| [--] <path>...)
   or: git submodule [--quiet] update [--init [--filter=<filter-spec>]] [--remote] [-N|--no-fetch] [-f|--force] [--checkout|--merge|--rebase] [--[no-]recommend-shallow] [--reference <repository>] [--recursive] [--[no-]single-branch] [--] [<path>...]
```

`gcc external_lib/sokol/tests/compile/sokol_app.c -o meu_app -I ./external_lib/sokol -I ./external_lib/sokol/util -Lexternal_lib -lEGL -lX11 -lXi -lXcursor -lEGL -lGL -ldl -pthread -lm`

```
    On Linux, SOKOL_GLCORE33 can use either GLX or EGL.

    Link with the following system libraries:
    - on Linux with EGL: X11, Xi, Xcursor, EGL, GL (or GLESv2), dl, pthread, m(?)
    - on Linux with GLX: X11, Xi, Xcursor, GL, dl, pthread, m(?)

    On Linux, you also need to use the -pthread compiler and linker option, otherwise weird
    things will happen, see here for details: https://github.com/floooh/sokol/issues/376
```

`emcc sokol_app.c -o build/sokol_app.html --shell-file=shell_minimal.html -I ./external_lib/sokol -I ./external_lib/sokol/util -Lexternal_lib -sUSE_WEBGL2 && python3 -m http.server -d build`
`gcc sokol_sapp.c -o build/meu_app -I ./external_lib/sokol -I ./external_lib/sokol/util -Lexternal_lib -lEGL -lX11 -lXi -lXcursor -lEGL -lGL -ldl -pthread -lm `

#### Install

`sudo apt-get install emscripten`

```sh
> emcc bufferoffsets-emsc.c -o build/bufferoffsets-emsc.html  -I ./external_lib/sokol -I ./external_lib/sokol/util -Lexternal_lib -sUSE_WEBGL2 --shell-file=shell_minimal.html
> emrun build/bufferoffsets-emsc.html
> python3 -m http.server -d build
```
