#include "../common/structsAndEnums.h"
#include <math.h>
#include "../teensy/readHardware.h"
#ifndef EXTRAS_YSD_H
#define EXTRAS_YSD_H

namespace ysd {


	ExtrasSlot extrasEssConfigSlot = EXTRAS_UNSET;

	enum YsdSettings{
		ESS_SETTING_ENABLE,
		ESS_SETTING_UNUSED1,
		ESS_SETTING_UNUSED2,
		ESS_SETTING_UNUSED3
	};

	enum YsdSettingEnable{
		ESS_DISABLED,
		ESS_ENABLED
	};

// 	void shielddrops(){
//   shield = gcc.l||gcc.r||gcc.left>74||gcc.right>74||gcc.z;
//         if(shield){
//             if(ay<0&&r>72){
//             if(arc(swang)<4.0){gcc.yAxis = 73; gcc.xAxis =  73;}
//             if(arc(seang)<4.0){gcc.yAxis = 73; gcc.xAxis = 183;}
//             }
//         }
//         }


void shieldDrop(Pins &pin, const float xIn, const float yIn, float* xOut, float* yOut, Buttons &btns, ControlConfig &controls){


	readButtons(pin, btns);
	btns.La = (uint8_t) readLa(pin, controls.lTrigInitial, 1);
	btns.Ra = (uint8_t) readRa(pin, controls.rTrigInitial, 1);
	btns.L;
	btns.R;
    //get shielding state
	bool shield_state = false;
	if (btns.La || btns.Ra || btns.L || btns.R) {
		shield_state = true;
	};
	float x = xIn;
	float y = yIn;
	float magnitude = sqrt((x * x) + (y * y));
	float angle = atan(y / x);

	if (magnitude > 72.0) && (shield_state) {
		if yIn < 0.0 {
			xOut = 73;
			yOut = 73;
		};
	};

    //get stick y position and magnitude
	//if below center and magnitude greater than 72 then
	// float arc(float val){return abs(180-abs(abs(deg-val)-180));}                 //returns length of arc between deg and val
	// get arc of polar degree of analog stick to the swang and seang
	// if less than 4.0 then set the axes to shield drop values


	// //determine the angle between the x unit vector and the current position vector
	// float angle = atan2f(yIn,xIn);

	// //unwrap the angle based on the first region boundary
	// if(angle < stickParams.boundaryAngles[0]){
	// 	angle += M_PI*2;
	// }

	// //go through the region boundaries from lowest angle to highest, checking if the current position vector is in that region
	// //if the region is not found then it must be between the first and the last boundary, ie the last region
	// //we check GATE_REGIONS*2 because each notch has its own very small region we use to make notch values more consistent
	// //int region = regions*2-1;
	// int region = regions-1;
	// for(int i = 1; i < regions; i++){
	// 	if(angle < stickParams.boundaryAngles[i]){
	// 		region = i-1;
	// 		break;
	// 	}
	// }

	// //Apply the affine transformation using the coefficients found during calibration
	// *xOut = stickParams.affineCoeffs[region][0]*xIn + stickParams.affineCoeffs[region][1]*yIn;
	// *yOut = stickParams.affineCoeffs[region][2]*xIn + stickParams.affineCoeffs[region][3]*yIn;

	// float stickScale;
	// if(whichStick == ASTICK) {
	// 	stickScale = controls.astickAnalogScaler/100.0f;
	// } else {
	// 	stickScale = controls.cstickAnalogScaler/100.0f;
	// }

	// *xOut *= stickScale;
	// *yOut *= stickScale;

	// if(currentCalStep == -1) {

	// 	if(whichStick == ASTICK) {
	// 		if(controls.astickCardinalSnapping > 0) {
	// 			if((abs(*xOut)<controls.astickCardinalSnapping+0.5) && (abs(*yOut)>=79.5)){
	// 				*xOut = 0;
	// 			}
	// 			if((abs(*yOut)<controls.astickCardinalSnapping+0.5) && (abs(*xOut)>=79.5)){
	// 				*yOut = 0;
	// 			}
	// 		} else if(controls.astickCardinalSnapping == -1) {
	// 			if((abs(*xOut)<6.5) && (abs(*yOut)>=79.5)){
	// 				*xOut = 7;
	// 			}
	// 			if((abs(*yOut)<6.5) && (abs(*xOut)>=79.5)){
	// 				*yOut = 7;
	// 			}
	// 		}
	// 	} else {
	// 		if(controls.cstickCardinalSnapping > 0) {
	// 			if((abs(*xOut)<controls.cstickCardinalSnapping+0.5) && (abs(*yOut)>=79.5)){
	// 				*xOut = 0;
	// 			}
	// 			if((abs(*yOut)<controls.cstickCardinalSnapping+0.5) && (abs(*xOut)>=79.5)){
	// 				*yOut = 0;
	// 			}
	// 		} else if(controls.cstickCardinalSnapping == -1) {
	// 			if((abs(*xOut)<6.5) && (abs(*yOut)>=79.5)){
	// 				*xOut = 7;
	// 			}
	// 			if((abs(*yOut)<6.5) && (abs(*xOut)>=79.5)){
	// 				*yOut = 7;
	// 			}
	// 		}
	// 	}

	// 	if((abs(*xOut)<3) && (abs(*yOut)<3)) {
	// 		*xOut = 0;
	// 		*yOut = 0;
	// 	}
	// }
};
	
}

#endif //EXTRAS_ESS_H
