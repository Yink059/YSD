#include "../common/structsAndEnums.h"
#include <math.h>
#ifndef EXTRAS_YSD_H
#define EXTRAS_YSD_H

namespace ysd {


	ExtrasSlot extrasYsdConfigSlot = EXTRAS_LEFT;
	float offset = -54.0;
	enum YsdSettings{
		YSD_SETTING_ENABLE,
		YSD_SETTING_UNUSED1,
		YSD_SETTING_UNUSED2,
		YSD_SETTING_UNUSED3
	};

	enum YsdSettingEnable{
		YSD_DISABLED,
		YSD_ENABLED
	};


	bool check_enabled(const IntOrFloat config[]) {
		if (config[YSD_SETTING_ENABLE].intValue != YSD_ENABLED) {
			return false; //do nothing, keep hyst enabled
		}
		return true;
	}

	bool toggle(IntOrFloat config[]) {
		int& enabled = config[YSD_SETTING_ENABLE].intValue;
		if (enabled != YSD_DISABLED){
			enabled = YSD_DISABLED;
		} else {
			enabled = YSD_ENABLED;
		}
		setExtrasSettingInt(extrasYsdConfigSlot, YSD_SETTING_ENABLE, enabled);
		return (enabled == YSD_ENABLED);
	}

};

#endif //EXTRAS_ESS_H
