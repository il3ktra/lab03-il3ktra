#include "transforms.h"
#include "glm/gtx/transform.hpp"
#include <math.h>
#include <iostream>

glm::mat4 Transforms::getScalingMatrix(float sx, float sy, float sz) {
    // Task 1: return the transformation matrix for 3D scaling
    return glm::mat3(
        sx, 0.0f, 0.0f,
        0.0f, sy, 0.0f,
        0.0f, 0.0f, sz);
    // Task 4: modify the function to return a 4x4 matrix
    return glm::mat4(
        sx, 0.0f, 0.0f, 0.0f,
        0.0f, sy, 0.0f, 0.0f,
        0.0f, 0.0f, sz, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

glm::mat4 Transforms::getRotationMatrixX(float angle) {
    // Task 2: return the matrix for rotation about the x-axis
    float rad = glm::radians(angle);
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    return glm::mat3(
        1.0f, 0.0f, 0.0f,
        0.0f, cosTheta, sinTheta,
        0.0f, -sinTheta, cosTheta);
    // Task 4: modify the function to return a 4x4 matrix
    return glm::mat4(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, cosTheta, sinTheta, 0.0f,
        0.0f, -sinTheta, cosTheta, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

glm::mat4 Transforms::getRotationMatrixY(float angle) {
    // Task 2: return the matrix for rotation about the y-axis
    float rad = glm::radians(angle);
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    return glm::mat3(
        cosTheta, 0.0f, -sinTheta,
        0.0f, 1.0f, 0.0f,
        sinTheta, 0.0f, cosTheta);
    // Task 4: modify the function to return a 4x4 matrix
    return glm::mat4(
        cosTheta, 0.0f, -sinTheta, 0.0f,
        0.0f,     1.0f, 0.0f,     0.0f,
        sinTheta, 0.0f, cosTheta,  0.0f,
        0.0f,     0.0f, 0.0f,     1.0f);
}

glm::mat4 Transforms::getRotationMatrixZ(float angle) {
    // Task 2: return the matrix for rotation about the z-axis
    float rad = glm::radians(angle);
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    return glm::mat3(
        cosTheta, sinTheta, 0.0f,
        -sinTheta, cosTheta, 0.0f,
        0.0f, 0.0f, 1.0f);
    // Task 4: modify the function to return a 4x4 matrix
    return glm::mat4(
        cosTheta,  sinTheta,  0.0f, 0.0f,
        -sinTheta, cosTheta,  0.0f, 0.0f,
        0.0f,      0.0f,     1.0f, 0.0f,
        0.0f,      0.0f,     0.0f, 1.0f);
}

glm::mat4 Transforms::getTranslationMatrix(float dx, float dy, float dz) {
    // Task 3: return the matrix for translation
    return glm::mat4(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        dx, dy, dz, 1.0f);
}


glm::mat4 Transforms::getMatrixA() {
    // Task 5: return matrix A using the previous functions
    glm::mat4 scale = getScalingMatrix(2.0f, 1.0f, -2.0f);
    glm::mat4 translate = getTranslationMatrix(0.0f, 0.0f, -1.0f);

    return translate * scale;
    //return glm::mat4(1.f); commenting this out because i don't think it helps
}

glm::mat4 Transforms::getMatrixB() {
    // Task 5: return matrix B using the previous functions
    return getRotationMatrixZ(45.0f);
    //return glm::mat4(1.f);
}

glm::mat4 Transforms::getMatrixC() {
    // Task 5: return matrix C using the previous functions
    glm::mat4 rotate = getRotationMatrixY(30.0f);
    glm::mat4 translate = getTranslationMatrix(4.0f, 0.0f, 4.0f);

    return translate * rotate;
    //return glm::mat4(1.f);
}

glm::mat4 Transforms::getMatrixD() {
    // Task 5: return matrix D using the previous functions
    glm::mat4 scale = getScalingMatrix(0.5f, 0.5f, 0.5f);
    glm::mat4 rotate = getRotationMatrixX(30.0f);
    glm::mat translate = getTranslationMatrix(3.0f, 6.0f, 1.0f);

    return translate * rotate * scale;
    //return glm::mat4(1.f);
}

// Task 7: Debug the following function
glm::mat4 Transforms::getInverseRotation(glm::mat4 rot) {
    // We know that the inverse of a rotation matrix is simply its transpose,
    //  so let's try to turn rows of the input matrix into columns of the inverse.
    glm::vec4 row0(rot[0][0], rot[1][0], rot[2][0], rot[3][0]);
    glm::vec4 row1(rot[0][1], rot[1][1], rot[2][1], rot[3][1]);
    glm::vec4 row2(rot[0][2], rot[1][2], rot[2][2], rot[3][2]);
    glm::vec4 row3(rot[0][3], rot[1][3], rot[2][3], rot[3][3]);

    return glm::mat4(row0, row1, row2, row3);
}

glm::mat4 Transforms::getViewMatrix(glm::vec3 pos, glm::vec3 look, glm::vec3 up) {
    // Task 8: return the camera view matrix
    glm::vec3 forward = glm::normalize(look - pos);

    glm::vec3 right = glm::normalize(glm::cross(forward, up));

    glm::vec3 cameraUp = glm::normalize(glm::cross(right, forward));

    glm::mat4 rotation(
        right.x, cameraUp.x, -forward.x, 0.0f,
        right.y, cameraUp.y, -forward.y, 0.0f,
        right.z, cameraUp.z, -forward.z, 0.0f,
        0.0f,    0.0f,      0.0f,      1.0f
        );

    glm::mat4 translation(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        -pos.x, -pos.y, -pos.z, 1.0f
        );

    return rotation * translation;
}

//Task 6:
//orange = D(you)
//yellow = C(B(you))
//blue = (C(A(you)))
//pink = bcbb or b-1cbb , sth w b & c, not sure abt d & a because they scale but could mean scale and then undo

//Task 9:
//Multiply cube_point_object and M to get cube_point_world in world space.
//Then multiply light_point_camera and inverse(V) to get light_point_world in world space.
//Then calculate the distance between cube_point_world and light_point_world.
