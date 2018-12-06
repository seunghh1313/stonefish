//
//  PrismaticJoint.h
//  Stonefish
//
//  Created by Patryk Cieslak on 27/03/2014.
//  Copyright (c) 2014-2018 Patryk Cieslak. All rights reserved.
//

#ifndef __Stonefish_PrismaticJoint__
#define __Stonefish_PrismaticJoint__

#include "joints/Joint.h"

namespace sf
{
    class SolidEntity;
    
    //! A class representing a prismatic joint.
    class PrismaticJoint : public Joint
    {
    public:
        PrismaticJoint(std::string uniqueName, SolidEntity* solidA, SolidEntity* solidB, const Vector3& axis, bool collideLinkedEntities = true);
        void ApplyForce(Scalar F);
        void ApplyDamping();
        std::vector<Renderable> Render();
        void setDamping(Scalar constantFactor, Scalar viscousFactor);
        void setLimits(Scalar min, Scalar max);
        void setIC(Scalar displacement);
        JointType getType();
        
    private:
        Vector3 axisInA;
        Scalar sigDamping;
        Scalar velDamping;
        Scalar displacementIC;
    };
}

#endif
