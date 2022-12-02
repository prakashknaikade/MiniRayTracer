#include <rt/groups/bvh.h>
#include <tuple>
#include <string.h>

namespace rt {

BVH::BVH()
{
    /* TODO */
    root = new BVHNode();
}

void BVH::rebuildIndex() {
    // /* TODO */ NOT_IMPLEMENTED;
    root->primitives = primitives;
    processNode(root);
    return;
}

float BVH::findSAHSplit(int axisIndex, BVHNode* node) {

    float primMid, prim2Mid; 
    float leftSA = 0, leftNum, cBest = FLT_MAX, cLeft, cRight, splitIndex;
    BBox nodeBBox = node->getBounds();
    for(std::vector<Primitive *>::size_type i = 0; i != node->primitives.size(); i++) {
        BBox primBBox = node->primitives[i]->getBounds();
        if (axisIndex == 0){
            primMid = (primBBox.min.x + primBBox.max.x)/2;
            leftSA = (primMid - nodeBBox.min.x) * (nodeBBox.max.y - nodeBBox.min.y) * (nodeBBox.max.z - nodeBBox.min.z);
            leftNum = 0;
            for(std::vector<Primitive *>::size_type j = 0; j != node->primitives.size(); j++) {
                BBox prim2BBox = node->primitives[j]->getBounds();
                prim2Mid = (prim2BBox.min.x + prim2BBox.max.x)/2;

                if (prim2Mid < primMid){
                    leftNum++;
                } 
            } 
        }
        else if (axisIndex == 1){
            primMid = (primBBox.min.y + primBBox.max.y)/2;
            leftSA = (nodeBBox.max.x - nodeBBox.min.x) * (primMid - nodeBBox.min.y) * (nodeBBox.max.z - nodeBBox.min.z);

            leftNum = 0;
            for(std::vector<Primitive *>::size_type j = 0; j != node->primitives.size(); j++) {
                BBox prim2BBox = node->primitives[j]->getBounds();
                prim2Mid = (prim2BBox.min.y + prim2BBox.max.y)/2;

                if (prim2Mid < primMid){
                    leftNum++;
                } 
            }
        }
        else{
            primMid = (primBBox.min.z + primBBox.max.z)/2;
            leftSA = (nodeBBox.max.x - nodeBBox.min.x) * (nodeBBox.max.y - nodeBBox.min.y) * (primMid - nodeBBox.min.z);

            leftNum = 0;
            for(std::vector<Primitive *>::size_type j = 0; j != node->primitives.size(); j++) {
                BBox prim2BBox = node->primitives[j]->getBounds();
                prim2Mid = (prim2BBox.min.z + prim2BBox.max.z)/2;

                if (prim2Mid < primMid){
                    leftNum++;
                } 
            }
        }

        cLeft = leftSA / node->area * leftNum;
        cRight = ((node->area - leftSA) / node->area) * (node->primitives.size() - leftNum);
        if ((cLeft + cRight) < cBest) {
            splitIndex = primMid; cBest = cLeft + cRight;
        }
    }
    return splitIndex;

}

float BVH::split(int axisIndex, BVHNode* node, int vec_size) {
    if (doSAHSplit){
        // SAH split
        return findSAHSplit(axisIndex, node);
    }
    else {
        // middle of axis split
        // Point cent = node->getBounds().centroid();
        // if (axisIndex == 0)
        //     return cent.x;
        // else if (axisIndex == 1)
        //     return cent.y;
        // else
        //     return cent.z;

        // // middle of primitives split
        std::vector<float> centers;
        for (int i=0; i<vec_size; i++) {
            BBox primBBox = node->primitives[i]->getBounds();
            Point centerBBox = Point((primBBox.min.x + primBBox.max.x)/2,
                                    (primBBox.min.y + primBBox.max.y)/2,
                                    (primBBox.min.z + primBBox.max.z)/2);
            if (axisIndex == 0)
                centers.push_back(centerBBox.x);
            else if (axisIndex == 1)
                centers.push_back(centerBBox.y);
            else
                centers.push_back(centerBBox.z);
        }
        if (vec_size <= 5){
            sort(centers.begin(), centers.end());
            centers.erase(unique(centers.begin(), centers.end()), centers.end());
        }
        auto biggest = std::max_element(std::begin(centers), std::end(centers));
        auto smallest = std::min_element(std::begin(centers), std::end(centers));
        return (*biggest + *smallest) / 2.0f; 
    }

}

void BVH::processNode(BVHNode* node) {
    Primitive* primitive;
    float splitLength;
    int axisIndex;
    float locationAxis;
    Point centerBBox;

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

            float length = std::max(std::max(lenx, leny), lenz);
            if (fabs(length - lenx) <= epsilon) 
                axisIndex = 0;
            else if (fabs(length - leny) <= epsilon)
                axisIndex = 1;
            else
                axisIndex = 2;
            // axisIndex = node->mBBox.largestAxis();
            splitLength = split(axisIndex, node, size);

            // std::vector<float> test; 
            for (int i=0; i<size; i++) {
                primitive = node->primitives[i];
                
                centerBBox = primitive->getBounds().centroid();
                if (axisIndex == 0)
                    locationAxis = centerBBox.x;
                else if (axisIndex == 1)
                    locationAxis = centerBBox.y;
                else
                    locationAxis = centerBBox.z;
                
                // test.push_back(locationAxis);
                if (locationAxis <= splitLength){
                    node->left->add(primitive);
                }
                else{
                    node->right->add(primitive);
                }
            }

            if (node->left->primitives.size() == 0) {
                node->left->add(node->right->primitives[0]);
                node->right->primitives.erase(node->right->primitives.begin()); 
            }

            else if (node->right->primitives.size() == 0) {
                node->right->add(node->left->primitives[0]);
                node->left->primitives.erase(node->left->primitives.begin());
            }

            processNode(node->left);
            processNode(node->right);
            return;
        }
    }
}


BBox BVH::getBounds() const {
    // /* TODO */ NOT_IMPLEMENTED;
    BBox bbox = BBox::empty();
    for(std::vector<Primitive *>::size_type i = 0; i != primitives.size(); i++) {
        bbox.extend(primitives[i]->getBounds());
    }
    return bbox;
}

Intersection BVH::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ //NOT_IMPLEMENTED;
    BVHNode* node = new BVHNode();
    Intersection nearestIntersection = Intersection::failure();
    Intersection currentIntersection;
    std::vector<BVHNode*> nodes;

    nodes.push_back(this->root);

    while (!nodes.empty()) {
        node = nodes.back();
        nodes.pop_back();

        if (node->isLeaf) {
            for(std::vector<Primitive *>::size_type i = 0; i != node->primitives.size(); i++){
                currentIntersection = node->primitives[i]->intersect(ray, tmin, tmax);
                if (currentIntersection) {
                    tmax = currentIntersection.distance;
                    nearestIntersection = currentIntersection;
                }
            }
        }
        else
        {
            BBox left = node->left->mBBox;
            auto tleft = left.intersect(ray);
            if(tleft.first < tleft.second && tleft.second > 0)
                nodes.push_back(node->left);

            BBox right = node->right->mBBox;
            auto tright = right.intersect(ray);
            if(tright.first < tright.second && tright.second > 0)
                nodes.push_back(node->right);
        }
    }
    return nearestIntersection;
}

void BVH::add(Primitive* p) {
    // /* TODO */ NOT_IMPLEMENTED;
    primitives.push_back(p);
    
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