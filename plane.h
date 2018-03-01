#ifndef PLANEH
#define PLANEH

#include "hitable.h"

class plane : public hitable {
  public:
    plane() {}
    plane(vec3 norm, float d) : normal(norm), distance(d) {};
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

    // Normal must be a unit vector
    vec3 normal;
    float distance;
};

bool plane::hit(const ray &r, float t_min, float t_max, hit_record&rec) const {
   float temp;
   if (dot(r.origin(), normal) + dot(r.direction(), normal) - distance < 0.0001) {
     return true;
   }
   float denom = dot(normal, r.direction());
   if (denom == 0) {
     return false;
   }
   temp = (distance - dot(normal, r.origin()))  / denom;
   if (t_min < temp && temp < t_max) {
     rec.t = temp;
     rec.p = r.point_at_parameter(temp);
     rec.normal = normal;
     return true;
   }
   return false;
}


#endif
