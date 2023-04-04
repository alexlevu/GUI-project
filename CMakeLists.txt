cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME TemplateSFML)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MovingObject.cpp MovingObject.h ShadowBox.cpp ShadowBox.h Typing.cpp Typing.h Key.h MultiText.cpp MultiText.h Letter.cpp Letter.h TextInput.cpp TextInput.h State.h States.cpp States.h SnapShotInterface.cpp SnapShotInterface.h SnapShot.cpp SnapShot.h DropDownMenu.cpp DropDownMenu.h MenuOptions.cpp MenuOptions.h KeyBoardShortcut.cpp KeyBoardShortcut.h Menu.cpp Menu.h NAryTree.cpp NAryTree.h Node.h FileItem.cpp FileItem.h ImageName.h Images.cpp Images.h FileMenu.cpp FileMenu.h FinalFilesMenu.cpp FinalFilesMenu.h LabelMakerScreen.cpp LabelMakerScreen.h DraggingUI.cpp DraggingUI.h ColorGradient.cpp ColorGradient.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT F:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()