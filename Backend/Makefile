local_libs=/app/libraries/vcpkg_installed/x64-linux
local_versioner=/app/libraries/vcpkg

all: versioner_libs

configure:
	echo "Running compiler"
	build_project

build_project:
	cmake CMakeLists.txt && \
	make all && \
	make Application


versioner_libs:
	git clone https://github.com/Microsoft/vcpkg.git ${local_versioner} && \
	${local_versioner}/bootstrap-vcpkg.sh && \
	echo "-DCMAKE_TOOLCHAIN_FILE=/app/libraries/vcpkg/scripts/buildsystems/vcpkg.cmake" > ${local_versioner}/CMAKE.txt && \
	cd ${local_versioner} && ./vcpkg integrate install && \
	cd /app/libraries && ./vcpkg/vcpkg install