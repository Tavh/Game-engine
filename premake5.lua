startproject "sandbox"

workspace "sky_engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "sky_engine/vendor/GLFW/include"

include "sky_engine/vendor/GLFW"

project "sky_engine"
    location "sky_engine"
    kind "SharedLib" -- Specifies that this project produces a dynamic linked library (dll)
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "skypch.h"
    pchsource "sky_engine/src/skypch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SKY_PLATFORM_WINDOWS",
            "SKY_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
        }

    filter "configurations:Debug"
        defines "SKY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SKY_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SKY_DIST"
        optimize "On"

project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "sky_engine/vendor/spdlog/include",
        "sky_engine/src"
    }

    links
    {
        "sky_engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SKY_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SKY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SKY_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SKY_DIST"
        optimize "On"