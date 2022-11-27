#include <rt/groups/simplegroup.h>

namespace rt {

BBox SimpleGroup::getBounds() const {
    // /* TODO */ NOT_IMPLEMENTED;
    return mBBox;
}

Intersection SimpleGroup::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Intersection _intersection;
    bool status_found = false;

    for(std::vector<Primitive *>::size_type i = 0; i != this->primitives.size(); i++) {
      Intersection intersection = primitives[i]->intersect(ray, tmax); //intersect(ray, tmin, bestDistance)
      float distance = intersection.distance;

      if (intersection && (distance < tmax)&& (distance > tmin)){
          tmax = distance;
          _intersection = intersection;
          status_found = true;
      }
    }
    if (status_found)
        return _intersection;
    else
        return Intersection::failure();
}


void SimpleGroup::rebuildIndex() {
    //do nothing
}

void SimpleGroup::add(Primitive* p) {
    /* TODO */ //NOT_IMPLEMENTED;
    SimpleGroup::primitives.push_back(p);
    mBBox.extend(p->getBounds());
}

void SimpleGroup::setMaterial(Material* m) {
    // /* TODO */ NOT_IMPLEMENTED;
    for (std::vector<Primitive *>::size_type i = 0; i != this->primitives.size(); i++) {
        this->primitives[i]->setMaterial(m);
    }
}

void SimpleGroup::setCoordMapper(CoordMapper* cm) {
    //  /* TODO */ NOT_IMPLEMENTED;
    for (std::vector<Primitive *>::size_type i = 0; i != this->primitives.size(); i++) {
        this->primitives[i]->setCoordMapper(cm);
    }
}

}
