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
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"%{prj.name}/vendor/spdlog/include"
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
			symbols "On"

		filter "configurations:Release"
			defines {"ADK_RELEASE", "_DEBUG"}
			optimize "On"

		filter "configurations:Dist"
			defines {"ADK_DIST", "NDEBUG"}
			optimize "On"

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

		filter "configurations:Release"
			defines {"ADK_RELEASE", "_DEBUG"}
			optimize "On"

		filter "configurations:Dist"
			defines {"ADK_DIST", "NDEBUG"}
			optimize "On"