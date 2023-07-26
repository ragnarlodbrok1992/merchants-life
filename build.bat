@echo off
SET compiler_dir="C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe"

SET header_file_glfw3="D:\libraries\glfw-3.3.8\include"
SET header_file_glad="D:\libraries\glad\include"
SET lib_file_glfw="D:\libraries\glfw-3.3.8\build\src\Debug\glfw3.lib"
SET glad_main_file="D:\libraries\glad\src\glad.c"

REM /Wall - disabling for now @TODO: make warning sensible
REM /link /LIBPATH:%lib_file_glfw%^
REM /link /verbose:lib^

%compiler_dir% /EHsc /Zi /MDd^
 /DEBUG:FULL^
 /INCREMENTAL:NO^
 /Fe:"merchants-life"^
 %glad_main_file%^
 src/main.cpp^
 src/shader.cpp^
 /I%header_file_glfw3% /I%header_file_glad%^
 OpenGL32.lib User32.lib gdi32.lib Shell32.lib %lib_file_glfw%^

