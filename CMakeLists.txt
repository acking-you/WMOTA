cmake_minimum_required(VERSION 3.16)
project(WMOTA C)

set(CMAKE_C_STANDARD 99)

add_executable(WMOTA main.c Base.c Base.h Hero.c Hero.h color.h Scene.c Scene.h RedSlime.c RedSlime.h print_qrcode.h GreenSlime.c GreenSlime.h BAT.c BAT.h Fight.h Master.c Master.h Skull.c Skull.h Key.c Key.h Door.c Door.h Medicine.c Medicine.h Stone.c Stone.h Transform.c Transform.h Weapon.c Weapon.h MonMap.c MonMap.h)