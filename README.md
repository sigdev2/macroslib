<p align="center">
    <img src="https://raw.githubusercontent.com/sigdev2/macroslib/master/icon.png" alt="Logo" width="64" height="64">
    <h3 align="center">MacrosLib</h3>
    <p align="center">Last version 0.1.0-b3</p>
</p>


## Table of Contents

* [About the Project](#about-the-project)
* [Usage](#usage)
* [Contribution](#contribution)
* [License](#license)


## About The Project

This project is a set of header files with macros for the C preprocessor.

The goal of this project is to collect solutions that speed up and simplify writing complex macros using variability, loops, recursion and conditions.

The project is being actively developed and supported. All macros have tests and documentation.

You can read [The Change history](./CHANGELOG)


## Usage

If you use this library in the project, then remember that macros may not work correctly in your version of the preprocessor, do first run the [test files](./tests/) in the environment and evaluate the results.

This project can be viewed as a memo with examples of the implementation of non-trivial solutions and other macros magic. Each macro has a doxygen description, where you can find out what the macro takes and returns, as well as implementation details.

Use with CMake:

    function(GIT_REPOSITORY TARGET GIT_FOLDER GIT_URL INCLUDE_PATH CHECK_FILE)
        find_path(MACROS_LIB_SOURCE NAMES macroslib.h PATHS ${CMAKE_CURRENT_SOURCE_DIR}${INCLUDE_PATH})

        if((NOT MACROS_LIB_SOURCE) OR (NOT EXISTS ${MACROS_LIB_SOURCE}))
            execute_process(COMMAND git clone ${GIT_URL} ${CMAKE_CURRENT_SOURCE_DIR}/${GIT_FOLDER}/)
        else()
            # execute_process(COMMAND git push WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${GIT_FOLDER}/)
            execute_process(COMMAND git pull WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${GIT_FOLDER}/)
        endif()
        target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}${INCLUDE_PATH})
    endfunction()
    ...
    add_executable(${RESULT_TARGET} main.cpp)
    ...
    git_repository(${RESULT_TARGET} macroslib https://github.com/sigdev2/macroslib.git /macroslib/src/ macroslib.h)


## Contribution

You can write about issues and errors in [issues](https://github.com/sigdev2/macroslib/issues) and send your fix as a [pull request](https://github.com/sigdev2/macroslib/pulls)


## License

Distributed under [the MIT License](./LICENSE).
