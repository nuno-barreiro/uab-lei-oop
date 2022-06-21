cmake_minimum_required(VERSION 3.22)
project(af4)

set(CMAKE_CXX_STANDARD 11)

add_executable(af4 main.cpp Aluno.cpp Aluno.h ConjuntoAlunos.cpp ConjuntoAlunos.h Impressora.cpp Impressora.h)
