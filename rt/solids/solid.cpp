#include <rt/solids/solid.h>

namespace rt {

Solid::Solid(CoordMapper* texMapper, Material* material)
{
    // CG_UNUSED(texMapper);
    // CG_UNUSED(material);

    /* TODO */
    //this->setCoordMapper(texMapper);
	//this->setMaterial(material);
    this->material = material;
    this->texMapper = texMapper;
}


}
