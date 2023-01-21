project "Engine"
    language "C++"
    kind "StaticLib"
    cppdialect "C++20"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "%{prj.name}")
    objdir    ("%{wks.location}/obj/" .. outputdir .. "%{prj.name}")

    files {
        "src/**.cpp",
        "src/*.hpp",
        "src/**.c",
        "src/*.h",
    }

    includedirs {
        "%{prj.location}/src",
        "%{wks.location}/vendor/GLFW/include",
        "%{wks.location}/vendor/glad/include",
    }

    links {
        "GLFW",
        "Glad",
        "opengl32",
    }

    filter "configurations:Debug"
        symbols "On"
    
    filter "configurations:Release"
        optimize "On"
