`v -skip-unused -prod -os wasm32_emscripten main.v -o main.c`
`v -showcc -skip-unused -prod -os wasm32_emscripten main.v`
`emcc main.c -o build/sokol_app.html -D SOKOL_GLES3 -D SOKOL_NO_ENTRY -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s USE_WEBGL2 -I "/home/hitalo/v/thirdparty/sokol" -I "/home/hitalo/v/thirdparty/sokol/util" -I "/home/hitalo/v/thirdparty/fontstash"  -std=c99 -D_DEFAULT_SOURCE -lm`
`python3 -m http.server -d build`
