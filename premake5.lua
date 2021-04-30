workspace "AdakiteEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "AdakiteEngine"
		location "AdakiteEngine"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/src/**.c"

		}

		includedirs{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{prj.name}/vendor/GLFW/include"
		}

		links{
			"glfw3.lib",
			"opengl32.lib"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines{
				"ADK_PLATFORM_WINDOWS",
				"ADK_BUILD_DLL",
				"_CONSOLE"
			}

			postbuildcommands{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines {"ADK_DEBUG", "_DEBUG"}
			buildoptions "/MTd"
			symbols "On"
			libdirs "%{prj.name}/vendor/GLFW/libsD"

		filter "configurations:Release"
			defines {"ADK_RELEASE", "_DEBUG"}
			buildoptions "/MTd"
			optimize "On"
			libdirs "%{prj.name}/vendor/GLFW/libsD"

		filter "configurations:Dist"
			defines {"ADK_DIST", "NDEBUG"}
			buildoptions "/MT"
			optimize "On"
			libdirs "%{prj.name}/vendor/GLFW/libs"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"AdakiteEngine/vendor/spdlog/include",
			"AdakiteEngine/src"
		}

		links{
			"AdakiteEngine"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines{
				"ADK_PLATFORM_WINDOWS",
				"_CONSOLE"
			}

		filter "configurations:Debug"
			defines {"ADK_DEBUG", "_DEBUG"}
			symbols "On"
			buildoptions "/MTd"

		filter "configurations:Release"
			defines {"ADK_RELEASE", "_DEBUG"}
			optimize "On"
			buildoptions "/MTd"

		filter "configurations:Dist"
			defines {"ADK_DIST", "NDEBUG"}
			optimize "On"
			buildoptions "/MT"