# NuGet
Install [libtorrent-net](https://www.nuget.org/packages/libtorrent-net/)
```Powershell
PM> Install-Package libtorrent-net
```

# Building

```
Download and install Microsoft Visual Studio 2017 and C++ tools with Windows 10 SDK 10.0.16299.15.

1/ BOOST
Download and extract Boost 1.67 to C:\boost_1_67_0
Go to C:\boost_1_67_0 and execute "bootstrap.bat", then ".\b2 --toolset=msvc-14.1 architecture=x86"
Add BOOST_ROOT (C:\boost_1_67_0), BOOST_BUILD_PATH (C:\boost_1_67_0\tools\build) to Environment path and C:\boost_1_67_0 to Path

2/ Libtorrent
Download and extract libtorrent-rasterbar 1.1.7 (https://github.com/arvidn/libtorrent/releases) to C:\libtorrent-libtorrent-1_1_7
Compile libtorrent using "bjam link=static variant=release boost-link=static architecture=x86 logging=off asserts=off invariant-checks=off deprecated-functions=off toolset=msvc-14.1"

3/ Ltnet
Open solution, set Release/x86, build.
```

# Usage

* Include the library as a reference to any .NET project and simply use the libtorrent API.

**Don't forget to include all the dlls from the "vc_150_redist_x86_windows_SDK_10.0.16299.15" folder in the same folder of the binary of your application.**
