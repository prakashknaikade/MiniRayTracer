#include <rt/groups/simplegroup.h>

namespace rt {

BBox SimpleGroup::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection SimpleGroup::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ //NOT_IMPLEMENTED;
    // Intersection _intersection;
    // bool status_found = false;

    // for(std::vector<Primitive *>::size_type i = 0; i != this->primitives.size(); i++) {
    //   Intersection intersection = primitives[i]->intersect(ray, tmax);
    //   float distance = intersection.distance;

    //   if (intersection && (distance < tmax)){
    //       tmax = distance;
    //       _intersection = intersection;
    //       status_found = true;
    //   }
    // }
    // if (status_found)
    //     return _intersection;
    // else
    //     return Intersection::failure();
    Intersection isec;

	bool anyIntersection = false;
	for (std::vector<Primitive*>::const_iterator it = primitives.begin(); it != primitives.end(); ++it)
	{
		Primitive* p = *it;
		Intersection newIsec = p->intersect(ray, tmax);

		if (newIsec)
		{
			tmax = newIsec.distance;
			isec = newIsec;
			anyIntersection = true;
		}
	}

	if (anyIntersection) return isec;
	return Intersection::failure();
}


void SimpleGroup::rebuildIndex() {
    //do nothing
}

void SimpleGroup::add(Primitive* p) {
    /* TODO */ //NOT_IMPLEMENTED;
    SimpleGroup::primitives.push_back(p);
}

void SimpleGroup::setMaterial(Material* m) {
    // /* TODO */ NOT_IMPLEMENTED;
    this->setMaterial(m);
}

void SimpleGroup::setCoordMapper(CoordMapper* cm) {
    // /* TODO */ NOT_IMPLEMENTED;
    this->setCoordMapper(cm);
}

}
