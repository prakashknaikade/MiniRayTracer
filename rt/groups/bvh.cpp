#include <rt/groups/bvh.h>

namespace rt {

BVH::BVH()
{
    /* TODO */
    fullbbox = BBox::empty();
    root = new BVHNode();
}

void BVH::processNode(BVHNode* node) {
    Primitive* primitive;
    float splitLength;
    int axisIndex;
    float locationAxis;

    int size = node->primitives.size();

    if (size <= 0)
    return;

    else {
    if (size < 3) {
        node->isLeaf = true;
        return;
    }

    if (size >= 3) {
        node->isLeaf = false;
        node->left = new BVHNode();
        node->right = new BVHNode();

        float lenx = node->mBBox.max.x - node->mBBox.min.x;
        float leny = node->mBBox.max.y - node->mBBox.min.y;
        float lenz = node->mBBox.max.z - node->mBBox.min.z;

        float length = max(max(lenx, leny), lenz);
        axisIndex = (fabs(length - lenx) <= epsilon) ? 0 : 2;
        axisIndex = (fabs(length - leny) <= epsilon) ? 1 : axisIndex;

        splitLength = split(axisIndex, node);

        for (int i=0; i<size; i++) {
            primitive = node->primitives[i];

            BBox currentPrimitive = primitive->getBounds();
            Point centerBBox = Point((currentPrimitive.min.x + currentPrimitive.max.x)/2,
                                        (currentPrimitive.min.y + currentPrimitive.max.y)/2,
                                        (currentPrimitive.min.z + currentPrimitive.max.z)/2);
            if (axisIndex == 0)
                locationAxis = centerBBox.x;
            else if (axisIndex == 1)
                locationAxis = centerBBox.y;
            else
                locationAxis = centerBBox.z;
            
            if (locationAxis <= splitLength)
                node->left->add(primitive);
            else
                node->right->add(primitive);
        }

        if (node->left->primitives.size() == 0) {
            node->left->add(node->right->primitives[0]);
            // need to update area as well
            node->right->primitives.erase(node->right->primitives.begin());
        }

        else if (node->right->primitives.size() == 0) {
            node->right->add(node->left->primitives[0]);
            // need to update area as well
            node->left->primitives.erase(node->left->primitives.begin());
        }

        processNode(node->left);
        processNode(node->right);
        return;
    }
    }
}

float BVH::split(int axisIndex, BVHNode* node) {
    // find the middle of the longest axis with axisIndex

    BBox nodeBBox = node->getBounds();
    Point centerBBox = Point((nodeBBox.min.x + nodeBBox.max.x)/2,
                             (nodeBBox.min.y + nodeBBox.max.y)/2,
                             (nodeBBox.min.z + nodeBBox.max.z)/2);
    if (axisIndex == 0)
        return centerBBox.x;
    else if (axisIndex == 1)
        return centerBBox.y;
    else
        return centerBBox.z;
}

void BVH::rebuildIndex() {
    // /* TODO */ NOT_IMPLEMENTED;
    root->primitives = primitives;
    processNode(root);
    return;
}

BBox BVH::getBounds() const {
    // /* TODO */ NOT_IMPLEMENTED;
    return fullbbox;
}

Intersection BVH::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ NOT_IMPLEMENTED;
}

void BVH::add(Primitive* p) {
    // /* TODO */ NOT_IMPLEMENTED;
    primitives.push_back(p);
    fullbbox.extend(p->getBounds());
    
}

void BVH::setMaterial(Material* m) {
    // /* TODO */ NOT_IMPLEMENTED;
    for (std::vector<Primitive *>::size_type i = 0; i != this->primitives.size(); i++) {
        this->primitives[i]->setMaterial(m);
    }
}

void BVH::setCoordMapper(CoordMapper* cm) {
    // /* TODO */ NOT_IMPLEMENTED;
}

void BVH::serialize(BVH::Output& output) {
    // To implement this function:
    // - Call output.setNodeCount() with the number of nodes in the BVH
    /* TODO */
    // - Set the root node index using output.setRootId()
    /* TODO */
    // - Write each and every one of the BVH nodes to the output using output.writeNode()
    /* TODO */ NOT_IMPLEMENTED;
}
void BVH::deserialize(BVH::Input& input) {
    // To implement this function:
    // - Allocate and initialize input.getNodeCount() nodes
    /* TODO */
    // - Fill your nodes with input.readNode(index)
    /* TODO */
    // - Use the node at index input.getRootId() as the root node
    /* TODO */ NOT_IMPLEMENTED;
}

}