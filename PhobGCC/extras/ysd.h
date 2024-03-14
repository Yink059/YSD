#include "../common/structsAndEnums.h"
#include <math.h>
#ifndef EXTRAS_YSD_H
#define EXTRAS_YSD_H

namespace ysd
{

	ExtrasSlot extrasYsdConfigSlot = EXTRAS_LEFT;

	float defaultOffset = -54.0;

	enum YsdSettings
	{
		YSD_SETTING_ENABLE,
		YSD_SETTING_OFFSET,
		YSD_SETTING_COUNTER,
		YSD_SETTING_UNUSED3
	};

	enum YsdSettingEnable
	{
		YSD_DISABLED,
		YSD_ENABLED
	};

	bool check_enabled(const IntOrFloat config[])
	{
		if (config[YSD_SETTING_ENABLE].intValue != YSD_ENABLED)
		{
			return false;
		}
		return true;
	}

	
	float getOffset() {
		return getExtrasSettingFloat(extrasYsdConfigSlot, YSD_SETTING_OFFSET);
	}

void config(IntOrFloat config[], Cardinals dpad)
{
    if (dpad.u) {
        setExtrasSettingFloat(extrasYsdConfigSlot, YSD_SETTING_OFFSET, -53.0);
    }
    if (dpad.d) {
        setExtrasSettingFloat(extrasYsdConfigSlot, YSD_SETTING_OFFSET, -55.0);
    }
    if (dpad.l) {
        setExtrasSettingFloat(extrasYsdConfigSlot, YSD_SETTING_OFFSET, -54.0);
    }
    if (dpad.r) {
        setExtrasSettingFloat(extrasYsdConfigSlot, YSD_SETTING_OFFSET, 100.0);
    }
}


	bool toggle(IntOrFloat config[])
	{
		int &enabled = config[YSD_SETTING_ENABLE].intValue;
		if (enabled != YSD_DISABLED)
		{
			enabled = YSD_DISABLED;
		}
		else
		{
			enabled = YSD_ENABLED;
		}
		
		setExtrasSettingInt(extrasYsdConfigSlot, YSD_SETTING_ENABLE, enabled);
		return (enabled == YSD_ENABLED);
	}

};

#endif // EXTRAS_ESS_H
