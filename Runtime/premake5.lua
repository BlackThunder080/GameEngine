project "Runtime"
    language "C++"
    kind "ConsoleApp"
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
        "%{wks.location}/Engine/"
    }

    links {
        "Engine",
    }

    filter "configurations:Debug"
        symbols "On"
    
    filter "configurations:Release"
        optimize "On"
