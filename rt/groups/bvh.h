#ifndef CG1RAYTRACER_GROUPS_BVH_HEADER
#define CG1RAYTRACER_GROUPS_BVH_HEADER

#include <rt/groups/group.h>
#include <rt/bbox.h>

namespace rt {

class BVHNode {
public:
	BVHNode() {this->mBBox = BBox::empty(); area = 0;}

	BBox mBBox;
	BVHNode* left = nullptr;
	BVHNode* right = nullptr;
	bool isLeaf;
	float area;

	std::vector<Primitive*> primitives;

	virtual void add(Primitive* p) {
        this->primitives.push_back(p);
        mBBox.extend(p->getBounds());
        area = mBBox.area();
	};

	virtual BBox getBounds() const {
		return mBBox;
	};

	virtual float getArea() const {
		return area;
	};
};


class BVH : public Group {
public:
    BVH();

    virtual BBox getBounds() const;
    virtual Intersection intersect(const Ray& ray, float tmin = 0, float tmax = FLT_MAX) const;
    virtual void rebuildIndex();
    virtual void add(Primitive* p);
    virtual void setMaterial(Material* m);
    virtual void setCoordMapper(CoordMapper* cm);

    BVHNode* root;
    virtual void processNode(BVHNode* node);
    virtual float split(int axisIndex, BVHNode* node, int vec_size); 
    virtual float findSAHSplit(int axisIndex, BVHNode* node);
    bool doSAHSplit = false;

    // Do not use this structure as your node layout:
    // It is inefficient and has a large memory footprint.
    struct SerializedNode {
        bool isLeaf;
        BBox bbox;

        // For leaves only
        std::vector<Primitive*> primitives;

        // For internal nodes only
        size_t leftChildId;
        size_t rightChildId;
    };

    // Implement this function if you want to take part in the BVH speed competition
    struct Output {
        virtual void setNodeCount(size_t nodeCount) = 0;
        virtual void setRootId(size_t rootId) = 0;
        virtual void writeNode(size_t nodeId, const SerializedNode& node) = 0;
    };
    void serialize(Output& output);

    // Implementing this is optional and not needed for the BVH speed competition,
    // but it will allow you to run the benchmark utility and test your BVH exporter.
    struct Input {
        virtual size_t getNodeCount() = 0;
        virtual size_t getRootId() = 0;
        virtual const SerializedNode& readNode(size_t nodeId) = 0;
    };
    void deserialize(Input& input);

};

}

#endif