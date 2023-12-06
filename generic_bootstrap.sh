#!/bin/bash
# This script allow to launch a cmake configuration for every possible project


# Method that print help in console
print_help()
{
        echo -e "############################### SCRIPT HELP ############################################################"
        echo
        echo -e "\e[0;37mThe role of this script is to help you configure your build with cmake.\e[0m"
        echo
        echo -e "\e[0;37mIt must be used with the following arguments:\e[0m"
        echo -e "\e[0;37m	--cmake_variables (optional) : The path to a cmake variables file\e[0m"
        echo -e "\e[0;37m	--sources (optional, default .) : The path to source dir\e[0m"
        echo -e "\e[0;37m	--build_type : (optional, default Debug) : Release or Debug\e[0m"
        echo -e "\e[0;37m	--build_target (optional, default ./builds/\${build_type}) : path to build directory\e[0m"
        echo -e "\e[0;37m	--coverage (optional, default OFF) : if you want to build with coverage config\e[0m"
        echo -e "\e[0;37m	--doc (optional, default OFF) : if you want to build documentation (doxygen)\e[0m"
        echo -e "\e[0;37m	--shared (optional, default OFF) : if you want to build shared lib (and not static)\e[0m"
        echo
        echo
        echo -e "\e[0;37mExample of usage :\e[0m	\e[0;32mgeneric_bootstratp.sh --cmake_variables project-cmake-variables.cmake \e[0m"
        echo
        echo
        echo -e "########################################################################################################"
}

if [ "$1" = "--help" ]; then
        print_help
        exit
fi

while [ $# -ne 0 ]
do
        arg=$1
        shift

        case $arg in
                "--sources")
                        sources="$1"
                        shift
                        ;;
		"--build_type")
                        build_type="$1"
                        shift
                        ;;
		"--build_target")
                        build_target="$1"
                        shift
                        ;;
		"--cmake_variables")
                        cmake_variables_file="$1"
                        shift
                        ;;
                "--coverage")
                        coverage="ON"
                        ;;
                "--doc")
                        doc="ON"
                        ;;
                "--shared")
                        shared="ON"
                        ;;
                *)
                        echo "unknown argument $arg" >&2
                        exit 1
        esac
done

sources=${sources:-.}
build_type=${build_type:-Debug}
build_target_tmp=${build_target:-builds}
build_target=${build_target_tmp}/${build_type}
coverage=${coverage:-OFF}
doc=${doc:-OFF}
shared=${shared:-OFF}
install_target=${build_target}/install
cmake_variables_file_command=${-C cmake_variables_file:-''}

cmake -S ${sources} \
	-B ${build_target} \
	-D CMAKE_BUILD_TYPE="${build_type}" \
	-D CMAKE_INSTALL_PREFIX="${install_target}" \
	-D ENABLE_COVERAGE=${coverage} \
	-D ENABLE_DOC=${doc} \
	-D BUILD_SHARED_LIBS=${shared} \
	${cmake_variables_file_command:''}
    #--trace

