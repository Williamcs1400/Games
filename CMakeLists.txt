# cmake_minimum_required(VERSION <specify CMake version here>)
project(TAC_Jogos)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TAC_Jogos
        .idea/.gitignore
        .idea/misc.xml
        .idea/modules.xml
        .idea/TAC-Jogos.iml
        .idea/vcs.xml
        .idea/workspace.xml
        .vscode/c_cpp_properties.json
        .vscode/settings.json
        ColliderRender.cpp
        Collision.cpp
        Game.cpp
        Game.exe
        Game.h
        readme.md
        SDL_include.h
        StateInput.cpp)
