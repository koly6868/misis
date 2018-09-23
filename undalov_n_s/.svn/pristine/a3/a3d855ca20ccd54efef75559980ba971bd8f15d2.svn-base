if NOT EXIST build.vc2015.win64 mkdir build.vc2015.win64
pushd build.vc2015.win64
call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x64
cmake -G"Visual Studio 14 2015 Win64" ..
msbuild polevoy_d_v.sln /property:Configuration=Debug /m
msbuild polevoy_d_v.sln /property:Configuration=Release /m
popd