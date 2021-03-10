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
IncludeDir["Glad"] = "Nerthus/vendor/Glad/include"

include "Nerthus/vendor/GLFW"
include "Nerthus/vendor/Glad"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad",
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
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "NT_DEBUG"
        buildoptions "/MDd"
        symbols "On"
        
    filter "configurations:Release"
        defines "NT_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Final"
        defines "NT_FINAL"
        buildoptions "/MD"
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
        buildoptions "/MDd"
        symbols "On"
        
    filter "configurations:Release"
        defines "NT_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Final"
        defines "NT_FINAL"
        buildoptions "/MD"
        optimize "On"