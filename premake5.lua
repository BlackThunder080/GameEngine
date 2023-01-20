workspace "GameEngine"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Runtime"

outputdir = "%{cfg.shortname}-%{cfg.system}-%{cfg.architecture}/"

group "Dependancies"
    include "Engine"
    include "Runtime"
    include "vendor/glfw"

group ""