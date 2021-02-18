workspace "Nerthus"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Final"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Nerthus/vendor/GLFW/include"

include "Nerthus/vendor/GLFW"

project "Nerthus"
    location "Nerthus"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ntpch.h"
    pchsource "Nerthus/src/ntpch.cpp"

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
            "NT_PLATFORM_WINDOWS", 
            "NT_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "NT_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "NT_RELEASE"
        optimize "On"

    filter "configurations:Final"
        defines "NT_FINAL"
        optimize "On"

project "Sandbox"
    location "Sandbox"
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
        "Nerthus/vendor/spdlog/include",
        "Nerthus/src"
    }

    links
    {
        "Nerthus"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NT_PLATFORM_WINDOWS", 
        }

    filter "configurations:Debug"
        defines "NT_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "NT_RELEASE"
        optimize "On"

    filter "configurations:Final"
        defines "NT_FINAL"
        optimize "On"