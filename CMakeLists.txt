cmake_minimum_required(VERSION 3.0)
project(OpenGL_Praktikum)

set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
set(INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/src")

##-------------------------------add your source files here-------------------------------------------------------------
##        new source paths must be added to the include list, if contained headers are used elsewhere!
## Framework/Assets
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Assets/AssetManager.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Assets/AssetManager.cpp")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Assets/ShaderProgram.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Assets/ShaderProgram.cpp")
# add that directory to include list:
list(APPEND INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/Assets")

## Framework/SceneElements
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/SceneElements/Transform.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/SceneElements/Transform.cpp")
# add that directory to include list:
list(APPEND INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/src/Framework/SceneElements")
## Window
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/Window.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/Window.cpp")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/Scene.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/Scene.cpp")
# add that directory to include list:
list(APPEND INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/src/Game")

##---------------------------------framework files----------------------------------------------------------------------
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/CommonTypes.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/fw_config.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/OpenGLWindow.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/OpenGLWindow.cpp")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/glerror.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/glerror.cpp")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/Input.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/Input.cpp")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/libheaders.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/OBJLoader.h")
list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/framework/OBJLoader.cpp")
# add that directory to include list:
list(APPEND INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/framework")

##--------------------------------external dependencies-----------------------------------------------------------------
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/libs")

##--------------------------------executable target---------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 11)

add_executable(OpenGL_Praktikum ${SOURCES} "src/Game/Mesh/CompositeMesh.h" "src/Game/Mesh/CompositeMesh.cpp" "src/Game/Mesh/Point.h" "src/Game/Mesh/Point.cpp" "src/Game/Mesh/Color.h" "src/Game/Mesh/Color.cpp" "src/Game/Mesh/Mesh.h" "src/Game/Mesh/Mesh.cpp" "src/Game/Mesh/Cube.h" "src/Game/Mesh/Cube.cpp" "src/Game/SceneObjects/Robot.h" "src/Game/SceneObjects/Robot.cpp" "src/Game/Transform/SceneGraph.h" "src/Game/Transform/SceneGraph.cpp" "src/Game/Transform/SceneGraphNode.h" "src/Game/Transform/SceneGraphNode.cpp" "src/Game/SceneObjects/SceneObject.h" "src/Game/SceneObjects/SceneObject.cpp" "src/Game/Animation/Animator.h" "src/Game/Animation/AnimatorState.h" "src/Game/Animation/Animation.h" "src/Game/Animation/AnimatorState.cpp" "src/Game/Animation/Animation.cpp" "src/Game/Animation/Animator.cpp" "src/Game/Consts.h" "src/Game/Physics/World.h" "src/Game/Physics/World.cpp" "src/Game/Physics/Colliders/Collider.h" "src/Game/Physics/Colliders/Collider.cpp" "src/Game/Physics/RigidBodys/RigidBody.h" "src/Game/Physics/RigidBodys/RigidBody.cpp" "src/Game/Physics/Collision.h" "src/Game/Physics/Collision.cpp" "src/Game/SceneObjects/Plane.h" "src/Game/SceneObjects/Plane.cpp" "src/Game/AI/RobotAI.h" "src/Game/AI/RobotAI.cpp" "src/Game/Physics/CollisionEventListener.h")
target_include_directories(
        OpenGL_Praktikum
        PRIVATE ${INCLUDES}
)

target_link_libraries(OpenGL_Praktikum PUBLIC cga2fw_external_dependencies)

##-------------------------------copy assets to output------------------------------------------------------------------

file(COPY "assets" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")