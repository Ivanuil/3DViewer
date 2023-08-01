#include "object_transformer.h"

bool epsilonComp(double a);

void moveObject(Object* object, double moveX, double moveY, double moveZ,
                int* error) {
  if (object == NULL) *error = NULL_POINTER;
  if (*error != SUCCESS) return;

  for (unsigned int i = 0; i < object->verticesNumber; i++) {
    object->vertices[i].x += moveX;
    object->vertices[i].y += moveY;
    object->vertices[i].z += moveZ;
  }
  object->minVertex.x += moveX;
  object->minVertex.y += moveY;
  object->minVertex.z += moveZ;
  object->maxVertex.x += moveX;
  object->maxVertex.y += moveY;
  object->maxVertex.z += moveZ;
}

void rotateObjectX(Object* object, double rotateX, int* error) {
  if (object == NULL) *error = NULL_POINTER;
  if (*error != SUCCESS) return;

  double sinV = sin(rotateX);
  double cosV = cos(rotateX);
  for (unsigned int i = 0; i < object->verticesNumber; i++) {
    double y = object->vertices[i].y;
    double z = object->vertices[i].z;

    object->vertices[i].y = y * cosV + z * sinV;
    object->vertices[i].z = (-y) * sinV + z * cosV;

    if (i == 0) {
      object->minVertex = object->vertices[i];
      object->maxVertex = object->vertices[i];
    }
    updateMaxMin(object, object->vertices[i]);
  }
}

void rotateObjectY(Object* object, double rotateY, int* error) {
  if (object == NULL) *error = NULL_POINTER;
  if (*error != SUCCESS) return;

  double sinV = sin(rotateY);
  double cosV = cos(rotateY);
  for (unsigned int i = 0; i < object->verticesNumber; i++) {
    double x = object->vertices[i].x;
    double z = object->vertices[i].z;

    object->vertices[i].x = x * cosV + z * sinV;
    object->vertices[i].z = (-x) * sinV + z * cosV;

    if (i == 0) {
      object->minVertex = object->vertices[i];
      object->maxVertex = object->vertices[i];
    }
    updateMaxMin(object, object->vertices[i]);
  }
}

void rotateObjectZ(Object* object, double rotateZ, int* error) {
  if (object == NULL) *error = NULL_POINTER;
  if (*error != SUCCESS) return;

  double sinV = sin(rotateZ);
  double cosV = cos(rotateZ);
  for (unsigned int i = 0; i < object->verticesNumber; i++) {
    double x = object->vertices[i].x;
    double y = object->vertices[i].y;

    object->vertices[i].x = x * cosV + y * sinV;
    object->vertices[i].y = (-x) * sinV + y * cosV;

    if (i == 0) {
      object->minVertex = object->vertices[i];
      object->maxVertex = object->vertices[i];
    }
    updateMaxMin(object, object->vertices[i]);
  }
}

void scaleObject(Object* object, double scaleX, double scaleY, double scaleZ,
                 int* error) {
  if (object == NULL) *error = NULL_POINTER;
  if (epsilonComp(scaleX) || epsilonComp(scaleY) || epsilonComp(scaleZ))
    *error = SCALE_BY_ZERO;
  else if (scaleX < 0 || scaleY < 0 || scaleZ < 0)
    *error = SCALE_BY_NEGATIVE;
  if (*error != SUCCESS) return;

  for (unsigned int i = 0; i < object->verticesNumber; i++) {
    object->vertices[i].x *= scaleX;
    object->vertices[i].y *= scaleY;
    object->vertices[i].z *= scaleZ;
  }
  object->minVertex.x *= scaleX;
  object->minVertex.y *= scaleY;
  object->minVertex.z *= scaleZ;
  object->maxVertex.x *= scaleX;
  object->maxVertex.y *= scaleY;
  object->maxVertex.z *= scaleZ;
}

/// UTILITY FUNCTIONS

/// @brief Compares absolute value to EPSILON
/// @param a Value
/// @return TRUE - if absolute value is smaller or equal to EPSILON,
///     FALSE - otherwise
bool epsilonComp(double a) {
  if (fabs(a) <= EPSILON) return true;
  return false;
}
