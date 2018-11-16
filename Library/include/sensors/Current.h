//
//  Current.h
//  Stonefish
//
//  Created by Patryk Cieslak on 09/06/2014.
//  Copyright (c) 2014 Patryk Cieslak. All rights reserved.
//

#ifndef __Stonefish_Current__
#define __Stonefish_Current__

#include "actuators/DCMotor.h"
#include "sensors/SimpleSensor.h"

class Current : public SimpleSensor
{
public:
    Current(std::string uniqueName, DCMotor* m, btScalar frequency = btScalar(-1.), int historyLength = -1);
    
    void InternalUpdate(btScalar dt);
    void Reset();
    
private:
    //params
    DCMotor* motor;
};


#endif