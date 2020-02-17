#include "Collision3D.h"

Collision3D::Collision3D(): collider(nullptr), collision_point(null_vector) {}

Collision3D::Collision3D(Object3D* collider_, Vector3D collision_point_): collider(collider_), collision_point(collision_point_){}