workspace "GameEngine"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Runtime"

outputdir = "%{cfg.shortname}-%{cfg.system}-%{cfg.architecture}/"

group ""
    include "Engine"
    include "Runtime"

group "Dependancies"
    include "vendor/glfw"
    include "vendor/glad"
