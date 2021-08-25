#pragma once

#include <cstdint>
#include <lvgl/lvgl.h>
#include "components/settings/Settings.h"
#include "displayapp/screens/Screen.h"

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class SettingNotification : public Screen {
      public:
        SettingNotification(DisplayApp* app, Pinetime::Controllers::Settings& settingsController);
        ~SettingNotification() override;

        bool Refresh() override;
        void UpdateSelected(lv_obj_t* object, lv_event_t event);

      private:
        Controllers::Settings& settingsController;
        const static int optionsTotal = 4;
        lv_obj_t* cbOption[optionsTotal];
        // When UpdateSelected is called, it uses lv_checkbox_set_checked,
        // which can cause extra events to be fired,
        // which might trigger UpdateSelected again, causing a loop.
        // This variable is used as a mutex to prevent that.
        bool ignoringEvents;
        const char* durations[optionsTotal] = { "5 Sec", "10 Sec", "15 Sec", "20 Sec"};

      };
    }
  }
}
